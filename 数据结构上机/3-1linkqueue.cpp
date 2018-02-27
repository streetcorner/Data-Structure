#include <stdio.h>
#include <stdlib.h>

//link queue
typedef struct QNode{ //链队列结点的类型定义
    int  data;  //用于存放队列元素
    struct QNode *next;  //用于存放元素直接后继
                                    //结点的地址
}QNode,*QueuePtr;

typedef struct
{  //链队列的表头结点的的类型定义
    QueuePtr front;  //队头指针，指向链表的头结点
    QueuePtr rear;   //队尾指针，指向队尾结点
}LinkQueue;

int InitQueue_L(LinkQueue &Q) {//建一个空队列
    Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
    //为链队列的头结点分配空间
    if (!Q.front) exit(1);
    Q.front->next=NULL;
    return 1;
} //InitQueue_L

//不带头结点
int DestroyQueue_L(LinkQueue &Q)  {//销毁队列Q
    while(Q.front) {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
    return 1;
}   //DestroyQueue_L

//带头结点
int DestroyQueue_Lha(LinkQueue &Q)  {           //销毁队列Q
    if (!Q.front) return 0; // 链队列不存在
    QNode * p;
        while(Q.front->next) {   // 回收链队列的所有元素结点空间
            p=Q.front->next;
            Q.front->next=p->next;
            free(p);
        }
        free(Q.front );                       // 回收链队列头结点空间
        Q.front=Q.rear=NULL;
        return 1;
}//DestroyQueue_L

int EnQueue_L(LinkQueue &Q, int e ) {     //在链队列Q队尾，插入新的队尾结点
    QueuePtr p=(QueuePtr)malloc(sizeof(QNode));   //为新元素e分配结点空间 
    if (!p) exit (1);     //存储分配失败
    p->data=e; p->next=NULL;
    Q.rear->next=p;    //修改队尾指针，插入新队尾结点
    Q.rear=p;
    return  1;
}

int DeQueue_L(LinkQueue &Q)  {        //若队列不空，则删除Q的队头元素结点，用e返回其值，并返回OK；否则返回ERROR
    if (Q.front ==Q.rear) return 0;
             //若队列空，返回ERROR
    QueuePtr p=Q.front->next;             // p指向队头元素结点
    int e=p->data;
    Q.front->next=p->next; // 修改链队列头结点指针
    if(Q.rear == p)  Q.rear=Q.front;
// 对于链队列只有一个元素结点的情况,要同时修改队尾指针
    free(p);
    return e;
}


int display(LinkQueue &q){
    QueuePtr p=q.front->next;
    while(p!=NULL){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}
int main(){
    int n,e;
    LinkQueue q;
    InitQueue_L(q);//with head node

    printf("Enter the number of linkqueue:\n");
    scanf("%d",&n);
    printf("Enter %d number:\n",n);
    while(n--){
        scanf("%d",&e);
        EnQueue_L(q,e);
    }
    printf("The queue is:\n");
    display(q);

//    printf("Enter the number you want to delete:\n");
//    scanf("%d",&e);
    e=DeQueue_L(q);
    printf("After delete node %d, the queue is:\n",e);
    display(q);

    if(DestroyQueue_Lha(q))
        printf("Destroy successful!\n");

    return 0;
}
