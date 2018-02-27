#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

typedef int ListData;

typedef struct node {          //������
   ListData  data;	                  //���������
   struct node * link;           //�������
} ListNode;

typedef ListNode  * LinkList;   //����ͷָ��
LinkList  head,last;                      //����ͷ��βָ��


void InitList(LinkList &head){
    head =              //������ͷ���
        (LinkList) malloc (sizeof (ListNode));

    head->link = NULL;
}
//ǰ�巨
void createListF (LinkList &head,int num) {
    int x;
    ListNode *q=(ListNode*) malloc(sizeof (ListNode));
    printf("Please input %d elements:\n",num);

    for(int i=0; i<num; i++){
//            printf("%d",num);
        scanf("%d",&x);
        q = (ListNode *) malloc (sizeof(ListNode));
        q->data = x;               //�����½��
        q->link = head->link;  //���뵽��ǰ��
        head->link = q;
    }

}
//��巨
void createListR (LinkList &head,int num) {
    last =              //������ͷ���
        (LinkList) malloc (sizeof (ListNode));
    ListNode *lastnode = head,*q;

    ListData x;
    printf("Please input %d elements:\n",num);

    for(int i=0; i< num;i++){
        scanf("%d",&x);
        q = (ListNode *) malloc (sizeof(ListNode));
        q->data = x;            //�����½��
        lastnode ->link = q;
        lastnode =q;    //���뵽��ĩ��
    }
    lastnode ->link = NULL;
}


ListNode * Locate ( LinkList first, int i ) {
//���ر��е� i ��Ԫ�صĵ�ַ
    if ( i < 0 ) return NULL;
    ListNode * p = first;   int k = 0;
    while ( p != NULL && k < i )
       { p = p->link;  k++; }	   //�ҵ� i �����
    if  ( k == i ) return p; //���ص� i ������ַ
    else return NULL;
}

//��ͷ���
int Insert (LinkList first, ListData x, int i ) {
//����Ԫ�� x �����������е� i �Ž��λ��
    ListNode * p = Locate( first, i-1 );
    if ( p == NULL ) return 0;	 //����iֵ��������0
    ListNode * newnode =          //�����½��
        (ListNode *) malloc (sizeof (ListNode) );
    newnode->data = x;
    newnode->link = p->link;       //����
    p->link = newnode;
    return 1;
}

int delete_by_order( LinkList first, int i ) {
	//������� i ��Ԫ��ɾȥ
    ListNode * p, * q;
	p = Locate ( first, i-1 ); //Ѱ�ҵ�i-1�����
 	if ( p == NULL || p->link == NULL)
	    return 0;//iֵ�������ձ�
   	q = p->link;
	p->link = q->link;            //ɾ�����
    free ( q );			    //�ͷ�
    return 1;
}

//���������
void makeEmpty ( LinkList first ) {
//ɾȥ�����г���ͷ�����������������
    ListNode *q;
    while ( first->link != NULL ) {//��������ʱ��ѭ�����ɾȥ���н��
 	     q = first->link;  first->link = q->link;
		free( q );        //�ͷ�
    }
	last=first;
}

//���㵥������
int Length( LinkList first ) {
   ListNode *p = first->link; //ָ�� p ָʾ��һ�����
	int count = 0;
    while ( p != NULL ) {      //��������
          p = p->link;  count++;
     }
     return count;
}

//��ֵ����
ListNode * Find ( LinkList first, ListData value ) {
		//�������д�ͷ����������ֵΪvalue�Ľ��
     ListNode * p = first->link;
          //ָ�� p ָʾ��һ�����
     while ( p != NULL && p->data != value )
         p = p->link;
     return p;
}
void display(LinkList &head){
    LinkList p=head->link;
    if(!p){
         printf("THE LIST IS EMPTY.\n");
         return ;
    }
    printf("The list is��\n");

    while( p != NULL){
        printf("%d ",p->data);
        p= p->link;
    }
    printf("\n");
}
int main(){
    int f;//chosen
    int num=0; //the number of the list
    int x, i; //element and position
//init
    InitList(head);
    display(head);
//create
    printf("Please input the number of the list:\n");
    scanf("%d",&num);
    printf("Chose how to create a list:\n1��insert from first;\n2��insert from last\n");
    scanf("%d",&f);
    if(f==1) createListF(head,num);
    if(f==2) createListR(head,num);
    display(head);
//insert
    printf("Please input the element and position you want to insert:\n");
    scanf("%d%d",&x,&i);
    Insert(head,x,i);
    display(head);
//delete
    printf("Please input the order of the element you want to delete:\n");
    scanf("%d",&i);
    delete_by_order(head,i);
    display(head);
//find
    printf("Please input the  element you want to find:\n");
    scanf("%d",&x);
    if(!Find(head,x)) printf("The element exists.\n");
    else printf("The element doesn't exist.\n");


}
