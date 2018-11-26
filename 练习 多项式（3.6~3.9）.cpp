#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

/*多项式的各种运算*/


struct polynomial    //多项式
{
	int coefficient;   //系数
	int exponent;      //幂
	polynomial *next;  //指针域
};
void createH(polynomial *L, int c,int e) //头插法 头节点 系数 幂
{
	polynomial *tmpcell;
	tmpcell = (polynomial*)malloc(sizeof(struct polynomial));
	tmpcell->coefficient = c;
	tmpcell->exponent = e;
	tmpcell->next = L->next;
	L->next = tmpcell;
	return;
}
void makelistH(polynomial *L, int N)  //头节点 项数
{
	int c;    //系数
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &c);
		createH(L, c, i);
	}
	return;
}

void Print(polynomial *L)  //输出链表里的数据
{
	polynomial *temp = L->next;  //从头节点之后元素开始
	while (temp)       //遍历所有结点 工作指针最终指向可控范围外
	{
		printf("%d ", temp->coefficient);
		printf("%d ", temp->exponent);
		printf("\n");
		temp = temp->next;
	}
	printf("\n");
	return;
}
 
polynomial *add(polynomial *L,polynomial *P)
{
	 
}
polynomial *mult(polynomial *L, polynomial *P)
{

}

int main(void)
{
	int Nl, Np;
	polynomial *L, *P;
	L = (polynomial*)malloc(sizeof(struct polynomial));
	P = (polynomial*)malloc(sizeof(struct polynomial));
	L->next = NULL; P->next = NULL;

	printf("输入多项式L项数:\n");
	scanf("%d", &Nl); 
	makelistH(L, Nl);               //尾插法建立链表L


	printf("输入多项式P项数:\n");
	scanf("%d", &Np);
	makelistH(P, Np);

    
	polynomial *T1 = (polynomial*)malloc(sizeof(struct polynomial));
	polynomial *T2 = (polynomial*)malloc(sizeof(struct polynomial));
	T1 = add(L, P);
	Print(T1);
	T2 = mult(L, P);
	Print(T2);

	 

	system("pause");
}