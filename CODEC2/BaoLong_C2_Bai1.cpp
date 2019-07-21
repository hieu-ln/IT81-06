//Bt1
#include <iostream>
using namespace std;
#define MAX 100
int a[MAX];
int n;

void nhap(int a[], int n);
void xuat(int a[], int n);
int timKiem(int a[], int n, int x);
int themCuoi(int a[], int &n, int b);
int xoaCuoi(int a[], int &n);
int xoa(int a[], int &n, int vT);
int timXoa(int a[], int &n, int x);

int main()
{

	int chon;
	char tt;
	do{
		cout << "Nhap so luong phan tu can dung: ";
		cin >> n;
		if(n <= 0 || n > MAX)
			cout << "Nhap sai. Hay nhap lai!\n";
	}while(n <= 0 || n > MAX);
	do{
		system("cls");
		cout << "1.Nhap\n2.Xuat\n3.Tim mot phan tu\n4.Them mot phan tu o cuoi\n5.Xoa mot phan tu o cuoi\n6.Xoa phan tu tai vi tri chi dinh\n7.Tim va xoa mot phan tu\nBan chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			nhap(a, n);
			cout << endl;
			break;
		case 2:
			cout << "Danh sach cac phan tu hien tai: ";
			xuat(a, n);
			cout << endl;
			break;
		case 3:
			int x;
			cout << "Nhap so can tim: ";
			cin >> x;
			if(timKiem(a, n, x) == -1)
				cout << x << " khong co trong danh sach\n";
			else
				cout << x << " co trong danh sach tai vi tri " << timKiem(a, n, x) << endl;
			break;
		case 4:
			int gTThem;
			cout << "Nhap gia tri them cuoi danh sach: ";
			cin >> gTThem;
			if(themCuoi(a, n, gTThem))
			{
				cout << "Danh sach sau khi them: ";
				xuat(a, n);
			}
			else
				cout << "Khong the them cuoi danh sach\n";
			cout << endl;
			break;
		case 5:
			if(xoaCuoi(a, n))
			{
				cout << "Danh sach sau khi xoa mot phan tu o cuoi: ";
				xuat(a, n);
				cout << endl;
			}
			else
				cout << "Khong the xoa\n";
			break;
		case 6:
			int b;
			cout << "Nhap vi tri can xoa: ";
			cin >> b;
			if(xoa(a, n, b))
			{
				cout << "Danh sach sau khi xoa: ";
				xuat(a, n);
				cout << endl;
			}
			else
				cout << "Khong the xoa\n";
			break;
		case 7:
			int c;
			cout << "Nhap gia tri can tim de xoa: ";
			cin >> c;
			if(timXoa(a, n, c))
			{
				cout << "Danh sach sau khi xoa phan tu can tim: ";
				xuat(a, n);
				cout << endl;
			}
			else
				cout << c << " khong co trong danh sach\n";
		}
		break;
		cout << "Ban co muon tiep tuc khong(y/n): ";
		cin >> tt;
	}while(tt == 'Y' || tt == 'y');
	return 0;
}

void nhap(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap phan tu thu " << i + 1 << " : ";
		cin >> a[i];
	}
}

void xuat (int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
}

int timKiem(int a[], int n, int x)
{
	int i = 0;
	while((i < n) && (a[i] != x))
		i++;
	if(i == n)
		return -1;
	return i;
}

int themCuoi(int a[], int &n, int b)
{
	if(n > 0 && n < MAX)
	{
		a[n] = b;
		n++;
		return 1;
	}
	return 0;
}

int xoaCuoi(int a[], int &n)
{
	if(n > 0)
	{
		n--;
		return 1;
	}
	return 0;
}

int xoa(int a[], int &n, int vT)
{
	if(vT >= 0 && vT < n)
	{
		for(int i = vT; i < n - 1; i++)
			a[i] = a[i + 1];
		n--;
		return 1;
	}
	return 0;
}

int timXoa(int a[], int &n, int x)
{
	if(timKiem(a, n, x) == -1)
		return 0;
	if(xoa(a, n, timKiem(a, n, x)))
		return 1;
}