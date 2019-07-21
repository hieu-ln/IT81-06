//Bt3
#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node *link;
};

Node *first;

void khoiTao()
{
	first = NULL;
}


void xuat()
{
	Node *p;
	p = first;
	while(p != NULL)
	{
		cout << p ->info << endl;
		p = p->link;
	}
}

Node *timKiem(int x)
{
	Node *p = first;
	while((p != NULL) && (p->info != x))
		p = p->link;
	return p;
}

void themDau(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = first;
	first = p;
}

int xoaDau()
{
	if(first != NULL)
	{
		Node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

void themCuoi(int x)
{
	Node *p;
	p = new Node;
	p->info = x;
	p->link = NULL;
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

int xoaCuoi()
{
	if(first != NULL)
	{
		Node *p, *q;
		p = first;
		q = NULL;
		if(p != NULL)
			while(p->link != NULL)
			{
				q = p;
				p = p->link;
			}
		if(p != first)
			q->link = NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}

int timVaXoa(int x)
{
	if (first != NULL)
	{
		Node *p, *q;
		p = first;
		q = first;
		while (p->info != x && p->link != NULL)
		{
			p = q;
			p = p->link;
		}
		if (p != first && p->link != NULL)
		{
			if (p->link != NULL)
				q->link = p->link;
			else
				q->link = NULL;
			delete p;
			return 1;
		}
		else if (p == first)
		{
			first = p->link;
			delete p;
			return 1;
		}
		else if (p->link == NULL && p->info == x)
		{
			q->link = NULL;
			delete p;
			return 1;
		}
		else
			return 0;
	}
	return 0;
}

void swap(Node *a, Node *b)
{
	int t = a->info;
	a->info = b->info;
	b->info = t;
}

void sapXepTang()
{
	Node *p, *q, *min;
	p = first;
	while (p != NULL)
	{
		min = p;
		q = p->link;
		while (q != NULL)
		{
			if (q->info < min->info)
				min = q;
			q = q->link;
		}
		swap(min, p);
		p = p->link;
	}
}

int main()
{
	int chon;
	char tt;
	do{
		system("cls");
		cout << "1.Khoi tao\n2.Xuat\n3.Tim mot phan tu\n4.Them mot phan tu o dau\n5.Them mot phan tu o cuoi\n6.Xoa mot phan tu o dau\n7.Xoa mot phan tu o cuoi\n8.Tim va xoa\n9.Sap xep danh sach tang dan\nBan chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			khoiTao();
			cout << "Khoi tao thanh cong\n";
			break;
		case 2:
			cout << "Danh sach cac phan tu hien tai: ";
			xuat();
			cout << endl;
			break;
		case 3:
			int x;
			cout << "Nhap gia can tim: ";
			cin >> x;
			cout << x << " co trong danh sach tai vi tri " << timKiem(x) << endl;
			break;
		case 4:
			int themD;
			cout << "Nhap gia tri them dau danh sach: ";
			cin >> themD;
			themDau(themD);
			cout << "Them dau thanh cong\n";
			break;
		case 5:
			int themC;
			cout << "Nhap gia tri them cuoi danh sach: ";
			cin >> themC;
			themCuoi(themC);
			cout << "Them cuoi thanh cong\n";
			break;
		case 6:
			if(xoaDau())
				cout << "Xoa dau thanh cong\n";
			else
				cout << "Xoa khong thanh cong\n";
			break;
		case 7:
			if(xoaCuoi())
				cout << "Xoa cuoi thanh cong\n";
			else
				cout << "Xoa khong thanh cong\n";
			break;
		case 8:
			int y;
			cout << "Nhap gia tri can tim va xoa: ";
			cin >> y;
			if (timVaXoa(y))
			{
				cout << "Tim thay va xoa thanh cong" << endl;
				cout << "Danh sach sau khi xoa la: " << endl;
				xuat();
			}
			else
				cout << "Khong tim thay phan tu co gia tri x=" << y << " !!!" << endl;
			break;
		case 9:
			sapXepTang();
			cout << "Danh sach sau khi sap xep tang la: " << endl;
			xuat();
			break;
		}
		cout << "Ban co muon tiep tuc khong(y/n): ";
		cin >> tt;
	}while(tt == 'Y' || tt == 'y');
	return 0;
}