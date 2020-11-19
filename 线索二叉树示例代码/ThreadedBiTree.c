#include"ThreadedBiTree.h"

ThreadNode* CreateThreadBinNode(ElemType data)          //结点创建函数
{
          ThreadNode* s = (ThreadNode*)malloc(sizeof(ThreadNode));
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

void _CreateBinTree(BinTree* T,ThreadNode** p, char** str)                         //根据序列创建二叉树子函数
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

///*二叉树的线索化*/
//void InThread(ThreadTree p, ThreadTree pre)
//{
//          if (p != NULL)
//          {
//                    InThread(p->lchild, pre);     //先往左边走
//                    if (p->lchild == NULL)        //结点不存在左孩子
//                    {
//                              p->lchild = pre;      //指向前驱结点
//                              p->ltag = 1;       //更改左标识位
//                    }
//                    if (pre!=NULL && pre->rchild == NULL)      //结点不存在右孩子
//                    {
//                              pre->rchild = p;     //指向后驱结点
//                              pre->rtag = 1;       //更改右标识位
//                    }
//                    pre = p;	//将旧的结点信息进行记录，方便之后的迭代
//                    InThread(p->rchild, pre);     //再往右边走(还需要再继续判断是否存在左孩子)
//          }
//}
//
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