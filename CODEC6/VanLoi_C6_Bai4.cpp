//bt4
#include <iostream>
#include <fstream>
using namespace std;

#define MAX 100
int a[MAX][MAX];
int n;
char vertex[MAX];
//khai bao tap E
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0;
//khai bao tap T
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0;

void initGrath()
{
	n = 0;
}

void inputGrath()
{
	cout << "Nhap so dinh cho do thi: ";
	cin >>  n;
	for(int i = 0; i < n; i++)
	{
		cout << "Nhap ten dinh: ";
		cin >> vertex[i];
		cout << "Nhap trong so cho dong thu " << i + 1 << ": ";
		for(int j = 0; j < n; j++)
			cin >> a[i][j] ;
	}
}

void inputGrathFromFile()
{
	ifstream inFile;
	inFile.open("MT.txt");
	if(inFile.is_open())
	{
		inFile >> n;
		for(int i = 0; i < n; i ++)
			inFile >> vertex[i];
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				inFile >> a[i][j];
		cout << "Doc du lieu thanh cong\n";
		inFile.close();
	}
	else
		cout << "Mo file that bai\n";
}

void outputGrath()
{
	//xuat dong tieu de
	cout << " | "; // (1)
	for(int i = 0; i < n; i++)
		cout << vertex[i] << " ";
	cout << endl;
	for(int i = 1; i <= 3 + n + n; i++) //3 la so ki tu  va khoang trang (1)
		cout << "-";
	cout << endl;
	for(int i = 0; i < n; i++)
	{
		cout << vertex[i] << "| ";
		for(int j = 0; j < n; j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}


void XoaViTriE(int i)
{
	for(int j = i; j < nE; j++)
	{
		E1[j] = E1[j + 1];
		E2[j] = E2[j + 1];
		wE[j] = wE[j + 1];
	}
	nE--;
}

void XoaCanhE(int u, int v)
{
	for(int i = 0; i < nE; i++)
		if(E1[i] == u && E2[i] == v)
		{
			XoaViTriE(i);
			break;
		}
}

int TonTai(int d, int D[],int nD)
{
	for(int i = 0; i < nD; i ++)
		if(D[i] == d)
			return 1;
	return 0;
}

void prim(int s)
{
	int u = s, min, i, d1, d2;
	while(nT < n - 1)
	{
		for(int v = 0; v < n; v++)
			if(a[u][v] != 0)
				if(TonTai(v, T2, nT) == 0)
				{
					E1[nE] = u;
					E2[nE] = v;
					wE[nE] = a[u][v];
					nE++;
				}
		for(i = 0; i < nE; i++)
			if(TonTai(E2[i], T2, nT) == 0)
			{
				min = wE[i];
				d1 = E1[i];
				d2 = E2[i];
				break;
			}
		for(i = 0; i < nE; i++)
			if(TonTai(E2[i], T2, nT) == 0)
				if(min > wE[i])
				{
					min = wE[i];
					d1 = E1[i];
					d2 = E2[i];
				}
		T1[nT] = d1;
		T2[nT] = d2;
		wT[nT] = a[d1][d2];
		a[d1][d2] = 0;
		a[d2][d1] = 0;
		nT++;
		XoaCanhE(d1, d2);
		u = d2;
	}
}

void output()
{
	int tong = 0;
	for(int i = 0; i < nT; i++)
	{
		cout << endl << "(" << T1[i] << "," << T2[i] << ") = " << wT[i];
		tong += wT[i];
	}
	cout << "\n Tong trong so cay khung toi thieu = " << tong << endl;
}


int main()
{
	int chon;
	char tt;
	do{
		system("cls");
		cout << "1. Khoi tao ma tran trong so\n"
			<< "2. Nhap ma tran trong so\n"
			<< "3. Nhap ma tran trong so bang file\n"
			<< "4. Xuat ma tran trog so\n"
			<< "5. Tinh tong trong so cua cay khung toi thieu bang thuat giai Prim\n"
			<< "Ban chon : ";
		cin >> chon;
		switch(chon)
		{
		case 1:
			initGrath();
			cout << "Khoi tao thanh cong ma tran trong so\n";
			break;
		case 2:
			inputGrath();
			break;
		case 3:
			inputGrathFromFile();
			break;
		case 4:
			cout << "Ma tran trong so cua do thi: " << endl;
			outputGrath();
			break;
		case 5:
			int x;
			cout << "Nhap dinh bat dau: ";
			cin >> x;
			prim(x);
			output();
			break;
		}
		cout << "Ban co muon tiet tuc khong(y/n): ";
		cin >> tt;
	}while(tt == 'y' || tt == 'Y');
	return 0;
}