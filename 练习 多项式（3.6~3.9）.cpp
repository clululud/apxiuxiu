#include <stdio.h>
#include <stdlib.h>
#include<windows.h>

/*����ʽ�ĸ�������*/


struct polynomial    //����ʽ
{
	int coefficient;   //ϵ��
	int exponent;      //��
	polynomial *next;  //ָ����
};
void createH(polynomial *L, int c,int e) //ͷ�巨 ͷ�ڵ� ϵ�� ��
{
	polynomial *tmpcell;
	tmpcell = (polynomial*)malloc(sizeof(struct polynomial));
	tmpcell->coefficient = c;
	tmpcell->exponent = e;
	tmpcell->next = L->next;
	L->next = tmpcell;
	return;
}
void makelistH(polynomial *L, int N)  //ͷ�ڵ� ����
{
	int c;    //ϵ��
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &c);
		createH(L, c, i);
	}
	return;
}

void Print(polynomial *L)  //��������������
{
	polynomial *temp = L->next;  //��ͷ�ڵ�֮��Ԫ�ؿ�ʼ
	while (temp)       //�������н�� ����ָ������ָ��ɿط�Χ��
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

	printf("�������ʽL����:\n");
	scanf("%d", &Nl); 
	makelistH(L, Nl);               //β�巨��������L


	printf("�������ʽP����:\n");
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