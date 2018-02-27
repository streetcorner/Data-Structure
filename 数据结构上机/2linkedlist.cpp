#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

typedef int ListData;

typedef struct node {          //链表结点
   ListData  data;	                  //结点数据域
   struct node * link;           //结点链域
} ListNode;

typedef ListNode  * LinkList;   //链表头指针
LinkList  head,last;                      //链表头、尾指针


void InitList(LinkList &head){
    head =              //建立表头结点
        (LinkList) malloc (sizeof (ListNode));

    head->link = NULL;
}
//前插法
void createListF (LinkList &head,int num) {
    int x;
    ListNode *q=(ListNode*) malloc(sizeof (ListNode));
    printf("Please input %d elements:\n",num);

    for(int i=0; i<num; i++){
//            printf("%d",num);
        scanf("%d",&x);
        q = (ListNode *) malloc (sizeof(ListNode));
        q->data = x;               //建立新结点
        q->link = head->link;  //插入到表前端
        head->link = q;
    }

}
//后插法
void createListR (LinkList &head,int num) {
    last =              //建立表头结点
        (LinkList) malloc (sizeof (ListNode));
    ListNode *lastnode = head,*q;

    ListData x;
    printf("Please input %d elements:\n",num);

    for(int i=0; i< num;i++){
        scanf("%d",&x);
        q = (ListNode *) malloc (sizeof(ListNode));
        q->data = x;            //建立新结点
        lastnode ->link = q;
        lastnode =q;    //插入到表末端
    }
    lastnode ->link = NULL;
}


ListNode * Locate ( LinkList first, int i ) {
//返回表中第 i 个元素的地址
    if ( i < 0 ) return NULL;
    ListNode * p = first;   int k = 0;
    while ( p != NULL && k < i )
       { p = p->link;  k++; }	   //找第 i 个结点
    if  ( k == i ) return p; //返回第 i 个结点地址
    else return NULL;
}

//带头结点
int Insert (LinkList first, ListData x, int i ) {
//将新元素 x 插入在链表中第 i 号结点位置
    ListNode * p = Locate( first, i-1 );
    if ( p == NULL ) return 0;	 //参数i值不合理返回0
    ListNode * newnode =          //创建新结点
        (ListNode *) malloc (sizeof (ListNode) );
    newnode->data = x;
    newnode->link = p->link;       //链入
    p->link = newnode;
    return 1;
}

int delete_by_order( LinkList first, int i ) {
	//将链表第 i 号元素删去
    ListNode * p, * q;
	p = Locate ( first, i-1 ); //寻找第i-1个结点
 	if ( p == NULL || p->link == NULL)
	    return 0;//i值不合理或空表
   	q = p->link;
	p->link = q->link;            //删除结点
    free ( q );			    //释放
    return 1;
}

//单链表清空
void makeEmpty ( LinkList first ) {
//删去链表中除表头结点外的所有其它结点
    ListNode *q;
    while ( first->link != NULL ) {//当链不空时，循环逐个删去所有结点
 	     q = first->link;  first->link = q->link;
		free( q );        //释放
    }
	last=first;
}

//计算单链表长度
int Length( LinkList first ) {
   ListNode *p = first->link; //指针 p 指示第一个结点
	int count = 0;
    while ( p != NULL ) {      //逐个结点检测
          p = p->link;  count++;
     }
     return count;
}

//按值查找
ListNode * Find ( LinkList first, ListData value ) {
		//在链表中从头搜索其数据值为value的结点
     ListNode * p = first->link;
          //指针 p 指示第一个结点
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
    printf("The list is：\n");

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
    printf("Chose how to create a list:\n1、insert from first;\n2、insert from last\n");
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
