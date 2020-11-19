#include"ThreadedBiTree.h"

ThreadNode* CreateThreadBinNode(ElemType data)          //��㴴������
{
          ThreadNode* s = (ThreadNode*)malloc(sizeof(ThreadNode));
          assert(s != NULL);
          s->lchild = s->rchild = NULL;
          s->Ltag = s->Rtag = Link;
          s->data = data;
          return s;
}

void InitThreadBinTree(BinTree* T, ElemType stopflag)               //����������������ʼ��
{
          T->root = NULL;
          T->stopflag = stopflag;       //��ʼ��������ʶ��
}

void CreateBinTree(BinTree* T, char* str)                            //�������д���������
{
          _CreateBinTree(T, &(T->root), &str);
}

static void _CreateBinTree(BinTree* T,ThreadNode** p, char** str)                         //�������д����������Ӻ���
{
          if (**str==T->stopflag)
          {
                    *p = NULL;
          }
          else
          {
                    *p = CreateThreadBinNode(**str);
                    (*str)++;          //�ƶ�ָ��
                    _CreateBinTree(T, (&(*p)->lchild),str);
                    (*str)++;            //�ƶ�ָ��
                    _CreateBinTree(T, (&(*p)->rchild), str);
          }
}

void CreateInThread(BinTree* T)               //���������������
{
          ThreadNode* pre = NULL;
          _CreateInThread(&pre, &(T->root));                //���ù����Ӻ���
          pre->Rtag = Thread;           //���һ�����Ҳ�����������
          pre->rchild = NULL;
}

static void _CreateInThread(ThreadNode** pre, ThreadNode** q)       //����������������Ӻ���
{
          if (*q == NULL)
          {
                    return;
          }
          else
          {
                    _CreateInThread(pre, &((*q)->lchild));         
                    //�ȵ���������ֱ��λ������ߵ�Ԫ��Ϊֹ
                   //����ߵ�Ԫ�ص��������Ƚڵ�ȫ����ջ
                    if ((*q)->lchild == NULL)                            //ǰ������
                    {
                              (*q)->Ltag = Thread;                    //������
                              (*q)->lchild = *pre;                      //�޸�������ָ��ָ��ǰ��
                    }
                    if (*pre!=NULL && (*pre)->rchild == NULL)                   //�������
                    {
                              (*pre)->Rtag = Thread;                    //������
                              (*pre)->rchild = *q;                      //�޸�������ָ��ָ����
                    }
                    *pre = *q;          //����pre����ֵ���е�������
                    _CreateInThread(pre, &((*q)->rchild));            //�����������
          }
}

ThreadNode* FindFirstNode(BinTree T)            //��һ�����
{
          return _FirstNode(T.root);              //�����Ӻ���
}

static ThreadNode* _FirstNode(ThreadNode* p)            //��һ������Ӻ���
{
          ThreadNode* t = p;
          if (t != NULL)                 //����Ϊ��
          {
                    while (t->Ltag!=Thread)
                    {
                              t = t->lchild;
                    }
          }
          return t != NULL ? t : NULL;
}

ThreadNode* FindLastNode(BinTree T)              //Ѱ�����һ�����
{
          return _LastNode(T.root);               //�����Ӻ���
}

static ThreadNode* _LastNode(ThreadNode* p)             //���һ������Ӻ���
{
          ThreadNode* t = p;
          if (t != NULL)                //����Ϊ��
          {
                    while (t->Rtag != Thread)
                    {
                              t = t->rchild;
                    }
          }
          return t != NULL ? t : NULL;
}

ThreadNode* FindNextNode(BinTree T, ThreadNode* curr)            //Ѱ��ָ�����ĺ�̽��
{
          return _NextNode(T.root, curr);         //�����Ӻ���
}

static ThreadNode* _NextNode(ThreadNode* p, ThreadNode* curr)  //Ѱ��ָ�����ĺ���Ӻ���
{
          if (p == NULL || curr == NULL)
          {
                    return NULL;
          }
          return curr->Rtag == Thread ? curr->rchild : _FirstNode(curr->rchild); //��Ҫ���ҽڵ����ڵ�������������������
}

ThreadNode* FindPreNode(BinTree T, ThreadNode* curr)              //Ѱ��ָ������ǰ�����
{
          return _PreNode(T.root, curr);
}

static ThreadNode* _PreNode(ThreadNode* p, ThreadNode* curr)   //Ѱ��ָ������ǰ������Ӻ���
{
          if (p == NULL || curr == NULL)
          {
                    return NULL;
          }
          return curr->Ltag == Thread ? curr->lchild : _LastNode(curr->lchild); //��Ҫ���ҽڵ����ڵ�������������������
}

void Inorder(BinTree T) //�����������ı���
{
          _Inorder(T, T.root);      //�����Ӻ���
}

static void _Inorder(BinTree T,ThreadNode* p)  //�������������Ӻ���
{
          for (ThreadNode* first = _FirstNode(p); first != NULL; first = _NextNode(p, first))
          {
                    printf("%c ", first->data);
          }
          printf("\n");
}