#include <iostream>
#include<stdio.h>

using namespace std;
#define MAX 100
 //cau 1.1

int a[MAX];
int n;

//cau1.2
void input(int a[], int &n)
{
	cout << "Nhap so phan tu cua danh sach: ";
	cin >> n;
	cout << "Nhap cac phan tu cua danh sach: ";
	for (int i = 0; i<n; i++)
	{
		cout << "a[" << i + 1 << "]";
		cin >> a[i];
	}
}

//1.3
void output(int a[], int n)
{
	for (int i = 0; i<n; i++)
		cout << a[i] << "\t";
	cout << endl;
}

//1.4
int search(int a[], int n, int x)
{
	for (int i = 0; i<n; i++)
	{
		if (a[i] == x)
			return i;
	}
	return -1;
}

//1.5
int insert_last(int a[], int &n, int x)
{
	if (n<MAX)
	{
		a[n] = x;
		n++;
		return 1;
	}
	else
		return 0;
}

//1.6
int delete_last(int a[], int &n)
{
	if (n>0)
	{
		n--;
		return 1;
	}
	return 0;
}

//1.7
int Delete(int a[], int &n, int i)
{
	if (i >= 0 && i<n)
	{
		for (int j = i; j<n - 1; j++)
			a[j] = a[j + 1];
		n--;
		return 1;
	}
	return 0;
}

//1.8
int searchAndDelete(int a[], int &n, int x)
{
	for (int i = 0; i<n; i++)
	{
		if (a[i] == x)
		{
			Delete(a, n, i);
			return 1;
		}
	}
	return 0;
}

int main()
{
	int choice = 0;
	int x, i;
	system("cls");
	cout << "----------- BAI TAP 1,	CHUONG 1, DANH SACH DAC ------------" << endl;
	cout << "1/Nhap danh sach" << endl;
	cout << "2/Xuat danh sach" << endl;
	cout << "3/Tim phan tu co gia tri x trong danh sach" << endl;
	cout << "4/Them phan tu vao cuoi danh sach" << endl;
	cout << "5/Xoa phan tu cuoi danh sach" << endl;
	cout << "6/Xoa phan tu tai vi tri i" << endl;
	cout << "7/Tim phan tu voi gia tri x va xoa neu co" << endl;
	cout << "8/Thoat" << endl;
	do
	{
		cout << "Vui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			input(a, n);
			cout << "Ban vua nhap danh sach thanh cong!\n";
			break;
		case 2:
			cout << "Danh sach da nhap la: \n";
			output(a, n);
			break;
		case 3:
			cout << "nhap phan tu x can tim: ";
			cin >> x;
			i = search(a, n, x);
			if (i == -1)
				cout << "khong tim thay phan tu x trong danh sach!\n";
			else
				cout << "tim thay phan tu x trong danh sach tai vi tri i=" << i << endl;
		case 4:
			cout << "Vui long nhap x can them vao cuoi ds: ";
			cin >> x;
			i = insert_last(a, n, x);
			if (i == 0)
				cout << "Danh sach da day, khong the them! " << x << endl;
			else
			{
				cout << "Da them phan tu x= " << x << " vao cuoi danh sach!" << endl;
				cout << "Ds sau khi them la: \n";
				output(a, n);
			}
			break;
		case 5:
			i = delete_last(a, n);
			if (i>0)
			{
				cout << "Xoa thanh cong !" << endl;
				cout << "Danh sach sau khi xoa phan tu cuoi la: \n";
				output(a, n);
			}
			else
				cout << "Danh sach dang rong, khong co phan tu nao!!!" << endl;
		case 6:
			cout << "Vui long nhap vi tri can xoa i=";
			cin >> i;
			i = Delete(a, n, i);
			if (i == 1)
			{
				cout << "Xoa thanh cong !" << endl;
				cout << "Danh sach sau khi xoa la:\n";
				output(a, n);
			}
			else
				cout << "Khong co phan tu nao de xoa!!!" << endl;
			break;
		case 7:
			cout << "Vui long nhap gia tri can xoa x=";
			cin >> x;
			i = searchAndDelete(a, n, x);
			if (i == 1)
			{
				cout << "Xoa thanh cong phan tu co gia tri x=" << x << endl;
				cout << "Danh sach sau khi xoa la: \n";
				output(a, n);
			}
			else
				cout << "Khong co phan tu nao de xoa!!!" << endl;
			break;
		case 8:
			cout << "\nGoodBye!";
			break;
		default:
			break;
		}
	} while (choice != 8);
	system("pause");
	return 0;
}