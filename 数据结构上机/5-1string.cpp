#include<stdio.h>
#include<stdlib.h>
#include<cstring>

//heap string
typedef struct {
	char *ch;
	int length;
}HString;

int StrInsert(HString &S, int pos, HString T){
//在串S的第pos个字符之前插入串T
	if (pos<1||pos>S.length+1) return 0;
	if(T.length){
		if(!(S.ch=(char *)realloc(S.ch,(S.length+T.length)*sizeof(char))))
			exit(1);
		for (int i=S.length-1;i>=pos-1;i--)//move (s.length-pos) elements backwards
			S.ch[i+T.length]=S.ch[i];
        for(int j =0,k=pos-1; j<T.length; j++,k++){
            S.ch[k] = T.ch[j];
        }
		S.length+=T.length;
	}
	return 1;
}//StrInsert

int StrAssign(HString &T,char *chars){
//生成值为chars的串T

    int i=0;
    char c;

	while(1){
	    if(chars[i])
            i++;
        else break;
    }//求chars长度
//    if(T.ch) free(T.ch);
	if(!i) {T.ch=NULL; T.length=0;}//chars is empty
	else  {
		if(!(T.ch=(char *)malloc(i*sizeof(char))))
			exit (1);
        for(int j=0; j <i; j++)
            T.ch[j]=chars[j];
		T.length=i;
	}
	return 1;
}//StrAssign

int StrLength(HString S) {
//求串长度
	return S.length;
}//StrLength

int StrCompare(HString S, HString T){
//比较串S和T
	for (int i=0;i<S.length && i<T.length;++i)
		if(S.ch[i]!=T.ch[i]) return S.ch[i]-T.ch[i];//return not 0, implying fail
	return S.length-T.length; //if they have equal length, then they are equal,return 0
}//StrCompare

int ClearString(HString &S){
//清空串S
	if(S.ch) {free(S.ch); S.ch=NULL;}
	S.length=0;
	return 1;
}//ClearString

int Concat(HString &T,HString S1,HString S2) {
//连接串S1和S2
	if(T.ch) free(T.ch);
	if(!(T.ch=(char *)malloc((S1.length+S2.length)*sizeof(char))))
		exit(1);
    for(int i=0; i<S1.length; i++){
        T.ch[i]=S1.ch[i];
    }
	T.length=S1.length+S2.length;
	for(int j=0; j<S2.length; j++)
	T.ch[S1.length+j]=S2.ch[j];
	return 1;
}//Concat

int SubString(HString &Sub,HString S,int pos,int len){
//返回串S中从pos位置起长度为len的子串
	if (pos<1||pos>S.length||len<0||len>S.length-pos+1)
		return 0;
	if(Sub.ch) free(Sub.ch);
	if(!len){Sub.ch=NULL; Sub.length=0;}//长度为0
	else{
		Sub.ch=(char *)malloc(len*sizeof(char));
		for(int i=0; i<len; i++)
            Sub.ch[i]=S.ch[pos-1+i];
		Sub.length=len;
	}
	return 1;
}//SubString

void display(HString &s){
    int i = s.length;
    if(!i) printf("The string is null.\n");
    else{
        //printf("The string is:%p\n",s.ch);
        for(int j=0;j<i;j++){
            printf("%c",s.ch[j]);
        }
        printf("\n");
    }
}


int main(){
    char strs[100];
    HString s,t;

    printf("enter string s:\n");
    scanf("%s",strs);
    StrAssign(s,strs);
    strs[0]='\0';

    printf("String s,");
    display(s);


    printf("enter string t:\n");
    scanf("%s",strs);
    //printf("%s",strs);

    StrAssign(t,strs);

    printf("String t,");
    display(t);

    StrInsert(s,2,t);
    printf("After insertion, the string is:");
    display(s);


    return 0;
}

