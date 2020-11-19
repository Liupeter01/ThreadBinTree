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


///*���������������ı���*/
//void Inorder(ThreadNode* T)
//{
//          for (ThreadNode* p = FirstNode(T); p != NULL; p = NextNode(p))
//          {
//                    printf("%d", p->data);
//          }
//}
//
//ThreadNode* FirstNode(ThreadNode* p)    //Ѱ��λ������ߵĽ��
//{
//          while (p->ltag == 0)        //���Ӳ�������
//          {
//                    p = p->lchild;
//          }
//          return p;
//}
//
//ThreadNode* NextNode(ThreadNode* p)
//{
//          if (p->rtag == 0)   //�Һ��Ӳ�������
//          {
//                    return FirstNode(p->rchild);  //�����ݹ�Ѱ���Һ��ӵ�������
//          }
//          else  //�Һ���������
//          {
//                    return p->rchild;   //���ؽ��ĺ���ָ��
//          }
//}