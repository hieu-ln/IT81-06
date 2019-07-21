     //bt12
#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node *next;
	Node *previous;
};

Node *first, *last;

void init()
{
	first = NULL;
	last = NULL;
}

void Process_list()
{
	Node *p;
	p = first;
	while(p != NULL)
	{
		cout << p->info << endl;
		p = p->next;
	}
}

void Insert_last()
{
	Node *p;
	p = last;
	while(p != NULL)
	{
		cout << p->info << endl;
		p = p->previous;
	}
}

void Insert_first(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->previous = NULL;
	p->next = first;
	if(first != NULL)
		first->previous = p;
	else
		last = p;
	first = p;
}

void Insert_last(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->next = NULL;
	p->previous = last;
	if(last != NULL)
		last->next = p;
	else
		first = p;
	last = p;
}

int Delete_first()
{
	if(first != NULL)
	{
		Node *p = first;
		first = first->next;
		delete p;
		if(first != NULL)
			first->previous = NULL;
		else
			last = NULL;
		return 1;
	}
	return 0;
}

int Delete_last()
{
	if(last != NULL)
	{
		Node *p = last;
		last = last->previous;
		if(last != NULL)
			last->next = NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}

Node *Search(int x)
{
	Node *p;
	p = first;
	while((p != NULL) && (p->info != x))
		p = p->next;
	return p;
}

int del(int x)
{
	Node *p = Search(x);
	if(p != NULL)
	{
		if(p == first)
		{
			if(Delete_first())
				return 1;
			else
				return 0;
		}
		else
			if(p == last)
			{
				if(Delete_last())
					return 1;
				else
					return 0;
			}
			else
			{
				Node *q;
				q = p->previous;
				q->next = p->next;
				(p->next)->previous = q;
				delete p;
				return 1;
			}
	}
	return 0;
}

int main()
{
	int chon;
	char tt;
	do{
		system("cls");
		cout << "1.Khoi tao\n2.Xuat cac phan tu\n3.Them mot phan tu vao dau\n4.Them mot phan tu vao cuoi\n5.Xoa phan tu dau\n6.Xoa phan tu cuoi\n7.Tim kiem va xoa\nBan chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			init();
			cout << "Khoi tao thanh cong\n";
			break;
		case 2:
			cout << "Cac phan tu trong danh sach hien tai la: " << endl;
			Process_list();
			break;
		case 3:
			int x;
			cout << "Nhap gia tri phan tu can them dau: ";
			cin >> x;
			Insert_first(x);
			cout << "Them thanh cong\n";
			break;
		case 4:
			int y;
			cout << "Nhap gia tri phan tu can them cuoi: ";
			cin >> y;
			Insert_last(y);
			cout << "Them thanh cong\n";
			break;
		case 5:
			if(Delete_first())
				cout << "Xoa dau thanh cong\n";
			else
				cout << "Xoa dau khong thanh cong\n";
			break;
		case 6:
			if(Delete_last())
				cout << "Xoa cuoi thanh cong\n";
			else
				cout << "Xoa cuoi khong thanh cong\n";
			break;
		case 7:
			int e;
			cout << "Nhap gia tri phan tu can tim de xoa: ";
			cin >> e;
			if(del(e))
				cout << "Tim va xoa thanh cong\n";
			else
				cout << "Tim va xoa khong thanh cong\n";
			break;
		}
		cout << "Ban co muon tiep tuc(y/n): ";
		cin >> tt;
	}while(tt == 'Y' || tt == 'y');
	return 0;
}