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

/*�����������Ĳ���*/
ThreadNode* FindFirstNode(BinTree T);             //��һ�����
static ThreadNode* _FirstNode(ThreadNode* p);             //��һ������Ӻ���

ThreadNode* FindLastNode(BinTree T);              //���һ�����
static ThreadNode* _LastNode(ThreadNode* p);              //���һ������Ӻ���

ThreadNode* FindNextNode(BinTree T, ThreadNode* curr);            //Ѱ��ָ�����ĺ�̽��
static ThreadNode* _NextNode(ThreadNode* p,  ThreadNode* curr);  //Ѱ��ָ�����ĺ���Ӻ���

ThreadNode* FindPreNode(BinTree T, ThreadNode* curr);              //Ѱ��ָ������ǰ�����
static ThreadNode* _PreNode(ThreadNode* p, ThreadNode* curr);   //Ѱ��ָ������ǰ������Ӻ���

/*�����������ı���*/
void Inorder(BinTree T);  //�����������ı���
static void _Inorder(BinTree T, ThreadNode* p);  //�������������Ӻ���