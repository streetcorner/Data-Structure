#include <stdio.h>
#include <stdlib.h>

//link queue
typedef struct QNode{ //�����н������Ͷ���
    int  data;  //���ڴ�Ŷ���Ԫ��
    struct QNode *next;  //���ڴ��Ԫ��ֱ�Ӻ��
                                    //���ĵ�ַ
}QNode,*QueuePtr;

typedef struct
{  //�����еı�ͷ���ĵ����Ͷ���
    QueuePtr front;  //��ͷָ�룬ָ�������ͷ���
    QueuePtr rear;   //��βָ�룬ָ���β���
}LinkQueue;

int InitQueue_L(LinkQueue &Q) {//��һ���ն���
    Q.front=Q.rear=(QueuePtr)malloc(sizeof(QNode));
    //Ϊ�����е�ͷ������ռ�
    if (!Q.front) exit(1);
    Q.front->next=NULL;
    return 1;
} //InitQueue_L

//����ͷ���
int DestroyQueue_L(LinkQueue &Q)  {//���ٶ���Q
    while(Q.front) {
        Q.rear = Q.front->next;
        free(Q.front);
        Q.front = Q.rear;
    }
    return 1;
}   //DestroyQueue_L

//��ͷ���
int DestroyQueue_Lha(LinkQueue &Q)  {           //���ٶ���Q
    if (!Q.front) return 0; // �����в�����
    QNode * p;
        while(Q.front->next) {   // ���������е�����Ԫ�ؽ��ռ�
            p=Q.front->next;
            Q.front->next=p->next;
            free(p);
        }
        free(Q.front );                       // ����������ͷ���ռ�
        Q.front=Q.rear=NULL;
        return 1;
}//DestroyQueue_L

int EnQueue_L(LinkQueue &Q, int e ) {     //��������Q��β�������µĶ�β���
    QueuePtr p=(QueuePtr)malloc(sizeof(QNode));   //Ϊ��Ԫ��e������ռ� 
    if (!p) exit (1);     //�洢����ʧ��
    p->data=e; p->next=NULL;
    Q.rear->next=p;    //�޸Ķ�βָ�룬�����¶�β���
    Q.rear=p;
    return  1;
}

int DeQueue_L(LinkQueue &Q)  {        //�����в��գ���ɾ��Q�Ķ�ͷԪ�ؽ�㣬��e������ֵ��������OK�����򷵻�ERROR
    if (Q.front ==Q.rear) return 0;
             //�����пգ�����ERROR
    QueuePtr p=Q.front->next;             // pָ���ͷԪ�ؽ��
    int e=p->data;
    Q.front->next=p->next; // �޸�������ͷ���ָ��
    if(Q.rear == p)  Q.rear=Q.front;
// ����������ֻ��һ��Ԫ�ؽ������,Ҫͬʱ�޸Ķ�βָ��
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
