#include <stdio.h>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std ;

// khai bao ma tran bang mang hai chieu
#define MAX 20
int a[MAX][MAX];
int n; // so dinh cua do thi
char vertex[MAX]; // ten dinh

void InitGraph()
{
	n = 0;
}

void inputGraphFromText()
{
	string line;
	ifstream myfile("do_thi_1.txt");
	if(myfile.is_open())
	{
		myfile >> n;
		for(int i = 0; i< n; i++)
			myfile >> vertex[i];
		for(int i =0; i < n; i++)
		{
			for(int j = 0; j < n; j++)
				myfile >> a[i][j];
		}
	}
}

// nhap ma tran ke cua do thi
void inputGraph()
{
	cout << "nhap so dinh do thi n: " ;
	cin >> n ;
	cout << "Nhap ten dinh: ";
	for(int i = 0; i < n; i++)
		cin >> vertex[i] ;
	for(int i = 0; i < n; i++)
	{
		cout << "Nhap vao dong thu " << i + 1 << ": " ;
		for(int j = 0; j < n; j++)
			cin >> a[i][j];
	}
}

// xuat ma tran ke cua do thi
void outputGraph()
{
	cout << setw(6) << left;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << a[i][j] << setw(6) << left;
		cout << endl ;
	}
}

// khai bao Tap E
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0; // so phan tu tap E

// khai bao Tap T
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT=0; // so phan tu tap T

// Prim & Kruskal
int TonTai(int d, int D[], int nD)
{
	for(int i = 0; i < nD; i++)
		if(D[i] == d)
			return 1;
	return 0 ;
}

// begin Prim
void XoaViTriE(int i)
{
	for(int j = i; j < nE; j++)
	{
		E1[j] = E1[j + 1];
		E2[j] = E2[j + 1] ;
		wE[j] = wE[j + 1];
	}
	nE--;
}

void XoaCanhE(int u, int v)
{
	for(int i = 0; i < nE; i++)
		if(E1[i] == u&&E2[i] == v)
		{
			XoaViTriE(i);
			break;
		}
}

void prim(int s) // s la dinh bat dau
{
	int u = s, min, i, d1, d2;
	while(nT < n - 1)
	{
		for(int v = 0; v < n; v++)
			if(a[u][v]!=0)
				if(TonTai(v, T2, nT) == 0)
				{
					E1[nE] = u;
					E2[nE] = v;
					wE[nE] = a[u][v];
					nE++;
				}
		for(i = 0; i < nE; i++)
			if(TonTai(E2[i], T2, nT)==0)
			{
				min=wE[i];
				d1=E1[i];
				d2=E2[i];
				break;
			}
		for(; i<nE;i++)
			if(TonTai(E2[i], T2, nT)==0)
				if(min > wE[i])
				{
					min=wE[i];
					d1=E1[i];
					d2=E2[i];
				}
		T1[nT]=d1;
		T2[nT]=d2;
		wT[nT]=a[d1][d2];
		a[d1][d2]=0;
		a[d2][d1]=0;
		nT++;
		XoaCanhE(d1,d2);
		u=d2;
	}
}

// end Prim

// begin Kruskal
void swap(int &a, int &b)
{
	int c = a;
	a = b;
	b = c;
}

void taoE()
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (a[i][j] != 0)
			{
				E1[nE] = i;
				E2[nE] = j;
				wE[nE] = a[i][j];
				a[i][j] = 0;
				a[j][i] = 0;
				nE++;
			}
}

void sapXepE()
{
	for (int i = 0; i < nE - 1; i++)
		for (int j = i + 1; j < nE; j++)
			if (wE[i] > wE[j])
			{
				swap(wE[i], wE[j]);
				swap(E1[i], E1[j]);
				swap(E2[i], E2[j]);
			}
}

void kruskal()
{
	for (int i = 0; i < nE; i++)
	{
		if (TonTai(E1[i], T1, nT) == 1 && TonTai(E2[i], T2, nT) == 1)
			continue;
		if (TonTai(E1[i], T2, nT) == 1 && TonTai(E2[i], T1, nT) == 1)
			continue;
		T1[nT] = E1[i];
		T2[nT] = E2[i];
		wT[nT] = wE[i];
		nT++;
		if (nT == n - 1)
			break;
	}
}
// end Kruskal

void output(bool VertexName)
{
	int tong = 0;
	for(int i = 0; i < nT; i++)
	{
		if(VertexName)
			cout << endl << "(" << vertex[T1[i]] << "," << vertex[T2[i]] << ") = " << wT[i];
		else
			cout << endl << "(" << T1[i] << "," << T2[i] << ") = " << wT[i];
		tong+=wT[i];
	}
	cout << "\n Tong = " << tong;
}

int main()
{
	int choice, x, i;
	system("cls");
	cout << "\n ---------- BAI TAP 4, CHUONG 6, TIM KIEM CAY KHUNG TOI THIEU, PRIM ----------" << endl;
	cout << "\n1. Khoi tao MA TRAN KE rong" << endl;
	cout << "\n2. Nhap MA TRAN KE tu file text" << endl;
	cout << "\n3. Nhap MA TRAN KE" << endl;
	cout << "\n4. Xuat MA TRAN KE" << endl;
	cout << "\n5. Tim CAY KHUNG TOI THIEU bang PRIM " << endl ;
	cout << "\n6. Tim CAY KHUNG TOI THIEU bang KRUSKAL " << endl ;
	cout << "\n7. Tim CAY KHUNG TOI THIEU bang KRUSKAL Cai Tien " << endl ;
	cout << "\n8. Thoat" << endl ;
	do{
		cout << "\nVui long chon so de thuc hien: " ;
		cin >> choice ;
		switch(choice)
		{
			case 1:
				InitGraph();
				cout << "\nBan vua khoi tao MA TRAN KE rong thanh cong! " << endl;
				break ;
			case 2:
				inputGraphFromText();
				cout << "\nBan vua nhap MA TRAN KE tu file: " << endl;
				outputGraph();
				break ;
			case 3:
				inputGraph();
				break;
			case 4:
				cout << endl;
				outputGraph();
				break;
			case 5:
				cout << "\nVui long nhap dinh xuat phat: " ;
				cin >> x ;
				prim(x) ;
				cout << "\nCay khung toi thieu voi PRIM: " << endl ;
				output(true);
				break;
			case 6:
				taoE();
				sapXepE();
				kruskal();
				cout << "\nCay khung toi thieu bang KRUSKAL " << endl;
				output(true);
				break;
			case 7:
				sapXepE();
				taoE();
				kruskal();
				cout << "\nCay khung toi thieu bang KRUSKAL Cai Tien " << endl;
				output(true);
				break;
			case 8:
				cout << "\nTam biet\n";
				break;
		}
	} while(choice != 8);
	return 0 ;
}