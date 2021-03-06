/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
File name: 11-1AVL二叉平衡树.cpp
Abstract:
AVL initialize,delete and display.
Version: 1.0
Last modify:2016.12.11
Copyright(c) 2016 Wang Yumeng
All rights reserved.
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;
#define EQ(a, b) ((a) == (b))
#define LT(a, b) ((a) < (b))
#define LQ(a, b) ((a) <= (b))
#define LH +1//左高
#define EH 0 //等高
#define RH -1 //右高
typedef int ElemType;
typedef struct BSTNode{
	ElemType	data;
	int			bf;	//平衡因子
	struct BSTNode *lchild,*rchild;
}BSTNode,*BSTree;
//右旋操作
void R_Rotate(BSTree &p)
{
	BSTree lc;
	lc = p->lchild;			//lc指向p的左子树
	p->lchild = lc->rchild;		//lc的右子树挂在p的左子树下
	lc->rchild = p;			//p挂在lc的左子树下
	p = lc;				//p指向新的根结点
}
//左旋操作
void L_Rotate(BSTree &p)
{
	BSTree rc;
	rc = p->rchild;
	p->rchild = rc->lchild;
	rc->lchild = p;
	p = rc;
}
//LH的情况，左边偏高。有两种情况，左左和左右
void LeftBalance(BSTree &T)
{
	BSTree lc, rd;
	lc = T->lchild;		//lc指向T的，左子树的根结点
	switch (lc->bf) {//检查T的左子树的平衡度
        case LH: //新结点插入在T的左孩子的，左子树上，要作单右旋处理
            T->bf = lc->bf = EH;//右旋之后的值
            R_Rotate(T);
            break;
        case RH:		//新结点插入在T的左孩子的右子树上，要作双旋处理，左右旋
            rd = lc->rchild;	//rd指向T的，左孩子的右子树的根
            switch (rd->bf) {	//修改T及其左孩子的平衡因子
                case LH:
                    T->bf = RH;
                    lc->bf = EH;
                    break;
                case EH:
                    T->bf = EH;
                    lc->bf = EH;
                    break;
                case RH:
                    T->bf = EH;
                    lc->bf = LH;
                    break;
            }
		rd->bf = EH;
		L_Rotate(T->lchild);
		R_Rotate(T);
	}

}
void RightBalance(BSTree &T)
{
	BSTree rc, ld;
	rc = T->rchild;		//rc指向T的右子树根结点
	switch (rc->bf) {	//检查T的右子树的平衡度
	case RH:		//新结点插入在T的右孩子的右子树上，要作单左旋处理
		T->bf = rc->bf = EH;
		L_Rotate(T);
		break;
	case LH:		//新结点插入在T的右孩子的左子树上，要作双旋处理
		ld = rc->lchild;	//ld指向T的右孩子的左子树根结点
		switch (ld->bf) {
		case LH:
			T->bf = EH;
			rc->bf = RH;
			break;
		case EH:
			T->bf = EH;
			rc->bf = EH;
			break;
		case RH:
			T->bf = LH;
			rc->bf = EH;
			break;
		}
		ld->bf = EH;
		R_Rotate(T->rchild);
		L_Rotate(T);
	}
}
int InsertAVL(BSTree &T,ElemType e,bool &taller){//taller表示树是否长高，布尔型
   // printf("1111111111111\n");
	if(!T){//如果结点不存在，则创建
        //printf("1111111111111\n");
		T=(BSTree)malloc(sizeof(BSTNode));
		T->data=e;T->lchild=T->rchild=NULL;
		T->bf=EH;taller=1;
	}
	else{
		if (EQ(e,T->data)){  //找到，不用插入节点
            //printf("1111111111111\n");
            taller=0;
            return 0;
        }
		if (LT(e,T->data)){//要插入在左子上
		    if(!InsertAVL(T->lchild,e,taller)) return 0;
		    //递归调用直至在某个分枝上插入节点作为叶子节点
		    //插入成功时候才会返回1
		    if(taller)
		    //如果要长高，就判断是哪种类型
                switch(T->bf){//检查T的平衡度
                    case LH://左高
                    LeftBalance(T);taller=0;break;
                    case EH:
                    T->bf=LH;taller=1;break;
                    case RH:
                    T->bf=EH;taller=0;break;
                }//switch(T->bf)
		}//if
		else{//要插入在右子上
		    if(!InsertAVL(T->rchild,e,taller)) return 0;
		    //递归右结点，插入成功时候才会返回1
		    if(taller)
                switch(T->bf){
                    case LH:
                    T->bf=EH;taller=0;break;
                    case EH:
                    T->bf=RH;taller=1;break;
                    case RH:
                    RightBalance(T);taller=0;break;
                    //右平衡函数没有给出
                }//switch(T->bf)
		}//else
	}//else
	return 1;
}//InsertAVL

//前序遍历
void PreOrder ( BSTree T ) {
    if ( T != NULL ) {
        //Visit( T->data);
        printf("%d",T->data);
        if(T->lchild ||T->rchild )//没有孩子就不用括号
            printf("(");
        PreOrder ( T->lchild );
        if(T->rchild )//如果没有右孩子就没逗号
            printf(",");
        PreOrder ( T->rchild );
        if(T->lchild ||T->rchild )//没有孩子就不用括号
            printf(")");
    }
}
int main(){
        BSTree T=NULL;
      int a[10]={4,9,0,1,8,6,3,5,2,7};
      int len=10;
        bool taller=1;
      for(int i=0; i<len; i++){
          InsertAVL(T,a[i],taller);
      }
      PreOrder(T);
        //InsertAVL(T,1,taller);
        //cout<<T<<endl;
}
