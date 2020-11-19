#include"ThreadedBiTree.h"

int main()
{
		  BinTree T;
		  InitThreadBinTree(&T, '#');
		  char* str = "ABC##DE##F##G#H##";
		  CreateBinTree(&T, str);				  //创建普通二叉树
		  CreateInThread(&T);					  //生成二叉树线索化

		  return 0;
}