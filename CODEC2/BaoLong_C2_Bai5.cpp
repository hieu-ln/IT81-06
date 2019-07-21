//Bt5
#include <iostream>
using namespace std;

#define MAX 100
int a[MAX];
int sp;


void khoiTao(int a[], int &sp)
{
	sp = -1;
}

int kiemTraRong(int a[], int sp)
{
	if(sp == -1)
		return 1;
	return 0;
}

int kiemTraDay(int a[], int sp)
{
	if(sp == MAX -1)
		return 1;
	return 0;
}

int them1PhanTu(int a[], int &sp, int x)
{
	if(sp < MAX - 1)
	{
		a[++sp] = x;
		return 1;
	}
	return 0;
}

int xoa1PhanTu(int a[], int &sp, int &x)
{
	if(sp != -1)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}

void xuat(int a[], int sp)
{
	for(int i = sp; i >= 0; i--)
		cout << a[i] << endl;
}

int main()
{
	int chon;
	char tt;
	do{
		system("cls");
		cout << "1.Khoi tao\n2.Kiem tra rong\n3.Kiem tra day\n4.Them mot phan tu\n5.Xoa mot phan tu\n6.Xuat\nBan chon:";
		cin >> chon;
		switch(chon)
		{
		case 1:
			khoiTao(a, sp);
			cout << "Khoi tao thanh cong stack\n";
			break;
		case 2:
			if(kiemTraRong(a, sp))
				cout << "Danh sach stack rong\n";
			else
				cout << "Danh sach stack co phan tu\n";
			break;
		case 3:
			if(kiemTraDay(a, sp))
				cout << "Danh sach stack day\n";
			else
				cout << "Danh sach stack chua  day\n";
			break;
		case 4:
			int x;
			cout << "Mhap gia tri can them vao stack: ";
			cin >> x;
			if(them1PhanTu(a, sp, x))
				cout << "Them thanh cong\n";
			else
				cout << "Them khong thanh cong\n";
			break;
		case 5:
			int y;
			cout << "Nhap gia tri can xoa: ";
			cin >> y;
			if(xoa1PhanTu(a, sp, y))
				cout << "Xoa thanh cong\n";
			else
				cout << "Xoa khong thanh cong\n";
			break;
		case 6:
			cout << "Stack hien tai: " << endl;
			xuat(a, sp);
			break;
		}
		cout << "Ban muon tiep tuc hay ket thuc(Y or N): ";
		cin >> tt;
	}while(tt == 'Y' || tt == 'y');
	return 0;
}