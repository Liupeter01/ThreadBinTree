#pragma once
#include<stdio.h>
#include<stdlib.h>

#define ElemType char
typedef enum Tag { Link, Thread }Tag;      //һ��Ϊ���ӽ�����ӣ���һ��Ϊ������

typedef struct ThreadNode               //���������
{
          ElemType data;
          struct ThreadNode* rchild;    //�Һ���
          struct ThreadNode* lchild;    //����
          Tag Rtag;           //�ұ�־λ
          Tag Ltag;           //���־λ
}ThreadNode, * ThreadTree;

typedef struct BinTree
{
          ThreadNode* root;             //���ڵ�
          ElemType stopflag;            //ֹͣ���
}BinTree;

ThreadNode* CreateThreadBinNode(ElemType data);             //��㴴������

void InitThreadBinTree(BinTree* T, ElemType stopflag);               //����������������ʼ��
void CreateBinTree(BinTree* T, char* str);                            //�������д���������
void _CreateBinTree(BinTree* T, ThreadNode** p, char** str);                       //�������д����������Ӻ���

///*����������������ʼ��*/
//void CreateInThread(ThreadTree T);
//
///*��������������*/
//void InThread(ThreadTree p, ThreadTree pre);
//
///*���������������ı���*/
//void Inorder(ThreadNode* T);
//ThreadNode* FirstNode(ThreadNode* p);
//ThreadNode* NextNode(ThreadNode* p);