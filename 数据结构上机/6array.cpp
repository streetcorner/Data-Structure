#include<stdio.h>
#include<stdlib.h>
#include<cstring>

//sparse matrix
#define MAXSIZE 12500
typedef struct{
	int i,j;	 //����Ԫ���к�/�к�
	int e;       //����Ԫ�ص�ֵ
}Triple; //��Ԫ��

typedef union{
	Triple data[MAXSIZE+1];
	int mu,nu,tu; //��������������������Ԫ����
}TSMatrix;//ϡ������ඨ��

//ϡ������ת��
int TransposeSMatrix(TSMatrix M, TSMatrix &T){
	T.mu=M.nu; T.nu=M.mu; T.tu=M.tu;
	//ת�þ��������,�����ͷ���Ԫ�ظ���
	if (T.tu){
		int q=1; //����T��ָ��
		for(int col=1;col<=M.nu;++col)
			for(int p=1;p<=M.tu;++p)//����M��ָ��
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
		for(col=1;col<=M.nu;++col) num[col]=0;//��ʼ��num
		for(t=1;t<=M.tu;++t) ++num[M.data[t].j];//��M��ÿ�з���Ԫ����
		cpot[1]=1;
		for(col=2;col<=M.nu;++col) cpot[col]=cpot[col-1]+num[col-1];
	//���col���е�һ������Ԫ��T�е����
		for(p=1;p<=M.tu;++p){
			col=M.data[p].j; q=cpot[col];
			T.data[q].i=M.data[p].j;
			T.data[q].j=M.data[p].i;
			T.data[q].e=M.data[p].e; ++cpot[col];//������һԪ��λ��
		}//for
	}//if
	return 1;
}//FastTransposeSMatrix


main ( ) {
    int a1[3] = { 3, 5, 7 };
    int *elem;
    for ( int i = 0; i < 3; i++ )
        printf ( "%d\n", a1[i]);    //��̬����
    elem = a1;
    for ( int i = 0; i < 3; i++ ) {
        printf ( "%d\n", *elem);  //��̬����
        elem++;
    }
}
