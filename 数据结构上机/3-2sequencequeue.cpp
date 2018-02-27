#include <stdio.h>
#include <stdlib.h>

#define  MAXSIZE 100  //  最大队列长度
typedef struct{
    int  *base;
	 //初始化时动态分配存储空间的基址
    int front;    //队头指针，指向队头元素
    int rear;     //队尾指针，指向队尾元素的下一个位置
}SqQueue;

int InitQueue_Sq(SqQueue &Q) {//构造一个空队列Q
        Q.base=(int * )malloc
        (MAXSIZE*sizeof (int));
      if (!Q.base) exit (1);    //存储分配失败
      Q.front = Q.rear=0;
    return 1;
}  // InitQueue_Sq

int EnQueue_Sq(SqQueue  &Q, int  e ) {       //将元素e插入队尾
    if ((Q.rear+1)%MAXSIZE==Q.front) //队满
        return 0;
        Q.base[Q.rear] = e;      // 将元素e插入队尾
        Q.rear= (Q.rear+1)%MAXSIZE;
  // 修改队尾指针
        return 1;
} // EnQueue_Sq

int DeQueue_Sq(SqQueue  &Q) {       //删除队头元素，用e返回其值,并返回OK；否
       //则返回ERROR
    if (Q.rear== Q.front) return 0; //队空
    int e =Q.base[Q.front] ;
    Q.front= (Q.front+1)%MAXSIZE; // 修改队头指针
    return e;
}  // EnQueue_Sq

void display(SqQueue  &Q){
    if (Q.rear== Q.front) exit(1); //队空
    for(int i=Q.front;i<Q.rear;i++){
        printf("%d ",Q.base[i]);
    }
    printf("\n");
}

void YANGHUI ( int n ) {
    SqQueue q;                                //队列初始化
    InitQueue_Sq(q);
    EnQueue_Sq(q,1);  EnQueue_Sq(q,1);//预放入第一行的两个系数
    int s = 0;
    for (int i=1; i<=n; i++ ) {   //逐行处理
        printf("\n");		//换行
        EnQueue_Sq(q,0);
        for ( int j=1; j<=i+2; j++ ) {  //处理第i行的i+2个系数
            int t = DeQueue_Sq(q);//读取系数
            EnQueue_Sq(q,s+t );//计算下一行系数，并进队列
            s = t;
            if ( j != i+2 )
                printf("%d  ", s); //打印一个系数，第 i+2个为0
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
