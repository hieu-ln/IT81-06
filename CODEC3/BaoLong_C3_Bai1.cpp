//bt01
#include <iostream>
using namespace std;
#define MAX 100
int a[MAX];
int n;

void nhap(int a[], int n)
{
	for(int i = 0; i < n; i++)
	{
		cout << "Nhap a[" << i << "] :";
		cin >> a[i];
	}
}

void xuat(int a[], int n)
{
	for(int i = 0; i < n; i++)
		cout << a[i] << endl;
}

void InsertionSort(int a[], int n)
{
	int x, i, j;
	for(i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while(0 <= j && x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}

void swap(int &a, int &b)
{
	int c;
	c = a;
	a = b;
	b = c;
}
void SelectionSort(int a[], int n)
{
	int min_pos, i, j;
	for(i = 0; i < n - 1; i++)
	{
		min_pos = i;
		for(j = i + 1; j < n; j++)
			if(a[j] < a[min_pos])
				min_pos = j;
		swap(a[min_pos], a[i]);
	}
}

void BubbleSort(int a[], int n)
{
	for(int i = 0; i < n - 1; i++)
		for(int j = n - 1; j > i; j--)
			if(a[j - 1] > a[j])
				swap(a[j], a[j - 1]);
}

void InterchangeSort(int a[], int n)
{
	for(int i = 0; i < n - 1; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] > a[j])
				swap(a[i], a[j]);
}

void QuickSort(int a[], int left, int right)
{
	int x = a[(left + right) / 2];
	int i = left;
	int j = right;
	while(i < j)
	{
		while(a[i] < x)
			i++;
		while(a[j] > x)
			j--;
		if(i <= j)
		{
			swap(a[i], a[j]);
			i++; 
			j--;
		}
	}
	if(left < j)
		QuickSort(a, left, j);
	if(i < right)
		QuickSort(a, i, right);
}

void shift(int a[], int i, int n)
{
	int j = 2 * i + 1;
	if(j >= n)
		return;
	if(j + 1 < n)
		if(a[j] <  a[j + 1])
			j++;
	if(a[i] >= a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		shift(a, j, n);
	}
}

void HeapSort(int a[], int n)
{
	int i = n / 2;
	while(i >= 0)
	{
		shift(a, i, n - 1);
		i--;
	}
	int right = n - 1;
	while(right > 0)
	{
		swap(a[0], a[right]);
		right--;
		if(right > 0)
			shift(a, 0, right);
	}
}
int Search(int a[], int n, int x)
{
	int i = 0;
	while(i < n && a[i] != x)
		i++;
	if(i < n)
		return i;
	return -1;
}

int BinarySearch(int a[], int n, int x)
{
	int left = 0, right = n - 1, mid;
	while(left <= right)
	{
		mid = (left + right) / 2;
		if(a[mid] == x)
			return mid;
		if(x > a[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return -1;
}

int main()
{
	int chon;
	char tt;
	do{
		cout << "Nhap so luong phan tu danh sach dac: ";
		cin >> n;
		if(n <= 0 || n > MAX)
			cout << "Nhap sai quy dinh so luong phan tu danh sac dac\n";
	} while(n <= 0 || n > MAX);
	int left = 0;
	int right = n - 1;
	do{
		system("cls");
		cout << "1.Nhap danh sach\n2.Xuat danh sach\n3.Sap xep theo InsertionSort\n4.Sap xep theo SelectionSort\n5.Sap xep theo InterchangeSort\n6.Sap xep theo BubbleSort\n7.Sap xep theo QuickSort\n8.Sap xep theo HeapSort\n9.Tim kiem tuan tu\n10.Tim kiem nhi phan\nBan chon: ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			nhap(a, n);
			break;
		case 2:
			cout << "Danh sach dac hien tai la: \n";
			xuat(a, n);
			break;
		case 3:
			InsertionSort(a, n);
			cout << "Danh sach sau khi sap xep tang dan bang phuong phap InsertionSort:\n";
			xuat(a, n);
			break;
		case 4:
			SelectionSort(a, n);
			cout << "Danh sach sau khi sap xep tang dan bang phuong phap SelectionSort:\n";
			xuat(a, n);
			break;
		case 5:
			InterchangeSort(a, n);
			cout << "Danh sach sau khi sap xep tang dan bang phuong phap InterchangeSort:\n";
			xuat(a, n);
			break;
		case 6:
			BubbleSort(a, n);
			cout << "Danh sach sau khi sap xep tang dan bang phuong phap BubbleSort:\n";
			xuat(a, n);
			break;
		case 7:
			QuickSort(a, left, right);
			cout << "Danh sach sau khi sap xep tang dan bang phuong phap QuickSort:\n";
			xuat(a, n);
			break;
		case 8:
			HeapSort(a, n);
			cout << "Danh sach sau khi sap xep tang dan bang phuong phap HeapSort:\n";
			xuat(a, n);
			break;
		case 9:
			int x;
			cout << "Ban muon tim kiem so nao trong danh sac dac: ";
			cin >> x;
			if(Search(a, n, x) == -1)
				cout << " Khong tim thay " << x << " trong danh sach dac " << endl;
			else
				cout << x << " co trong ds va nam o vi tri " << Search(a, n, x) << endl;
			break;
		case 10:
			int y;
			cout << "Ban muon tim kiem so nao trong danh sach dac: ";
			cin >> y;
			if(BinarySearch(a, n, y) == -1)
				cout << "Khong tim thay " << y << " trong danh sach dac " << endl;
			else
				cout << y << " co trong ds va nam o vi tri " << BinarySearch(a, n, y) << endl;
			break;
		}
		cout << "Ban co muon tiep tuc(y/n): ";
		cin >> tt;
	} while(tt == 'y' || tt == 'Y');
	return 0;
}