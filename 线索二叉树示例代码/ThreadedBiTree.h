#pragma once
#include<stdio.h>
#include<stdlib.h>

#define ElemType char
typedef enum Tag { Link, Thread }Tag;      //一个为孩子结点链接，另一个为线索化

typedef struct ThreadNode               //线索化结点
{
          ElemType data;
          struct ThreadNode* rchild;    //右孩子
          struct ThreadNode* lchild;    //左孩子
          Tag Rtag;           //右标志位
          Tag Ltag;           //左标志位
}ThreadNode, * ThreadTree;

typedef struct BinTree
{
          ThreadNode* root;             //根节点
          ElemType stopflag;            //停止标记
}BinTree;

ThreadNode* CreateThreadBinNode(ElemType data);             //结点创建函数

void InitThreadBinTree(BinTree* T, ElemType stopflag);               //二叉树的线索化初始化
void CreateBinTree(BinTree* T, char* str);                            //根据序列创建二叉树
void _CreateBinTree(BinTree* T, ThreadNode** p, char** str);                       //根据序列创建二叉树子函数

///*二叉树的线索化初始化*/
//void CreateInThread(ThreadTree T);
//
///*二叉树的线索化*/
//void InThread(ThreadTree p, ThreadTree pre);
//
///*中序线索二叉树的遍历*/
//void Inorder(ThreadNode* T);
//ThreadNode* FirstNode(ThreadNode* p);
//ThreadNode* NextNode(ThreadNode* p);