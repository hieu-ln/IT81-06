// Bai 2 _ Chuong 2 _ Bai lam them
#include <iostream>
using namespace std;

// 2.1 Khai bao cau truc ds dac
#define MAX 100
int a[MAX];
int n;

// Nhap danh sach
void Input(int a[MAX], int &n)
{
	do{
		cout << "\nNhap so luong phan tu can dung: "; cin >> n;
		if (n <= 0 || n > MAX)
			cout << "\nNhap lai !\n";
	}while(n <= 0 || n > MAX);
	cout << "\nNhap " << n << " phan tu : ";
	for (int i = 0; i < n; i++)
		 cin >> a[i];
}
// 2.2 Them mot phan tu vao ds . Note : Khong xep thu tu ds
void Insert(int a[], int &n, int x, int &vtthem)
{
	for (int i = n - 1; i >= vtthem - 1; i--)
		a[i + 1] = a[i];
	a[vtthem - 1] = x;
	n++;
}
// 2.3 Thu tuc xuat cac phan tu danh sach
void Process(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << "   ";
	cout << endl;
}
// 2.4 Tim kiem tuan tu
int Search(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
		if (x == a[i])
			return i;
	return -1; // Khong tim thay
}
// Hoan doi 
void Swap(int &x, int &y)
{
	int temp = x;
	x = y; 
	y = temp;
}
// Sap xep theo Interchange Sort
void interchangeSort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				Swap(a[i], a[j]);
}
// 2.5 Tim kiem nhi phan
int searchBinary(int a[], int n, int x)
{
	int left = 0, right = n - 1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == x)
			return mid;
		else if (x > a[mid])
				left = mid + 1;
			else
				right = mid - 1;
	}
	return -1;
}
// Ham xoa phan tu tai vi tri i
int Delete_at_i(int a[], int &n, int vtxoa)
{
	if (vtxoa >= 0 && vtxoa < n)
	{
		for (int i = vtxoa; i < n - 1; i++)
			a[i] = a[i + 1];
		n--;
		return 1;
	}
	return 0;
}
// 2.5 Tim phan tu va xoa (neu co)
int search_Delete(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
		if (x == a[i])
			Delete_at_i(a, n, i);
				return 1;
	return 0;
}
int main()
{
	int x, vtthem, choice, i, kq;
	do{
		cout << "\n----->	BAI TAP CHUONG 2 - BAI TAP THEM (DS DAC)	<-----\n";
		cout << "\n1. Nhap danh sach\n";
		cout << "\n2. Xuat danh sach\n";
		cout << "\n3. Them phan tu vao vi tri phu hop trong DS\n";
		cout << "\n4. Tim kiem tuan tu\n";
		cout << "\n5. Tim kiem nhi phan\n";
		cout << "\n6. Tim kiem phan tu va xoa (neu co phan tu nay)\n";
		cout << "\n7. Thoat\n";
		cout << "\nBan chon: "; cin >> choice;
		switch(choice)
		{
			case 1:
				Input(a, n);
				break;
			case 2:
				cout << "\nDanh sach hien tai la: " << endl;
				Process(a, n);
				break;
			case 3:
				do{
					cout << "\nVui long nhap vi tri can them: "; cin >> vtthem;
					if (vtthem <= 0 || vtthem > n + 1)
						cout << "\nNhap lai !\n";
				}while(vtthem <= 0 || vtthem > n + 1);
				cout << "\nVui long nhap gia tri x = "; cin >> x;
				Insert(a, n, x, vtthem);
				cout << "\nDanh sach sau khi them la: " << endl;
				Process(a, n);
				break;
			case 4: 
				cout << "\nVui long nhap phan tu can tim x = " ; cin >> x;
				i = Search(a, n, x);
				if (i == -1)
					cout << "\nKhong tim thay phan tu " << x << " trong danh sach !\n";
				else
					cout << "\nPhan tu " << x << " tim thay trong danh sach tai vi tri " << i << endl;
				break;
			case 5:
				interchangeSort(a, n);
				cout << "\nDanh sach da duoc sap xep de tim kiem nhi phan !\n";
				cout << "\nVui long nhap phan tu can tim x = "; cin >> x;
				i = searchBinary(a, n, x);
				if (i == -1)
					cout << "\nKhong tim thay phan tu " << x << " trong danh sach !\n";
				else
					cout << "\nPhan tu " << x << " tim thay trong danh sach tai vi tri " << i << endl;
				break;
			case 6:
				cout << "\nNhap mot phan tu x = "; cin >> x;
				kq = search_Delete(a, n, x);
				if (kq == 1)
				{
					cout << "\nDanh sach da tim thay phan tu " << x << endl;
					cout << "\nDanh sach sau khi xoa la: " << endl;
					Process(a, n);
				}
				else
					cout << "\nKhong tim thay phan tu " << x << " trong danh sach\n";
				break;
			case 7:
				cout << endl;
				cout << "Ban chon thoat. Tam biet\n";
				break;
		}
	}while(choice != 7);
	return 0;
}