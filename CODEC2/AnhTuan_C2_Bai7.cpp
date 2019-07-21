 //Bt7
#include <iostream>
using namespace std;
#define MAX 100
int a[MAX];
int front, rear;

void init(int a[], int &front, int &rear)
{
	front = -1;
	rear = -1;
}

int kTRong()
{
	if(front == NULL)
		return 1;
	return 0;
}

int kTDay()
{
	if(rear - front == MAX - 1)
		return 1;
	return 0;
}

int them1PT(int a[], int &front, int &rear, int x)
{
	if(rear - front == MAX - 1)
		return 0;
	else
	{
		if(front == -1)
			front = 0;
		if(rear == MAX - 1)
		{
			for(int i = front; i <= rear; i++)
				a[i - front] = a[i];
			rear = MAX - 1 - front;
			front = 0;
		}
		a[++rear] = x;
		return 1;
	}
}

int xoa1PT(int a[], int &front, int &rear, int &x)
{
	if(front == -1)
		return 0;
	else
	{
		x = a[front++];
		if(front > rear)
		{
			front = -1;
			rear = -1;
		}
		return 1;
	}
}

void xuat(int a[], int front, int rear)
{
	for(int i = front; i <= rear; i++)
		cout << a[i] << endl;
}

int main()
{
	int chon;
	char tt;
	do{
		system("cls");
		cout << "1.Khoi tao\n2.Kiem tra rong\n3.Kiem tra day\n4.Them mot phan tu\n5.Xoa mot phan tu\n6.Xuat\nBan chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			init(a, front, rear);
			cout << "Khoi tao thanh cong queue\n";
			break;
		case 2:
			if(kTRong())
				cout << "Danh sach rong\n";
			else
				cout << "Danh sach co phan tu\n";
			break;
		case 3:
			if(kTDay())
				cout << "Danh sach day\n";
			else
				cout << "Danh sach chua day\n";
			break;
		case 4:
			int x;
			cout << "Nhap gia tri phan tu can them: ";
			cin >> x;
			if(them1PT(a, front, rear, x))
				cout << "Them thanh cong\n";
			else
				cout << "Khong them duoc\n";
			break;
		case 5:
			int y;
			cout << "Nhap gia tri can xoa: ";
			cin >> y;
			if(xoa1PT(a, front, rear, x))
				cout << "Xoa thanh cong\n";
			else
				cout << "Xoa khong thanh cong\n";
			break;
		case 6:
			cout << "Danh sach hien tai la: " << endl;
			xuat(a, front, rear);
		}
		cout << "Ban muon tiep tuc hay ket thuc(Y or N): ";
		cin >> tt;
	}while(tt == 'Y' || tt == 'y');
	return 0;
}