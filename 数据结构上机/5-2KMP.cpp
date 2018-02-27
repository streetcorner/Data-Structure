#include<stdio.h>
#include<stdlib.h>
#include<cstring>

#define MAXSTRLEN 255
typedef unsigned char SString[MAXSTRLEN+1];//0ºÅµ¥Ôª´æ´®³¤

int Index_KMP(SString S, SString T, int pos) {
	int i,j;
	i=pos; j=1;
	while(i<=S[0] && j<=T[0]) {
		if (j==0 || S[i]==T[j]) {++i; ++j}
		else j=next[j];
	}
	if (j>T[0]) return i-T[0];//return the matching position
	else return 0;
}//Index_KMP

void get_next(SString T, int next[]){
    int i,j;
    i=1,j=0;
    next[1]=0;
    while(i<T[0]){
        if(j==0 || T[i]==T[j]){
            ++i;++j;
            next[i]=j;
        }
        else j=next[j];
    }
}
