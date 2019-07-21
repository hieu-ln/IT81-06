#include <iostream>
using namespace std;
struct node
{
	int info;
	node *link;
};

node *first;

void init()
{
	first = NULL;
}

void process_list()
{
	node *p;
	p = first;
	while (p != NULL)
	{
		cout << p->info << "\t";
		p = p->link;
	}
	cout << endl;
}

node *search(int x)
{
	node *p = first;
	while (p != NULL && p->info != x)
	{
		p = p->link;
	}
	return p;
}

void insert_first(int x)
{
	node *p;
	p = new node;
	p->info = x;
	p->link = first;
	first = p;
}

int delete_first()
{
	if (first != NULL)
	{
		node *p = first;
		first = first->link;
		delete p;
		return 1;
	}
	return 0;
}

void insert_last(int x)
{
	node *p;
	p = new node;
	p->info = x;
	p->link = NULL;
	if (first == NULL)
		first = p;
	else
	{
		node *q = first;
		while (q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}

int delete_last()
{
	if (first != NULL)
	{
		node *p, *q;
		p = first;
		q = first;
		while (p->link != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first)
			q->link = NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}

int searchAndDelete(int x)
{
	if (first != NULL)
	{
		node *p, *q;
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

void swap(node *a, node *b)
{
	int t = a->info;
	a->info = b->info;
	b->info = t;
}

void sort()
{
	node *p, *q, *min;
	p = first;
	while (p != NULL)
	{
		min = p;
		q = p->link;
		while (q != NULL)
		{
			if (q->info<min->info)
				min = q;
			q = q->link;
		}
		swap(min, p);
		p = p->link;
	}
}

int main()
{
	int choice = 0;
	int x, i;
	node *p;
	system("cls");
	cout << "---------- BAI TAP 3, CHUONG 2, DANH SACH LIEN KET DON -----------\n";
	cout << "1/Khoi tao danh sach lien ket rong" << endl;
	cout << "2/Them phan tu vao dau danh sach lien ket don" << endl;
	cout << "3/Them phan tu vao cuoi dslk don" << endl;
	cout << "4/Xoa phan tu o dau dslk don" << endl;
	cout << "5/Xoa phan tu o cuoi dslk don" << endl;
	cout << "6/Xuat dslk don" << endl;
	cout << "7/Tim phan tu voi gia tri x trong dslk don" << endl;
	cout << "8/Tim phan tu voi gia tri x va xoa no neu co" << endl;
	cout << "9/Sap xep dslk don tang dan" << endl;
	cout << "10/Thoat" << endl;
	do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			break;
		case 2:
			cout << "Vui long nhap gia tri x: ";
			cin >> x;
			insert_first(x);
			cout << "Danh sach sau khi them la: ";
			process_list();
			break;
		case 3:
			cout << "Vui long nhap gia tri x: ";
			cin >> x;
			insert_last(x);
			cout << "Danh sach sau khi them la: ";
			process_list();
			break;
		case 4:
			i = delete_first();
			if (i == 0)
				cout << "Danh sach rong, khong the xoa " << x << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu dau tien cua dslk don !" << endl;
				cout << "Danh sach sau khi xoa la: ";
				process_list();
			}
			break;
		case 5:
			i = delete_last();
			if (i == 0)
				cout << "Danh sach rong, khong the xoa " << x << endl;
			else
			{
				cout << "Da xoa thanh cong phan tu cuoi cua dslk don!" << endl;
				process_list();
			}
			break;
		case 6:
			cout << "Danh sach hien tai la: ";
			process_list();
			break;
		case 7:
			cout << "Vui long nhap gia tri can tim x: ";
			cin >> x;
			p = search(x);
			if (p != NULL)
			{
				cout << "Tim thay phan tu co gia tri x=" << x << "!!!" << endl;
			}
			else
				cout << "Khong tim thay phan tu co gia tri x=" << x << "!!!" << endl;
			break;
		case 8:
			cout << "Vui long nhap gia tir can tim x=";
			cin >> x;
			i = searchAndDelete(x);
			if (i == 1)
			{
				cout << "Tim thay x=" << x << " va da xoa thanh cong" << endl;
				cout << "Danh sach sau khi xoa la: ";
				process_list();
			}
			else
				cout << "Khong tim thay phan tu co gia tri x=" << x << " !!!" << endl;
			break;
		case 9:
			sort();
			cout << "Danh sach sau khi sap xep tang dan la: ";
			process_list();
			break;
		case 10:
			cout << "Goodbye ...!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 10);
	system("pause");
	return 0;
}