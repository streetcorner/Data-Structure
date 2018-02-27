#include <stdio.h>
#include <stdlib.h>

#define  MAXSIZE 100  //  �����г���
typedef struct{
    int  *base;
	 //��ʼ��ʱ��̬����洢�ռ�Ļ�ַ
    int front;    //��ͷָ�룬ָ���ͷԪ��
    int rear;     //��βָ�룬ָ���βԪ�ص���һ��λ��
}SqQueue;

int InitQueue_Sq(SqQueue &Q) {//����һ���ն���Q
        Q.base=(int * )malloc
        (MAXSIZE*sizeof (int));
      if (!Q.base) exit (1);    //�洢����ʧ��
      Q.front = Q.rear=0;
    return 1;
}  // InitQueue_Sq

int EnQueue_Sq(SqQueue  &Q, int  e ) {       //��Ԫ��e�����β
    if ((Q.rear+1)%MAXSIZE==Q.front) //����
        return 0;
        Q.base[Q.rear] = e;      // ��Ԫ��e�����β
        Q.rear= (Q.rear+1)%MAXSIZE;
  // �޸Ķ�βָ��
        return 1;
} // EnQueue_Sq

int DeQueue_Sq(SqQueue  &Q) {       //ɾ����ͷԪ�أ���e������ֵ,������OK����
       //�򷵻�ERROR
    if (Q.rear== Q.front) return 0; //�ӿ�
    int e =Q.base[Q.front] ;
    Q.front= (Q.front+1)%MAXSIZE; // �޸Ķ�ͷָ��
    return e;
}  // EnQueue_Sq

void display(SqQueue  &Q){
    if (Q.rear== Q.front) exit(1); //�ӿ�
    for(int i=Q.front;i<Q.rear;i++){
        printf("%d ",Q.base[i]);
    }
    printf("\n");
}

void YANGHUI ( int n ) {
    SqQueue q;                                //���г�ʼ��
    InitQueue_Sq(q);
    EnQueue_Sq(q,1);  EnQueue_Sq(q,1);//Ԥ�����һ�е�����ϵ��
    int s = 0;
    for (int i=1; i<=n; i++ ) {   //���д���
        printf("\n");		//����
        EnQueue_Sq(q,0);
        for ( int j=1; j<=i+2; j++ ) {  //�����i�е�i+2��ϵ��
            int t = DeQueue_Sq(q);//��ȡϵ��
            EnQueue_Sq(q,s+t );//������һ��ϵ������������
            s = t;
            if ( j != i+2 )
                printf("%d  ", s); //��ӡһ��ϵ������ i+2��Ϊ0
        }
    }
}

int main(){
    int n,e;
    SqQueue q;
    InitQueue_Sq(q);
//YANGHUI
    printf("Enter the number of sequence queue:\n");
    scanf("%d",&n);
    YANGHUI(n);
    printf("\n");
//SEQUENCE QUEUE
    printf("Enter the number of sequence queue:\n");
    scanf("%d",&n);
    printf("Enter %d number:\n",n);
    while(n--){
        scanf("%d",&e);
        EnQueue_Sq(q,e);
    }

    printf("The queue is:\n");
    display(q);

    e=DeQueue_Sq(q);
    printf("After delete node %d, the queue is:\n",e);
    display(q);

}
