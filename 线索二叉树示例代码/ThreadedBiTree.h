#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>

#define ElemType char
typedef enum Tag { Link, Thread }Tag;      //一个为孩子结点链接，另一个为线索化

typedef struct ThreadNode               //线索化结点
{
          ElemType data;
          struct ThreadNode* rchild;    //右孩子
          struct ThreadNode* lchild;    //左孩子
          Tag Rtag;           //右标志位
          Tag Ltag;           //左标志位
}ThreadNode;

typedef struct BinTree
{
          ThreadNode* root;             //根节点
          ElemType stopflag;            //停止标记
}BinTree;

ThreadNode* CreateThreadBinNode(ElemType data);             //结点创建函数

/*普通的二叉树创建函数*/
void InitThreadBinTree(BinTree* T, ElemType stopflag);               //二叉树的初始化
void CreateBinTree(BinTree* T, char* str);                                      //根据序列创建二叉树
static void _CreateBinTree(BinTree* T, ThreadNode** p, char** str);     //根据序列创建二叉树子函数

/*二叉树线索化程序*/
void CreateInThread(BinTree* T);                //创建中序的线索化
static void _CreateInThread(ThreadNode **pre,ThreadNode**q);        //创建中序的线索化子函数

/*线索二叉树的查找*/
ThreadNode* FindFirstNode(BinTree T);             //第一个结点
static ThreadNode* _FirstNode(ThreadNode* p);             //第一个结点子函数

ThreadNode* FindLastNode(BinTree T);              //最后一个结点
static ThreadNode* _LastNode(ThreadNode* p);              //最后一个结点子函数

ThreadNode* FindNextNode(BinTree T, ThreadNode* curr);            //寻找指定结点的后继结点
static ThreadNode* _NextNode(ThreadNode* p,  ThreadNode* curr);  //寻找指定结点的后继子函数

ThreadNode* FindPreNode(BinTree T, ThreadNode* curr);              //寻找指定结点的前驱结点
static ThreadNode* _PreNode(ThreadNode* p, ThreadNode* curr);   //寻找指定结点的前驱结点子函数

ThreadNode* Search(BinTree T, ElemType key);                //查找某一个结点
static ThreadNode* _Search(ThreadNode* p, ElemType key);        //查找某一个结点子函数

ThreadNode* FindParent(BinTree T, ThreadNode* curr);                //查找某一个结点父节点
static ThreadNode* _FindParent(ThreadNode* p, ThreadNode* curr);        //查找某一个结点父节点子函数

/*线索二叉树的遍历*/
void Inorder(BinTree T);  //线索二叉树的遍历
static void _Inorder(BinTree T, ThreadNode* p);  //线索二叉树的子函数