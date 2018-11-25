#include <stdio.h>
#include <stdlib.h>
#include<windows.h>


struct linklist
{
	int data;
	linklist *next;
};
void createH(linklist *L, int x) //头插法
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

void createT(linklist *L, int N) //尾插法
{
	linklist *s, *r;  //临时指针与尾指针
	int x;            //数据
	r = L;//r始终指向尾结点，开始时头结点和尾结点是同一个
	for (int i = 0; i < N; i++)   //循环插入
	{
		scanf("%d", &x);
		s = (linklist *)malloc(sizeof(struct linklist));//创建数据结点
		s->data = x;//数据域
		r->next = s;//将s插入到r后
		r = s;//使r指向尾结点
	}
	r->next = NULL;//尾指针指针域置空
	return;
}
linklist *findlocation(int location, linklist *L) //查找位置
{
	linklist *tmp = L->next;
	for (int i = 1; i != location; i++)
		tmp = tmp->next;
	return tmp;
}

void Print(linklist *L)  //输出链表里的数据
{
	linklist *temp = L->next;  //从头节点之后元素开始
	while (temp)       //遍历所有结点 工作指针最终指向可控范围外
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
	return;
}
void PrintLots(linklist *L, linklist *P, int Np)   //按p中元素的值输出L中位置与之对应的元素
{
	int t = 0;
	linklist *tL = (linklist*)malloc(sizeof(struct linklist));
	linklist *tP = (linklist*)malloc(sizeof(struct linklist));
	tL->next = NULL; tP->next = NULL;
	tP = P->next;                        //！这里出了问题 链表P带头节点 tp = p；tp->data = null
	for (int i = 0; i < Np; i++)
	{
		t = tP->data;
		tL = findlocation(t, L);
		printf("%d ", tL->data);
		tP = tP->next;
	}
	return;
}

linklist *intersection(linklist *L, linklist *P)   //有序表L P交集  A∩B
{
	
	linklist *S = (linklist*)malloc(sizeof(struct linklist));  //最终返回的新链表
	S->next = NULL;                                            //初始化
	L = L->next; P = P->next;//从头节点的下一位开始
	linklist *tl = L;
	while (tl)         //直接遍历表L与P           
	{  
		linklist *tp = P;
		while (tp)
		{ 
			if (L->data == tp->data)            //找到了相等的元素 放入链表S中
				createH(S, L->data);             //头插法插入	
			tp = tp->next;
		}
		tl = tl->next;
	}
	return S;                      //时间复杂度O(N2)?
}
linklist *unionset(linklist *L, linklist *P)   //有序表L P并集
{
	
	linklist *S = (linklist*)malloc(sizeof(struct linklist));
	S = L;
	
	linklist *tP = P->next;
	while (tP)             //遍历P
	{   
		linklist *tL = L->next;
		int flag = 0;
		while (tL&&(!flag))         //遍历L
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

	printf("输入L表长:\n");
	scanf("%d", &Nl); 
	makelistH(L, Nl);               //尾插法建立链表L


	printf("输入P表长:\n");
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