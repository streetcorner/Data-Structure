#include <stdio.h>
#include <stdlib.h>

#define ListSize 100      //最大允许长度
typedef int ListData;
	typedef struct {
      ListData * data;      //存储空间基址
	   int length; 	      //当前元素个数
} SeqList;

void InitList ( SeqList & L ) {
     L.data = ( ListData * ) malloc
           ( ListSize * sizeof ( ListData ) );
     if ( L.data == NULL ) {
         printf ( "存储分配失败!\n" );
         exit (1);
     }
     L.length = 0;
 }
//找x在表中的位置，若查找成功，返回表项的位置，否则返回-1
 int Find ( SeqList &L, ListData x ) {
        int i = 0;
        while ( i < L.length && L.data[i] != x )
             i++;
        if ( i < L.length ) return i;
        else return -1;
    }

 int Find_by_order(SeqList &L, int i ){
	 if(i<L.length){
		return L.data[i-1];}
	 else
		 return -1;
 }

//判断x是否在表中
int IsIn ( SeqList &L, ListData x )
 {	int i = 0,	found=0;
	while ( i < L.length &&!found )
		if(L.data[i] != x ) i++;
		else found=1;
        return found;
}

//求表的长度
int Length ( SeqList & L ) {
    return L.length;
}
//提取函数：在表中提取第 i 个元素的值
ListData GetData ( SeqList &L, int i ) {
    if ( i >= 0 && i < L.length )
        return L.data[i];
    else printf ( "参数 i 不合理！\n");
}
//寻找x的后继
int Next ( SeqList &L, ListData x ) {
    int i = Find(L,x);
    if ( i >=0 && i < L.length-1) return i+1;
    else return -1;
}
//寻找x的前驱
int Previous ( SeqList &L, ListData x ) {
    int i = Find(L,x);
    if ( i >0 && i < L.length ) return i-1;
    else return -1;
}

//顺序表的插入
int Insert ( SeqList &L, ListData x, int i ) {
//在表中第 i 个位置插入新元素 x
    if (i < 0 || i > L.length || L.length == ListSize)
    return 0;            //插入不成功
    else {
         for ( int j = L.length; j > i; j-- )
                 L.data[j] = L.data[j -1];
             L.data[i] = x;
			 L.length++;
			 return 1;     //插入成功
       }
}

//顺序表的删除
int Delete ( SeqList &L, ListData x ) {
    //在表中删除已有元素 x
    int i = Find (L, x);	       //在表中查找 x
    if ( i >= 0 ) {
        L.length -- ;
         for ( int j = i; j < L.length; j++ )
                   L.data[j] = L.data[j+1];
         return 1;	               //成功删除
     }
    return 0;                     //表中没有 x
}

void Union ( SeqList &A, SeqList &B ) {
     int n = A.length;
     int m = B.length;
     for ( int i = 0; i < m; i++ ) {
	 int x = GetData ( B, i );  //在B中取一元素
	 int k = Find (A, x);       //在A中查找它
	 if ( k == -1 )                //若未找到插入它
             { Insert ( A, x, n );  n++; }
     }
}

 void Intersection ( SeqList &A, SeqList &B ) {
     int n = Length ( A );
     int m = Length ( B );
     int i = 0;
     while ( i < n ) {
         int x = GetData ( A, i );  //在A中取一元素
 	int k = Find ( B, x );    //在B中查找它
	if ( k == -1 ) { Delete ( A, i );  n--; }
	else i++;                //未找到在A中删除它
    }
 }

void selectSort ( int a[ ], int n ) {
 //对n个整数a[0],a[1],…,a[n-1]按递增顺序排序
       for ( int i = 0; i < n-1; i++ ) {
            int k = i;
            //从a[i]查到a[n-1], 找最小整数, 在a[k]
            for ( int j = i+1; j < n; j++ )
 	     if ( a[j] < a[k] ) k = j;
	 int temp = a[i];  a[i] = a[k];   a[k] = temp;
      }
 }

int seqsearch ( int a[ ], int n, int x ) {
//在a[0],…,a[n-1]中搜索x
    int i = 0;
    while ( i < n && a[i] != x )
          i++;
    if ( i == n ) return -1;
    return i;
}

void display(SeqList &L,int len){
	for(int i=0; i<len;i++)
		printf("%d ",L.data[i]);
	printf("\n");
}

int main(){
	SeqList L;
	ListData x;
	int i;
	InitList(L);
//add
	int len=0;
	printf("Please define the length of your list:\n");
	scanf("%d",&len);
//insert
	printf("Please insert your list:\n");
	for(int i = 0; i <len;i++){
		scanf("%d",&x);
		Insert(L,x,i);
	}
//display
	printf("L is as follows:\n");
	display(L,L.length);
//delete
	printf("Please print the element you want to delete:\n");
	scanf("%d",&x);
	Delete(L,x);
	printf("L is as follows:\n");
	display(L,L.length);
//find by value
	printf("Please input the element you want to find:\n");
	scanf("%d",&x);
	if(Find(L,x)<0)
		printf("It doesn't exist\n");
	else
		printf("The element is the %dth number.\n",Find(L,x)+1);
//find by order
	printf("Please input the order of the element you want to find:\n");
	scanf("%d",&i);
	if(Find_by_order(L,i)<0)
		printf("It doesn't exist\n");
	else
		printf("The %dth element is %d.\n",i,Find_by_order(L,i));
	return 0;
}
