// Bai 5+6 chuong 6
#include<iostream>
#include<iomanip>
#include<stdio.h>
#include<fstream>
using namespace std;

// Khai bao ma tran mang hai chieu 
#define MAX 20
int a[MAX][MAX];
int n; // So dinh cua do thi 
char vertex[MAX];// Ten dinh
void initGraph()
{
	n = 0;
}
void inputGraphFromText()
{
	string line;
	ifstream myfile("matrantrongso2.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i<n; i++)
			myfile >> vertex[i];
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<n; j++)
				myfile >> a[i][j];

		}
	}
}
//Nhap ma tran ke cua do thi
void inputGraph()
{
	cout << " Nhap so dinh cua do thi : ";
	cin >> n;
	for (int i = 0; i<n; i++)
	{
		cout << " Nhap ten dinh : ";
		cin >> vertex[i];
		cout << " Nhap vao dong thu  " << i + 1 << " : ";
		for (int j = 0; j<n; i++)
		{
			cin >> a[i][j];
		}
	}
}
// Xuat ma tran ke cua do thi
void outputGraph()
{
	cout << setw(6) << left;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<n; j++)
			cout << a[i][j] << setw(6) << left;
		cout << endl;
	}
}
//Khai bao TapE
int E1[MAX];
int E2[MAX];
int wT[MAX];
int nE = 0;//So phan tu cua E

//Khai bao TapE
int T1[MAX];
int T2[MAX];
int wE[MAX];
int nT = 0;//So phan tu cua T

void TaoE()
{
	for (int i = 0; i<n; i++)
	for (int j = 0; j<n; j++)
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
int tonTai(int E, int T[], int nT)
{
	for (int i = 0; i<nT; i++)
	{
		if (E == T[i])
			return 1;
	}
	return 0;
}
void sapXepE()
{
	for (int i = 0; i<nE - 1; i++)
	for (int j = i + 1; j<nE; j++)
	if (wE[i]>wE[j])
	{
		swap(wE[i], wE[j]);
		swap(E1[i], E1[j]);
		swap(E2[i], E2[j]);

	}
}
void kruskal()
{
	for (int i = 0; i<nE; i++)
	{
		if (tonTai(E1[i], T1, nT) == 1 && tonTai(E2[i], T2, nT) == 1)
			continue;
		if (tonTai(E1[i], T2, nT) == 1 && tonTai(E2[i], T1, nT) == 1)
			continue;
		T1[nT] = E1[i];
		T2[nT] = E2[i];
		wT[nT] = wE[i];
		nT++;
		if (nT == n - 1)
			break;
	}
}
void output(bool vertexName)
{
	int tong = 0;
	for (int i = 0; i<nT; i++)
	{
		if (vertexName)
			cout << endl << "(" << vertex[T1[i]] << "," << vertex[T2[i]] << ") =" << wT[i];
		else
			cout << endl << "(" << T1[i] << "," << T2[i] << ")=" << wT[i];
		tong += wT[i];
	}
	cout << "\n Tong =" << tong;
}
int main()
{
	int choice, x, i;
	system("cls");
	cout << " Bai tap 5 chuong 6 tim kiem cay khung toi tieu, kruskal " << endl;
	cout << " 1.Khoi tao ma tran ke rong " << endl;
	cout << " 2.Nhap ma tran ke tu file text " << endl;
	cout << " 3.Nhap ma tran ke " << endl;
	cout << " 4.Xuat ma tran ke " << endl;
	cout << " 5. Xuat cay khung toi tieu bang Kruskal " << endl;
	cout << " 6.Thoat " << endl;
	do{
		cout << "\n Vui long chon so de thuc hien : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			initGraph();
			cout << " Ban vua khoi tao ma tran ke thanh cong ! \n ";
			break;
		case 2:
			inputGraphFromText();
			cout << " Ban vua nhap ma tran ke tu file : \n";
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			TaoE();
			sapXepE();
			kruskal();
			cout << " Cay khung toi tieu voi Kruskal : " << endl;
			output(true);
			break;
		case 6:
			cout << " Goodbye ... " << endl;
			break;
		default:
			break;
		}
	} while (choice != 6);
	return 0;
}