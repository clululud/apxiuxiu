#include <stdio.h>
#include <stdlib.h>
#include<windows.h>


struct linklist
{
	int data;
	linklist *next;
};
void createH(linklist *L, int x) //ͷ�巨
{
	linklist *tmpcell;
	tmpcell = (linklist*)malloc(sizeof(struct linklist));

	tmpcell->data = x;
	tmpcell->next = L->next;
	L->next = tmpcell;

	return;
}
void makelistH(linklist *L, int N)
{
	int x;
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &x);
		createH(L, x);
	}
	return;
}

void createT(linklist *L, int N) //β�巨
{
	linklist *s, *r;  //��ʱָ����βָ��
	int x;            //����
	r = L;//rʼ��ָ��β��㣬��ʼʱͷ����β�����ͬһ��
	for (int i = 0; i < N; i++)   //ѭ������
	{
		scanf("%d", &x);
		s = (linklist *)malloc(sizeof(struct linklist));//�������ݽ��
		s->data = x;//������
		r->next = s;//��s���뵽r��
		r = s;//ʹrָ��β���
	}
	r->next = NULL;//βָ��ָ�����ÿ�
	return;
}
linklist *findlocation(int location, linklist *L) //����λ��
{
	linklist *tmp = L->next;
	for (int i = 1; i != location; i++)
		tmp = tmp->next;
	return tmp;
}

void Print(linklist *L)  //��������������
{
	linklist *temp = L->next;  //��ͷ�ڵ�֮��Ԫ�ؿ�ʼ
	while (temp)       //�������н�� ����ָ������ָ��ɿط�Χ��
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	return;
}
void PrintLots(linklist *L, linklist *P, int Np)   //��p��Ԫ�ص�ֵ���L��λ����֮��Ӧ��Ԫ��
{
	int t = 0;
	linklist *tL = (linklist*)malloc(sizeof(struct linklist));
	linklist *tP = (linklist*)malloc(sizeof(struct linklist));
	tL->next = NULL; tP->next = NULL;
	tP = P->next;                        //������������� ����P��ͷ�ڵ� tp = p��tp->data = null
	for (int i = 0; i < Np; i++)
	{
		t = tP->data;
		tL = findlocation(t, L);
		printf("%d ", tL->data);
		tP = tP->next;
	}
	return;
}

linklist *intersection(linklist *L, linklist *P)   //�����L P����  A��B
{
	
	linklist *S = (linklist*)malloc(sizeof(struct linklist));  //���շ��ص�������
	S->next = NULL;                                            //��ʼ��
	L = L->next; P = P->next;//��ͷ�ڵ����һλ��ʼ
	linklist *tl = L;
	while (tl)         //ֱ�ӱ�����L��P           
	{  
		linklist *tp = P;
		while (tp)
		{ 
			if (L->data == tp->data)            //�ҵ�����ȵ�Ԫ�� ��������S��
				createH(S, L->data);             //ͷ�巨����	
			tp = tp->next;
		}
		tl = tl->next;
	}
	return S;                      //ʱ�临�Ӷ�O(N2)?
}
linklist *unionset(linklist *L, linklist *P)   //�����L P����
{
	
	linklist *S = (linklist*)malloc(sizeof(struct linklist));
	S = L;
	
	linklist *tP = P->next;
	while (tP)             //����P
	{   
		linklist *tL = L->next;
		int flag = 0;
		while (tL&&(!flag))         //����L
		{
			if (tP->data == tL->data)
				flag = 1;
			tL = tL->next;			
		}
		if (flag != 1)
		{
			createH(S, tP->data);
			flag = 0;
		}
		tP = tP->next;
	} 
	return S;

}

int main(void)
{
	int Nl, Np;
	linklist *L, *P;
	L = (linklist*)malloc(sizeof(struct linklist));
	P = (linklist*)malloc(sizeof(struct linklist));
	L->next = NULL; P->next = NULL;

	printf("����L��:\n");
	scanf("%d", &Nl); 
	makelistH(L, Nl);               //β�巨��������L


	printf("����P��:\n");
	scanf("%d", &Np);
	createT(P, Np);

    
	linklist *T1 = (linklist*)malloc(sizeof(struct linklist));
	linklist *T2 = (linklist*)malloc(sizeof(struct linklist));
	T1 = intersection(L, P);
	Print(T1);
	T2 = unionset(L, P);
	Print(T2);

	PrintLots(L, P, Np);

	system("pause");
}