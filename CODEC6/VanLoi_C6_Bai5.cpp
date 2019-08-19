//bt5
 #include <iostream>
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

int TonTai(int d, int D[],int nD)
{
	for(int i = 0; i < nD; i ++)
		if(D[i] == d)
			return 1;
	return 0;
}

void kruskal()
{
	for(int i = 0; i < nE; i++)
	{
		if(TonTai(E1[i], T1, nT) == 1 && TonTai(E2[i], T2, nT) == 1)
			continue;
		if(TonTai(E1[i], T2, nT) == 1 && TonTai(E2[i], T1, nT) == 1)
			continue;
		T1[nT] = E1[i];
		T2[nT] = E2[i];
		wT[nT] = wE[i];
		nT++;
		if(nT == n - 1)
			break;
	}
}

void taoE()
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(a[i][j] != 0)
			{
				E1[nE] = i;
				E2[nE] = j;
				wE[nE] = a[i][j];
				a[i][j] = 0;
				a[j][i] = 0;
				nE++;
			}
}

void swap(int &a, int &b)
{
	int tam = a;
	a = b;
	b = tam;
}

void SapXepE()
{
	for(int i = 0; i < nE - 1; i++)
		for(int j = i + 1; j < nE; j++)
			if(wE[i] > wE[j])
			{
				swap(wE[i], wE[j]);
				swap(E1[i], E1[j]);
				swap(E2[i], E2[j]);
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
	cout << "\n Tong = " << tong << endl;
}

int main()
{
	int chon;
	char tt;
	do{
		system("cls");
		cout << "1. Khoi tao ma tran trong so\n"
			<< "2. Nhap ma tran trong so\n"
			<< "3. Xuat ma tran trog so\n"
			<< "4. Tim cay khung toi thieu bang thuat giai Kruskal\n"
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
			cout << "Ma tran trong so cua do thi: " << endl;
			outputGrath();
			break;
		case 4:
			cout << "Cay khung toi thieu bang thuat giai Kruskal: " << endl;
			taoE();
			SapXepE();
			kruskal();
			output();
			break;
		}
		cout << "Ban co muon tiet tuc khong(y/n): ";
		cin >> tt;
	}while(tt == 'y' || tt == 'Y');
	return 0;
}