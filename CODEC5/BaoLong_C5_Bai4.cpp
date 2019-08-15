//bt2
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
using namespace std;
#define MAX 20

struct Node
{
	int info;
	Node *link;
};

Node *First[MAX];
int n;
char vertex[MAX];

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

///end QUEUE

void initGraph()
{
	n = 0;
}

void InsertLast(Node *&first, Node *p)
{
	if(first == NULL)
		first = p;
	else
	{
		Node *q = first;
		while(q->link != NULL)
			q = q->link;
		q->link = p;
	}
}

void inputGraphFromText()
{
	string line;
	ifstream myfile ("danhsachke1.txt");
	if(myfile.is_open())
	{
		myfile >> n;
		for(int i = 0; i < n; i++)
			myfile >> vertex[i];
		string str;
		int i = 0;
		while(getline(myfile, str))
		{
			istringstream ss(str);
			int u;
			while(ss >> u)
			{
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				InsertLast(First[i - 1], p);
			}
			i++;
		}
		cout << i;
	}
}

void inputGraph()
{
	cout << "Nhap so dinh do thi n: ";
	cin >> n;
	cout << "Nhap ten dinh: ";
	for(int i = 0; i < n; i++)
		cin >> vertex[i];
	for(int i = 0; i < n + 1; i++)
	{
		if(i > 0)
			cout << "Nhap DSK cua dinh thu " << i - 1 << " (" << vertex[i - 1] << "): ";
		int u;
		string str;
		while(getline(cin, str))
		{
			istringstream ss(str);
			while(ss >> u)
			{
				Node *p = new Node;
				p->info = u;
				p->link = NULL;
				InsertLast(First[i - 1], p);
			}
			break;
		}
	}
}

void outputGraph()
{
	for(int i = 0; i < n; i++)
	{
		cout << "Dinh " << i << " (" << vertex[i] << "): ";
		Node *p = First[i];
		while(p != NULL)
		{
			cout << p->info << "  ";
			p = p->link;
		}
		cout << endl;
	}
}

void output(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout << vertex[a[i]] << " ";
	cout << endl;
}

//BFS
int c[100], bfs[100];
int nbfs = 0;

void InitC()
{
	for(int i = 0; i < n; i++)
		c[i] = 1;
}

void BFS(int v)
{
	int p;
	Node *w;
	PushQ(v);
	c[v] = 0;
	while(front != NULL)
	{
		PopQ(p);
		bfs[nbfs] = p;
		w = First[p];
		nbfs++;
		while(w != NULL)
		{
			if(c[w->info])
			{
				PushQ(w->info);
				c[w->info] = 0;
			}
			w = w->link;
		}
	}
}

//DFS
int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs] = s;
	ndfs++;
	c[s] = 0;
	int  u = s;
	Node *v = NULL;
	while(isEmptyS() == 0)
	{
		if(v == NULL)
			PopS(u);
		v = First[u];
		while(v != NULL)
		{
			if(c[v->info] == 1)
			{
				PushS(u);
				PushS(v ->info);
				dfs[ndfs] = v->info;
				ndfs++;
				c[v->info] = 0;
				u = v->info;
				break;
			}
			v = v->link;
		}
	}
}

void Search_by_BFS(int x, int v)
{
	int p;
	Node *w;
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
		w = First[p];
		while(w != NULL)
		{
			if(c[w->info])
			{
				PushQ(w->info);
				c[w->info] = 0;
			}
			w = w->link;
		}
	}
}

int main()
{
	int chon;
	char tt;
	do{
		system("cls");
		cout << "1. Khoi tao danh sach ke rong\n";
		cout << "2. Nhap danh sach ke\n";
		cout << "3. Nhap danh sach ke tu file txt\n";
		cout << "4. Xuat danh sach ke\n";
		cout << "5. Duyet do thi theo chieu rong(BFS)\n";
		cout << "6. Duyet do thi theo chieu sau(DFS)\n";
		cout << "7. Tim dinh co gia tri x theo BFS\n";
		cout << "Ban chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			initGraph();
			cout << "Khoi tao danh sach ke rong thanh cong!\n";
			break;
		case 2:
			inputGraph();
			break;
		case 3:
			cout << "Ban vua nhap danh sach ke tu file: \n";
			inputGraphFromText();
			break;
		case 4:
			cout << "Xuat danh sach ke hien tai: \n";
			outputGraph();
			break;
		case 5:
			InitQueue();
			InitC();
			int k;
			cout << "Vui long nhap dinh bat dau: ";
			cin >> k;
			nbfs = 0;
			BFS(k);
			cout << "Thu tu dinh sau khi duyet DFS: " << endl;
			output(bfs, n);
			break;
		case 6:
			InitStack();
			InitC();
			int l;
			cout << "Vui long nhap dinh bat dau: ";
			cin >> l;
			ndfs = 0;
			DFS(k);
			cout << "Thu tu dinh sau khi duyet DFS: " << endl;
			output(dfs, n);
			break;
		case 7:
			InitQueue();
			InitC();
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