#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>

#define ElemType char
typedef enum Tag { Link, Thread }Tag;      //һ��Ϊ���ӽ�����ӣ���һ��Ϊ������

typedef struct ThreadNode               //���������
{
          ElemType data;
          struct ThreadNode* rchild;    //�Һ���
          struct ThreadNode* lchild;    //����
          Tag Rtag;           //�ұ�־λ
          Tag Ltag;           //���־λ
}ThreadNode;

typedef struct BinTree
{
          ThreadNode* root;             //���ڵ�
          ElemType stopflag;            //ֹͣ���
}BinTree;

ThreadNode* CreateThreadBinNode(ElemType data);             //��㴴������

/*��ͨ�Ķ�������������*/
void InitThreadBinTree(BinTree* T, ElemType stopflag);               //�������ĳ�ʼ��
void CreateBinTree(BinTree* T, char* str);                                      //�������д���������
static void _CreateBinTree(BinTree* T, ThreadNode** p, char** str);     //�������д����������Ӻ���

/*����������������*/
void CreateInThread(BinTree* T);                //���������������
static void _CreateInThread(ThreadNode **pre,ThreadNode**q);        //����������������Ӻ���

/*���������������ı���*/

//void Inorder(ThreadNode* T);
//ThreadNode* FirstNode(ThreadNode* p);
//ThreadNode* NextNode(ThreadNode* p);