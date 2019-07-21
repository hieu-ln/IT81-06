//Bt10;
#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node *link;
};

Node *sp;   

void init()
{
	sp = NULL;
}

int isEmpty()
{
	if(sp == NULL)
		return 1;
	return 0;
}

void Push(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = sp;
	sp = p;
}

int Pop(int &x)
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

int convert(int tp)
{
	init();
	while(tp != 0)
	{
		int d = tp % 2;
		Push(d);
		tp /= 2;
	}
	int np = 0;
	while(!isEmpty())
	{
		int so;
		if(Pop(so))
			np = np * 10 + so;
	}
	return np;
}

int main()
{
	int chon;
	char tt;
	do{
		system("cls");
		cout << "1.Khoi tao\n2.Kiem tra rong\n3.Them mot phan tu\n4.Xoa mot phan tu\n5.Chuyen he thap phan sang nhi phan\nBan chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			init();
			cout << "Khoi tao thanh cong\n";
			break;
		case 2:
			if(isEmpty())
				cout << "Danh sach rong\n";
			else
				cout << "Danh sach co phan tu\n";
			break;
		case 3:
			int x;
			cout << "Nhap gia tri phan tu can them: ";
			cin >> x;
			Push(x);
			cout << "Them thanh con\n";
			break;
		case 4:
			int y;
			if(Pop(y))
				cout << "Xoa thanh cong\n";
			else
				cout << "Xoa khong thanh cong\n";
			break;
		case 5:
			int tp;
			cout << "Nhap gia tri thap phan can chuyen doi: ";
			cin >> tp;
			cout << "Gia tri nhi phan tuong ung la: " << convert(tp) << endl;
			break;
		}
		cout << "Ban muon tiep tuc hay ket thuc(Y or N): ";
		cin >> tt;
	}while(tt == 'Y' || tt == 'y');
	return 0;
}