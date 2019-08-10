//bt1
#include <iostream>
#include <stdio.h>
using namespace std;

#define MAX 20
int a[MAX][MAX];
int n;
char vertex[MAX];

///DSLK su dung cho STACK va QUEUE
struct Node {
	int info;
	Node *link;
};

Node *sp;
Node *front, *rear;

///STACK
void InitStack()
{
	sp = NULL;
}

int isEmptyS()
{
	if(sp == NULL)
		return 1;
	return 0;
}

void PushS(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

int PopS(int &x)
{
	if(sp != NULL)
	{
		Node *p = sp;
		x = p->info;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

///QUEUE
void InitQueue()
{
	front = NULL;
	rear = NULL;
}

int isEmptyQ()
{
	if(front == NULL)
		return 1;
	return 0;
}

void PushQ(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if(rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}

int PopQ(int &x)
{
	if(front != NULL)
	{
		Node *p = front;
		front = p->link;
		x = p->info;
		if(front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}
///GRAPH
void init()
{
	n = 0;
}

void input()
{
	cout << "Nhap so dinh cua do thi: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for(int i = 0; i < n; i++)
		cin >> vertex[i];
	for(int i = 0; i < n; i++)
	{
		cout << "Nhap vao dong thu " << i + 1 << " : ";
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}

void outputGraph()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << a[i][i] << " ";
		cout << endl;
	}
}

void output(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
	cout << endl;
}

//Duyet theo chieu rong BFS(su dung QUEUE)
int c[100];
int bfs[100];
int nbfs = 0;

void initC()
{
	for(int i = 0; i < n; i++)
		c[i] = 1;
}

void BFS(int v)
{
	int w, p;
	PushQ(v);
	c[v] = 0;
	while(front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for(w = 0; w < n; w++)
			if(c[w] && a[p][w] == 1)
			{
				PushQ(w);
				c[w] = 0;
			}
	}
}

///Duyet do thi theo chieu sau DFS(su dung STACK)
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	c[s] = 0;
	int v = -1, u = s;
	while(!isEmptyS())
	{
		if(v == n)
			PopS(u);
		for(v = 0; v < n; v++)
			if(a[u][v] != 0 && c[v] == 1)
			{
				PushS(u);
				PushS(v);
				dfs[ndfs] = v;
				ndfs++;
				c[v] = 0;
				u = v;
				break;
			}
	}
}

//Dung BFS tim x tren do thi
void Search_by_BFS(int x, int v)
{
	int w, p;
	PushQ(v);
	c[v] = 0;
	while(front != NULL)
	{
		PopQ(p);
		if(x == p)
		{
			cout << "Tim thay x = " << x << endl;
			return;
		}
		for(w = 0; w < n; w++)
			if(c[w] && a[p][w] == 1)
			{
				PushQ(w);
				c[w] = 0;
			}
	}
}


int main()
{
	int chon;
	char tt;
	do{
		system("cls");
		cout << "1. Khoi tao ma tran ke rong\n";
		cout << "2. Nhap ma tran ke\n";
		cout << "3. Xuat ma tran ke\n";
		cout << "4. Duyet do thi theo chieu rong(BFS)\n";
		cout << "5. Duyet do thi theo chieu sau(DFS)\n";
		cout << "6. Tim dinh co gia tri x theo BFS\n";
		cout << "Ban chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			init();
			cout << "Khoi tao ma tran ke rong thanh cong!\n";
			break;
		case 2:
			input();
			break;
		case 3:
			cout << "Xuat ma tran ke hien tai: \n";
			outputGraph();
			break;
		case 4:
			InitQueue();
			initC();
			int k;
			cout << "Vui long nhap dinh bat dau: ";
			cin >> k;
			nbfs = 0;
			BFS(k);
			cout << "Thu tu dinh sau khi duyet DFS: " << endl;
			output(bfs, n);
			break;
		case 5:
			InitStack();
			initC();
			int l;
			cout << "Vui long nhap dinh bat dau: ";
			cin >> l;
			ndfs = 0;
			DFS(k);
			cout << "Thu tu dinh sau khi duyet DFS: " << endl;
			output(dfs, n);
			break;
		case 6:
			InitQueue();
			initC();
			int m;
			cout << "vui long nhap gia tri x  can tim: ";
			cin >> m;
			Search_by_BFS(m, 0);
			break;
		}
		cout << "Ban co muon tiep tuc: ";
		cin >> tt;
	} while(tt == 'y' || tt == 'Y');
	return 0;
}
