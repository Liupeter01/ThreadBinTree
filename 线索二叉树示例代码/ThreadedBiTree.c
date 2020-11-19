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


///*中序线索二叉树的遍历*/
//void Inorder(ThreadNode* T)
//{
//          for (ThreadNode* p = FirstNode(T); p != NULL; p = NextNode(p))
//          {
//                    printf("%d", p->data);
//          }
//}
//
//ThreadNode* FirstNode(ThreadNode* p)    //寻找位于最左边的结点
//{
//          while (p->ltag == 0)        //左孩子不是线索
//          {
//                    p = p->lchild;
//          }
//          return p;
//}
//
//ThreadNode* NextNode(ThreadNode* p)
//{
//          if (p->rtag == 0)   //右孩子不是线索
//          {
//                    return FirstNode(p->rchild);  //继续递归寻找右孩子的左子树
//          }
//          else  //右孩子是线索
//          {
//                    return p->rchild;   //返回结点的后驱指针
//          }
//}