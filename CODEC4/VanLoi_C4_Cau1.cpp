//Bt1
#include <iostream>
using namespace std;
#define COUNT 10

struct Node
{
	int info;
	Node *left;
	Node *right;
};

Node *root;

void tree_empty()
{
	root = NULL;
}

void InsertNode(Node *&p, int x)
{
	if(p == NULL)
	{
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if(p->info == x)
			return;
		else
			if(p->info > x)
				return InsertNode(p->left, x);
			else
				return InsertNode(p->right, x);
	}
}

int intsert_Node1(Node *p, int x)  //Them khong can dia chi
{
	if(p->info == x)
		return 0;
	else
	{
		if(p->info > x)
		{
			if(p->left == NULL)
			{
				Node *y = new Node;
				y->info = x;
				y->left = NULL;
				y->right = NULL;
				p->left = y;
				return 1;
			}
			else
				return intsert_Node1(p->left, x);
		}
		else
		{
			if(p->right == NULL)
			{
				Node *y = new Node;
				y->info = x;
				y->left = NULL;
				y->right = NULL;
				p->right = y;
				return 1;
			}
			else
				return intsert_Node1(p->right, x);
		}
	}
}

void print(Node *p, int space)
{
	if(p == NULL)
		return;
	space += COUNT;
	print(p->right, space);
	cout << endl;
	for(int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << endl;
	print(p->left, space);
}

void Process_print() //xuat
{
	print(root, 0);
}

Node *search(Node *p, int x)
{
	if(p != NULL)
	{
		if(p->info == x)
			return p;
		else
			if(x > p->info)
				return search(p->right, x);
			else
				return search(p->left, x);
	}
	return NULL;
}

void searchStandFor(Node *&p, Node *&q)
{
	if(q->left == NULL)
	{
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		searchStandFor(p, q->left);
}

int Delete(Node *&T, int x)
{
	if(T == NULL)
		return 0;
	if(T->info == x)
	{
		Node *p = T;
		if(T->left == NULL)
			T = T->right;
		else
			if(T->right == NULL)
				T = T->left;
			else
				searchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if(T->info < x)
		return Delete(T->right, x);
	if(T->info > x)
		return Delete(T->left, x);
}

void duyetLNR(Node *p)
{
	if(p != NULL)
	{
		duyetLNR(p->left);
		cout << p->info << " ";
		duyetLNR(p->right);
	}
}

void duyetNLR(Node *p)
{
	if(p != NULL)
	{
		cout << p->info << " ";
		duyetLNR(p->left);
		duyetLNR(p->right);
	}
}

void duyetLRN(Node *p)
{
	if(p != NULL)
	{
		duyetLNR(p->left);
		duyetLNR(p->right);
		cout << p->info << " ";
	}
}

int main()
{
	int chon;
	char tt;
	do{
		system("cls");
		cout << "MENU: " << endl;
		cout << "1.Khoi tao cay rong\n"
			<< "2.Them mot phan tu vao cay\n"
			<< "3.Xuat cay\n"
			<< "4.Tim mot phan tu trong cay\n"
			<< "5.Xoa mot nut trong cay\n"
			<< "6.Duyet cay theo thu tu NLR\n"
			<< "7.Duyet cay theo thu tu LNR\n"
			<< "8.Duyet cay theo thu tu LRN\n"
			<< "Ban chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			tree_empty();
			cout << "Khoi tao thanh cong\n";
			break;
		case 2:
			int x;
			cout << "Nhap gia tri can them vao cay: ";
			cin >> x;
			InsertNode(root, x);
			cout << "Them thanh cong\n";
			break;
		case 3:
			cout << "Cay nhi phan hien tai la: ";
			Process_print();
			break;
		case 4:
			int y;
			cout << "Nhap gia tri can tim trong cay: ";
			cin >> y;
			if(search(root, y))
				cout << y << " co trong cay\n";
			else
				cout << y << " khong ton tai trong cay\n";
			break;
		case 5:
			int e;
			cout << "Nhap gia tri can xoa trong cay: ";
			cin >> e;
			if(Delete(root, e))
				cout << "Xoa thành cong\n";
			else
				cout << "Xóa khong thanh cong\n";
			break;
		case 6:
			cout << "Cay nhi phan duyet theo thu tu NLR: ";
			duyetNLR(root);
			cout << endl;
			break;
		case 7:
			cout << "Cay nhi phan duyet theo thu tu LNR: ";
			duyetLNR(root);
			cout << endl;
			break;
		case 8:
			cout << "Cay nhi phan duyet theo thu tu LRN: ";
			duyetLRN(root);
			cout << endl;
			break;
		}
		cout << "Ban co muon tiep tuc(y/n): ";
		cin >> tt;
	}while(tt == 'Y' || tt == 'y');
	return 0;
}