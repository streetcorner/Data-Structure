#include <stdio.h>
#include <stdlib.h>

#define ListSize 100      //���������
typedef int ListData;
	typedef struct {
      ListData * data;      //�洢�ռ��ַ
	   int length; 	      //��ǰԪ�ظ���
} SeqList;

void InitList ( SeqList & L ) {
     L.data = ( ListData * ) malloc
           ( ListSize * sizeof ( ListData ) );
     if ( L.data == NULL ) {
         printf ( "�洢����ʧ��!\n" );
         exit (1);
     }
     L.length = 0;
 }
//��x�ڱ��е�λ�ã������ҳɹ������ر����λ�ã����򷵻�-1
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

//�ж�x�Ƿ��ڱ���
int IsIn ( SeqList &L, ListData x )
 {	int i = 0,	found=0;
	while ( i < L.length &&!found )
		if(L.data[i] != x ) i++;
		else found=1;
        return found;
}

//���ĳ���
int Length ( SeqList & L ) {
    return L.length;
}
//��ȡ�������ڱ�����ȡ�� i ��Ԫ�ص�ֵ
ListData GetData ( SeqList &L, int i ) {
    if ( i >= 0 && i < L.length )
        return L.data[i];
    else printf ( "���� i ������\n");
}
//Ѱ��x�ĺ��
int Next ( SeqList &L, ListData x ) {
    int i = Find(L,x);
    if ( i >=0 && i < L.length-1) return i+1;
    else return -1;
}
//Ѱ��x��ǰ��
int Previous ( SeqList &L, ListData x ) {
    int i = Find(L,x);
    if ( i >0 && i < L.length ) return i-1;
    else return -1;
}

//˳���Ĳ���
int Insert ( SeqList &L, ListData x, int i ) {
//�ڱ��е� i ��λ�ò�����Ԫ�� x
    if (i < 0 || i > L.length || L.length == ListSize)
    return 0;            //���벻�ɹ�
    else {
         for ( int j = L.length; j > i; j-- )
                 L.data[j] = L.data[j -1];
             L.data[i] = x;
			 L.length++;
			 return 1;     //����ɹ�
       }
}

//˳����ɾ��
int Delete ( SeqList &L, ListData x ) {
    //�ڱ���ɾ������Ԫ�� x
    int i = Find (L, x);	       //�ڱ��в��� x
    if ( i >= 0 ) {
        L.length -- ;
         for ( int j = i; j < L.length; j++ )
                   L.data[j] = L.data[j+1];
         return 1;	               //�ɹ�ɾ��
     }
    return 0;                     //����û�� x
}

void Union ( SeqList &A, SeqList &B ) {
     int n = A.length;
     int m = B.length;
     for ( int i = 0; i < m; i++ ) {
	 int x = GetData ( B, i );  //��B��ȡһԪ��
	 int k = Find (A, x);       //��A�в�����
	 if ( k == -1 )                //��δ�ҵ�������
             { Insert ( A, x, n );  n++; }
     }
}

 void Intersection ( SeqList &A, SeqList &B ) {
     int n = Length ( A );
     int m = Length ( B );
     int i = 0;
     while ( i < n ) {
         int x = GetData ( A, i );  //��A��ȡһԪ��
 	int k = Find ( B, x );    //��B�в�����
	if ( k == -1 ) { Delete ( A, i );  n--; }
	else i++;                //δ�ҵ���A��ɾ����
    }
 }

void selectSort ( int a[ ], int n ) {
 //��n������a[0],a[1],��,a[n-1]������˳������
       for ( int i = 0; i < n-1; i++ ) {
            int k = i;
            //��a[i]�鵽a[n-1], ����С����, ��a[k]
            for ( int j = i+1; j < n; j++ )
 	     if ( a[j] < a[k] ) k = j;
	 int temp = a[i];  a[i] = a[k];   a[k] = temp;
      }
 }

int seqsearch ( int a[ ], int n, int x ) {
//��a[0],��,a[n-1]������x
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
