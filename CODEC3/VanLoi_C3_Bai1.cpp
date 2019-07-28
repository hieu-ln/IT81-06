//bt01
#include <iostream>
#include <ctime>
using namespace std;

//cau 1.1
#define MAX 3000
int a[MAX], n;

//cau 1.2
void init(int a[], int &n)
{
	cout << "Nhap so luong phan tu danh sach: ";
	cin >> n;
	for(int i = 0; i < n; i++)
		a[i] = rand() % 10000 + 1;
	cout << "Danh sach da duoc tao ngau nhien nhu sau: " << endl;
	for(int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}

void input(int a[], int &n)
{
	cout << "Nhap so luong phan tu danh sach";
	cin >> n;
	cout << "Nhap vao cac phan tu danh sach";
	for(int i = 0; i < n; i++)
	{
		cout << "a[" << i << "] = ";
		cin >> a[i];
	}
}

//cau 1.3
void output(int a[], int n)
{
	for(int i = 0; i< n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}

void copyArray(int a[], int b[], int n)
{
	for(int i = 0; i < n; i++)
		b[i] = a[i];
}

//cau 1.4
void insertionSort(int a[], int n)
{
	int i, key, j;
	for(i = 1; i < n; i++)
	{
		key = a[i];
		j = i - 1;
		while (j >= 0 && a[j] > key)
		{
			a[j + 1] = a[j];
			j = j - 1;
		}
		a[j + 1] = key;
	}
}

// ham hoan doi
void swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}

//Cau 1.5
void SelectionSort(int a[], int n)
{
	int i, j, min_idx;
	for(i = 0; i < n - 1; i++)
	{
		min_idx = i; 
		for(j = i + 1; j < n; j++)
			if(a[j] < a[min_idx])
				min_idx = j;
		swap(a[min_idx], a[i]);
	}
}

// cau 1.6
void interchangeSort(int a[], int n)
{
	for(int i = 0; i < n; i++)
		for(int j = i + 1; j < n; j++)
			if(a[i] > a[j])
				swap(a[i], a[j]);
}

// cau 1.7
void BubbleSort(int a[], int n)
{
	int i, j;
	bool haveSwap = false;
	for(i = 0; i < n; i++)
	{
		haveSwap = false;
		for(j = 0; j < n - i - 1; j++)
		{
			if(a[j] > a[j + 1])
			{
				swap(a[j], a[j + 1]);
				haveSwap = true;
			}
		}
		if(haveSwap == false)
			break;
	}
}

// cau 1.8
int Partition(int a[], int low, int high)
{
	int pivot = a[high];
	int left = low;
	int right = high - 1;
	while (true)
	{
		while(left <= right && a[left] < pivot)
			left++;
		while (right >= left && a[right] > pivot)
			right--;
		if(left >= right)
			break;
		swap(a[left], a[right]);
		left++;
		right--;
	}
	swap(a[left], a[high]);
	return left;
}

void QuickSort(int a[], int low, int high)
{
	if(low < high)
	{
		int pi = Partition(a, low, high);
		QuickSort(a, low, pi - 1);
		QuickSort(a, pi + 1, high);
	}
}

// cau 1.9
void Heapify(int a[], int n, int i)
{
	int largest = i; 
	int l = 2*i + 1;
	int r = 2*i + 2;
	if(l < n && a[l] > a[largest])
		largest = l;
	if(r < n && a[r] > a[largest])
		largest = r;
	if(largest != i)
	{
		swap(a[i], a[largest]);
		Heapify(a, n, largest);
	}
}

void HeapSort(int a[], int n)
{
	for(int i = n/2 - 1; i >= 0; i--)
		Heapify(a, n, i);
	for(int j = n - 1; j >= 0; j--)
	{
		swap(a[0], a[j]);
		Heapify(a, j, 0);
	}
}

// cau 1.10
void SearchSequence(int a[], int n, int x)
{
	int i = 0; 
	while (i < n && a[i] != x)
	{
		i++;
	}
	if(i == n)
	{
		cout << "khong tim thay";
	}
	else
		cout << "Tim thay tai vi tri " << i;
}

// cau 1.11
int searchBinary(int a[], int l, int r, int x)
{
	if(r >= l)
	{
		int mid = l + (r - l) / 2;
		if(a[mid] == x)
			return mid;
		if(a[mid] > x)
			return searchBinary(a, l, mid - 1, x);
		return searchBinary(a, mid + 1, r, x);
	}
	return -1;
}

int main()
{
	int b[MAX];
	clock_t start;
	double duration;
	int choice, x, i;
	cout << "---------BAI TAP CHUONG 3, XEP THU TU  va TIM KIEM ----------" << endl;
	cout << "1. Nhap danh sach" << endl;
	cout << "2. Xuat danh sach" << endl;
	cout << "3. Xep thu tu danh sach bang SELECTION SORT" << endl;
	cout << "4. Xep thu tu danh sach bang INSERTION SORT" << endl;
	cout << "5.Xep thu tu danh sach bang BUBBLE SORT" << endl;
	cout << "6.Xep thu tu danh sach bang INTERCHANGE SORT" << endl;
	cout << "7.Xep thu tu danh sach bang QUICK SORT" << endl;
	cout << "8.Xep thu tu danh sach bang HEAP SORT" << endl;
	cout << "9.Tim kiem phan tu x bang TIM KIEM TUAN TU" << endl;
	cout << "10.Tim kiem phan tu x bang TIM KIEM NHI PHAN" << endl;
	cout << "11.Thoat" << endl;
	do {
		system("cls");
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			init(a, n);
			break;
		case 1:
			input(a, n);
			break;
		case 2:
			cout << "Danh sach la: " << endl;
			output(a, n);
			break;
		case 3:
			copyArray(a, b, n);
			start = clock();
			SelectionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi xep thu tu voi SELECTION SORT la: " << endl;
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian SELECTION SORT: " << duration * 1000000 << " Microseconds" << endl;
			break;
		case 4:
			copyArray(a, b, n);
			start = clock();
			insertionSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi xep thu tu voi INSERTION SORT la: " << endl;
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian INSERTION SORT: " << duration * 1000000 << " Microseconds" << endl;
			break;
		case 5:
			copyArray(a, b, n);
			start = clock();
			BubbleSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "Ds sau khi xep thu tu voi BUBBLE SORT la: " << endl;
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian BUBBLE SORT: " << duration * 1000000 << " Microseconds" << endl;
			break;
		case 6:
			copyArray(a, b, n);
			start = clock();
			interchangeSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi xep thu tu voi INTERCHANGE SORT la: " << endl;
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian INTERCHANGE SORT: " << duration * 1000000 << " Microseconds" << endl;
			break;
		case 7:
			copyArray(a, b, n);
			start = clock();
			QuickSort(b, 0, n - 1);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi xep thu tu voi QUICK SORT la: " << endl;
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian QUICK SORT: " << duration * 1000000 << " Microseconds" << endl;
			break;
		case 8:
			copyArray(a, b, n);
			start = clock();
			HeapSort(b, n);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (n < 100)
			{
				cout << "DS sau khi xep thu tu voi HEAP SORT la: " << endl;
				output(b, n);
			}
			if (duration > 0)
				cout << "Thoi gian HEAP SORT: " << duration * 1000000 << " Microseconds" << endl;
			break;
		case 9:
			cout << "Vui long nhap gia tri x=";
			cin >> x;
			start = clock();
			SearchSequence(a, n, x);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (duration > 0)
				cout << "\n-Thoi gian tim kiem TUAN TU la: " << duration * 1000000 << " Microseconds" << endl;
			break;

		case 10:
			cout << "Vui long nhap gia tri x = ";
			cin >> x;
			start = clock();
			i = searchBinary(b, 0, n, x);
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (i == -1)
				cout << "Khong tim thay x=" << x << " trong day !" << endl;
			else
				cout << "Tim thay x=" << x << " tai vi tri i=" << i << endl;
			if (duration > 0)
				cout << "\nThoi gian tim kiem NHI PHAN la: " << duration * 1000000 << " Microseconds" << endl;
			break;
		case 11:
			cout << "Goodbye...!" << endl;
			break;
		default:
			break;
		}
	} while (choice != 11);
	return 0;
}