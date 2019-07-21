//Bt11
#include <stdio.h>
#include <iostream>
using namespace std;
//11.1: Khao bao cau truc queue
struct Node{
	int info;
	Node *link;
};

Node *front, *rear;


//11.2: Khoi tao queue rong
void init(){
	front = NULL;
	rear = NULL;
}

//11.3: Kiem tra queue rong
int isEmpty(){
	if (front == NULL)
		return 1;
	return 0;
}

//11.4: Them phan tu vao queue
void Push(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}

//11.5:Lay phan tu ra khoi queue
int Pop(int &x)
{
	if (front != NULL)
	{
		Node *p = front;
		front = p->link;
		x = p->info;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

//Xuat queue
void Process_queue()
{
	if (front != NULL)
	{
		Node *p = front;
		cout << "<-- ";
		do{
			cout << p->info << "\t";
			p = p->link;
		} while (p != NULL);
		cout << "<--" << endl;
	}
}

int main()
{
	int choice, x, i;
	system("cls");
	cout << "-------- BAI TAP 7, CHUONG 2, QUEUE (HANG DOI - DSLK) --------" << endl;
	cout << "1.Khoi tao queue rong" << endl;
	cout << "2.Them phan tu vao queue" << endl;
	cout << "3.Lay phan tu ra khoi queue" << endl;
	cout << "4.Kiem tra queue co rong hay khong" << endl;
	cout << "5.Xuat queue" << endl;
	cout << "6.Thoat" << endl;
	do{
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init();
			cout << "Ban vua khoi tao queue rong thanh cong!\n";
			break;
		case 2:
			cout << "Vui long nhap gia tri x=";
			cin >> x;
			Push(x);
			cout << "Queue sau khi them la: ";
			Process_queue();
			break;
		case 3:
			Pop(x);
			cout << "Phan tu lay ra tu Queue la x=" << x << endl;
			cout << "Queue sau khi lay ra la: ";
			Process_queue();
			break;
		case 4:
			i = isEmpty();
			if (i == 0)
				cout << "Queue khong rong! (" << x << ")" << endl;
			else
				cout << "Queue rong!" << endl;
			break;
		case 5:
			cout << "Queue hien tai la: ";
			Process_queue();
			break;
		case 6:
			cout << "Goodbye .......!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 6);
	return 0;
}