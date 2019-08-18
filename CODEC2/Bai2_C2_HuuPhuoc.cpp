#include <iostream>
using namespace std;

#define MAX 100
int a[MAX];

int n;

void init(int &n)
{
	do {
		cout << "Nhap so phan tu can dung: ";
		cin >> n;
		if (n <= 0 || n > MAX)
			cout << "Nhap sai. Nhap lai.\n";
	} while (n<=0 || n > MAX);
}

void input(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "] = ";
		cin >> a[i];
	}
}

void output(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

int searchTT(int a[], int n, int x)
{
	int i = 0;
	while (i < n && a[i] != x)
	{
		i++;
	}
	if (i < n)
		return i;
	return -1;
}

void swap(int &a, int &b)
{
	if (a > b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
}

void copy(int a[], int b[])
{
	for (int i = 0; i < n; i++)
		a[i] = b[i];
}

void add(int a[], int &n, int x, int vt)
{
	if (n == MAX)
		cout << "Da du so luong phan tu. Khong the them\n";
	else
	{
		for (int i = n; i >= vt; i--)
		{
			a[i] = a[i-1];
		}
		a[vt] = x;
		cout << "Them thanh cong.\n";
	}
}

void sapxep(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		for(int j = i+1; j < n; j++)
			if (a[i] > a[j])
				swap(a[i], a[j]);
	}
}

int searchBinary(int a[], int n, int x)
{
	int left = 0, right = n - 1, mid;
	sapxep(a, n);
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == x)
		{
			return mid;
		}
		if (a[mid] < x)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

void deleteX(int a[], int &n, int x)
{
	if (searchTT(a, n, x) != -1)
	{
		for (int i = searchTT(a, n, x); i < n; i++)
		{
			a[i] = a[i + 1];
		}
		n--;
		cout << "Xoa thanh cong!!\n";
	}
	else
		cout << "Khong tim thay.\n";
}

void main()
{
	int choice, x, kq;
	cout << "1. Khoi tao danh sach dac.\n";
	cout << "2. Nhap danh sach.\n";
	cout << "3. Xuat danh sach.\n";
	cout << "4. Them 1 phan tu vao danh sach.\n";
	cout << "5. Tim phan tu x (Phuong phap: TIM KIEM TUAN TU).\n";
	cout << "6. Tim phan tu x (Phuong phap: TIM KIEM NHI PHAN).\n";
	cout << "7. Tim phan tu x va xoa phan tu.\n";
	cout << "8. Thoat.\n";
	do {
		cout << "Lua chon cua ban: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			init(n);
			break;
		case 2:
			input(a, n);
			break;
		case 3:
			cout << "----Danh sach cua ban----\n";
			output(a, n);
			break;
		case 4:
			int vt;
			cout << "Nhap phan tu can them: ";
			cin >> x;
			cout << "Nhap vi tri: ";
			cin >> vt;
			if (vt > ++n)
				break;
			else
				add(a, n, x, vt - 1);
			break;
		case 5:
			cout << "Nhap so can tim: ";
			cin >> x;
			kq = searchTT(a, n, x);
			if (kq != -1)
				cout << "Tim thay " << x << " o vi tri (" << kq << ")\n";
			else
				cout << "Khong tim thay " << x << " trong danh sach.\n";
			cout << "-----DO PHUC TAP THUAT TOAN: O(n)------\n";
			break;
		case 6:
			int b[MAX];
			copy(b, a);
			cout << "Nhap so can tim: ";
			cin >> x;
			kq = searchBinary(b, n, x);
			if (kq != -1)
				cout << "Tim thay " << x << " o vi tri (" << kq << ")\n";
			else
				cout << "Khong tim thay " << x << " trong danh sach.\n";
			output(b, n);
			cout << "-----DO PHUC TAP THUAT TOAN: O(log(n))------\n";
			break;
		case 7:
			cout << "Nhap so can tim: ";
			cin >> x;
			deleteX(a, n, x);
			break;
		case 8:
			cout << "---GOODBYE---\n";
			break;
		default:
			break;
		}
	} while (choice != 8);
}