#include"ThreadedBiTree.h"

ThreadNode* CreateThreadBinNode(ElemType data)          //结点创建函数
{
          ThreadNode* s = (ThreadNode*)malloc(sizeof(ThreadNode));
          assert(s != NULL);
          s->lchild = s->rchild = NULL;
          s->Ltag = s->Rtag = Link;
          s->data = data;
          return s;
}

void InitThreadBinTree(BinTree* T, ElemType stopflag)               //二叉树的线索化初始化
{
          T->root = NULL;
          T->stopflag = stopflag;       //初始化结束标识符
}

void CreateBinTree(BinTree* T, char* str)                            //根据序列创建二叉树
{
          _CreateBinTree(T, &(T->root), &str);
}

static void _CreateBinTree(BinTree* T,ThreadNode** p, char** str)                         //根据序列创建二叉树子函数
{
          if (**str==T->stopflag)
          {
                    *p = NULL;
          }
          else
          {
                    *p = CreateThreadBinNode(**str);
                    (*str)++;          //移动指针
                    _CreateBinTree(T, (&(*p)->lchild),str);
                    (*str)++;            //移动指针
                    _CreateBinTree(T, (&(*p)->rchild), str);
          }
}

void CreateInThread(BinTree* T)               //创建中序的线索化
{
          ThreadNode* pre = NULL;
          _CreateInThread(&pre, &(T->root));                //调用过程子函数
          pre->Rtag = Thread;           //最后一个结点也是线索化结点
          pre->rchild = NULL;
}

static void _CreateInThread(ThreadNode** pre, ThreadNode** q)       //创建中序的线索化子函数
{
          if (*q == NULL)
          {
                    return;
          }
          else
          {
                    _CreateInThread(pre, &((*q)->lchild));         
                    //先调用左子树直到位于最左边的元素为止
                   //最左边的元素的所有祖先节点全部入栈
                    if ((*q)->lchild == NULL)                            //前驱连接
                    {
                              (*q)->Ltag = Thread;                    //线索化
                              (*q)->lchild = *pre;                      //修改线索化指针指向前驱
                    }
                    if (*pre!=NULL && (*pre)->rchild == NULL)                   //后继连接
                    {
                              (*pre)->Rtag = Thread;                    //线索化
                              (*pre)->rchild = *q;                      //修改线索化指针指向后继
                    }
                    *pre = *q;          //更新pre的数值进行迭代操作
                    _CreateInThread(pre, &((*q)->rchild));            //后调用右子树
          }
}

ThreadNode* FindFirstNode(BinTree T)            //第一个结点
{
          return _FirstNode(T.root);              //调用子函数
}

static ThreadNode* _FirstNode(ThreadNode* p)            //第一个结点子函数
{
          ThreadNode* t = p;
          if (t != NULL)                 //树不为空
          {
                    while (t->Ltag!=Thread)
                    {
                              t = t->lchild;
                    }
          }
          return t != NULL ? t : NULL;
}

ThreadNode* FindLastNode(BinTree T)              //寻找最后一个结点
{
          return _LastNode(T.root);               //调用子函数
}

static ThreadNode* _LastNode(ThreadNode* p)             //最后一个结点子函数
{
          ThreadNode* t = p;
          if (t != NULL)                //树不为空
          {
                    while (t->Rtag != Thread)
                    {
                              t = t->rchild;
                    }
          }
          return t != NULL ? t : NULL;
}

ThreadNode* FindNextNode(BinTree T, ThreadNode* curr)            //寻找指定结点的后继结点
{
          return _NextNode(T.root, curr);         //调用子函数
}

static ThreadNode* _NextNode(ThreadNode* p, ThreadNode* curr)  //寻找指定结点的后继子函数
{
          if (p == NULL || curr == NULL)
          {
                    return NULL;
          }
          return curr->Rtag == Thread ? curr->rchild : _FirstNode(curr->rchild); //需要查找节点所在的右子树的最后的左子树
}

ThreadNode* FindPreNode(BinTree T, ThreadNode* curr)              //寻找指定结点的前驱结点
{
          return _PreNode(T.root, curr);
}

static ThreadNode* _PreNode(ThreadNode* p, ThreadNode* curr)   //寻找指定结点的前驱结点子函数
{
          if (p == NULL || curr == NULL)
          {
                    return NULL;
          }
          return curr->Ltag == Thread ? curr->lchild : _LastNode(curr->lchild); //需要查找节点所在的左子树的最后的右子树
}

void Inorder(BinTree T) //线索二叉树的遍历
{
          _Inorder(T, T.root);      //调用子函数
}

static void _Inorder(BinTree T,ThreadNode* p)  //线索二叉树的子函数
{
          for (ThreadNode* first = _FirstNode(p); first != NULL; first = _NextNode(p, first))
          {
                    printf("%c ", first->data);
          }
          printf("\n");
}