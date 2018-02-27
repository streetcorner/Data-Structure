/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
File name: 10-2ary sort tree.cpp
Abstract:
Binary sort tree.
Version: 1.0
Last modify:2016.12.9
Copyright(c) 2016 Wang Yumeng
All rights reserved.

unfinished:
希尔、快排
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
#include<stdio.h>
#include<stdlib.h>
#include<iostream>


using namespace std;

typedef int KeyType;
typedef int TElemType ;
typedef struct BiTNode { // 结点结构
    TElemType  data;
    struct BiTNode  *lchild, *rchild; // 左右指针
 } BiTNode, *BiTree;
bool EQ(KeyType kval,TElemType e){
    if(kval==e)
        return 1;
    else return 0;
}
bool LT(KeyType kval,TElemType e){
    if(e> kval)
        return 1;
    else return 0;
}
int SearchBST (BiTree T, KeyType kval, BiTree f, BiTree &p ) {//t is node,f is tree flag, p is return position
    if (!T)//结点为空值
    {
       // printf("oooooooooo\n");
        p = f;
        return 0;
    }  //查找不成功
    else  if ( EQ(kval, T->data) )
    { p = T;  return 1; }  // 查找成功
    else  if ( LT(kval, T->data) )//右>左
        return SearchBST (T->lchild, kval, T, p ); // 在左子树中继续查找
    else
        return SearchBST (T->rchild, kval, T, p );
                             // 在右子树中继续查找
}
int InsertBST(BiTree &T, TElemType key ) {
    BiTNode *p=  new  BiTNode;
    if (!SearchBST ( T, key, NULL, p ))//没找到
    {
        BiTNode *s =  new  BiTNode; // 为新结点分配空间
        s->data = key;
        s->lchild = s->rchild = NULL;

        if  ( !p )  T = s;     // 若为空值，插入 s 为新的叶子或者根结点
        else   if ( LT(key, p->data) )
                 p->lchild = s;       // 插入 *s 为 *p 的左孩子
        else  p->rchild = s;     // 插入 *s 为 *p 的右孩子
        return 1;     // 插入成功
    }
   else return 0;
} // Insert BST
//其中删除操作过程如下：
void Delete ( BiTree &p ){
   // 从二叉排序树中删除结点 p，
   // 并重接它的左子树或右子树
   BiTNode *q= new  BiTNode;
   BiTNode *f= new  BiTNode;
   BiTNode *s= new  BiTNode;
   if (!p->rchild)  {
    //左子树为空树只需重接它的右子树
        q = p;
        f->lchild = p->rchild;
        delete(q);
   }
   else if (!p->lchild) {
     //右子树为空树则只需重接它的左子树
        q = p;
        f->lchild = p->lchild;
        delete(q);
   }
   else {
        //左右子树均不空
        q = p;
        s = p->lchild;
        while (s->rchild)
             { q = s;  s = s->rchild; }
               // s 指向被删结点的前驱p->data = s->data;
        if (q != p )  q->rchild = s->lchild;
        else  q->lchild = s->lchild;
         // 重接*q的左子树
        delete(s);
   }
} // Delete
int DeleteBST (BiTree &T,  KeyType kval ) {
    if (!T)  return 0;//空树
      	//不存在关键字等于kval的数据元素
    else if ( EQ (kval, T->data) )
    {  Delete (T);   return 1;  }
         // 找到关键字等于key的数据元素
    else if ( LT (kval, T->data) )
        return DeleteBST ( T->lchild, kval );
                // 继续在左子树中进行查找
    else
        return DeleteBST ( T->rchild, kval );
       // 继续在右子树中进行查找
} // DeleteBST

//前序遍历
void PreOrder ( BiTNode *T ) {
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
    BiTree T=NULL;
    int len=10;
    int a[]={4,9,0,1,8,6,3,5,2,7};
   // InsertBST(T,1);
   // printf("%d\n",a[4]);
    for(int i=0; i<len; i++){
        InsertBST(T,a[i]);
    }

    PreOrder(T);
    return 0;
}
