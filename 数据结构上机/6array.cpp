#include<stdio.h>
#include<stdlib.h>
#include<cstring>

//sparse matrix
#define MAXSIZE 12500
typedef struct{
	int i,j;	 //非零元素行号/列号
	int e;       //非零元素的值
}Triple; //三元组

typedef union{
	Triple data[MAXSIZE+1];
	int mu,nu,tu; //矩阵行数、列数、非零元个数
}TSMatrix;//稀疏矩阵类定义

//稀疏矩阵的转置
int TransposeSMatrix(TSMatrix M, TSMatrix &T){
	T.mu=M.nu; T.nu=M.mu; T.tu=M.tu;
	//转置矩阵的列数,行数和非零元素个数
	if (T.tu){
		int q=1; //矩阵T的指针
		for(int col=1;col<=M.nu;++col)
			for(int p=1;p<=M.tu;++p)//矩阵M的指针
				if(M.data[p].j==col){
					T.data[q].i=M.data[p].j;
					T.data[q].j=M.data[p].i;
					T.data[q].e=M.data[p].e;
					++q;
				}
	}
	return 1;
}//TransposeSMatrix

//fast transpose
int FastTransposeSMatrix(TSMatrix M, TSMatrix &T){
	T.mu=M.nu; T.nu=M.mu; T.tu=M.tu;
	int col,cpot[MAXSIZE],num[MAXSIZE],t;
	int p,q;
	if(T.tu){
		for(col=1;col<=M.nu;++col) num[col]=0;//初始化num
		for(t=1;t<=M.tu;++t) ++num[M.data[t].j];//求M中每列非零元个数
		cpot[1]=1;
		for(col=2;col<=M.nu;++col) cpot[col]=cpot[col-1]+num[col-1];
	//求第col列中第一个非零元在T中的序号
		for(p=1;p<=M.tu;++p){
			col=M.data[p].j; q=cpot[col];
			T.data[q].i=M.data[p].j;
			T.data[q].j=M.data[p].i;
			T.data[q].e=M.data[p].e; ++cpot[col];//该列下一元素位置
		}//for
	}//if
	return 1;
}//FastTransposeSMatrix


main ( ) {
    int a1[3] = { 3, 5, 7 };
    int *elem;
    for ( int i = 0; i < 3; i++ )
        printf ( "%d\n", a1[i]);    //静态数组
    elem = a1;
    for ( int i = 0; i < 3; i++ ) {
        printf ( "%d\n", *elem);  //动态数组
        elem++;
    }
}
