#include"ThreadedBiTree.h"

int main()
{
		  BinTree T;
		  InitThreadBinTree(&T, '#');
		  char* str = "ABC##DE##F##G#H##";
		  CreateBinTree(&T, str);				  //������ͨ������
		  CreateInThread(&T);					  //���ɶ�����������

		  return 0;
}