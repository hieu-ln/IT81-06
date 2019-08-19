// BTH2_BT4
#include<iostream>
#include <iomanip>

using namespace std;

//4.1. Khai báo cấu trúc danh sách 

struct Node {
	int info;
	Node*link;
};

Node*first;
//4.2. Viết thủ tục khởi tạo danh sách rỗng. 
void init()
{
	first = NULL;
}

//4.3.Viết thủ tục thêm một phần tử vào danh sách(thêm một phần tử vào vị trí phù hợp trong danh sách đã có thứ tự).Lưu ý : Không xếp thứ tự danh sách.
void Insert_first(int x)
{

	Node*p = new Node;
	p->info = x;
	p->link = first;
	first = p;

}
void Insert_last(int x)
{
	Node*p = new Node;
	p->info = x;
	p->link = NULL;
	if (first == NULL)
	{
		first = p->link;
	}
	else
	{
		Node*q = first;
		while (q->link != NULL)
		{
			q = q->link;
		}
		q->link = p;
	}
}
Node* vtthem(int x)
{
	Node*p = first;
	Node*q = NULL;
	while (p != NULL && p->info < x)
	{
		q = p;
		p = p->link;
	}


	return q;

}
void Insert_condition(int x)
{

	if (x <= first->info)
	{
		Insert_first(x);
	}
	else
	{


		Node* vt = vtthem(x);
		Node*kt = vt->link;
		if (vt->link == NULL)
		{

			Insert_last(x);

		}
		else
		{
			if (kt->link == NULL)
			{
				Insert_last(x);

			}

			else
			{
				Node*p = new Node;

				p->link = first;
				first = p;
				Node*q = first;

				Node*a = new Node;
				a->info = 9;
				while (q != vt)
				{
					a = q->link;
					swap(q->info, a->info);
					q = q->link;
				}

				vt->info = x;
			}
		}
	}

}
//4.4. Viết thủ tục xuất các phần tử trong danh sách. 
void Process_list()
{
	Node* p = first;

	while (p != NULL)
	{
		cout << p->info << setw(4);
		p = p->link;

	}
	cout << endl;
}
//4.5.Viết thủ tục tìm một phần tử trong danh sách(lưu ý : danh sách đã có thứ tự)
Node* Search(int x)
{
	Node*p = first;

	while (p != NULL)
	{
		if (p->info == x)
			return p;
		p = p->link;
	}
	return NULL;
}
//4.6. Viết thủ tục tìm một phần tử trong danh sách. Nếu tìm thấy, xóa phần tử này (Lưu ý: danh sách đã có thứ tự) 
int delete_first()
{
	Node*p = first;
	first = p->link;
	delete p;
	return 1;
}

int delete_last()
{
	Node *p = first;
	Node *q = NULL;
	if (p != NULL)
	{
		while (p != NULL)
		{
			q = p;
			p = p->link;
		}
		if (p != first)
		{
			q->link = NULL;
		}
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}

int search_Delete(int x)
{
	Node* p = first;
	Node* vt = Search(x);

	if (vt == NULL)
	{
		return 0;
	}
	else
	{
		if (vt == first)
		{
			return delete_first();
		}
		else
		{
			if (vt->link == NULL)
				return delete_last();
			else
			{
				Node*q;
				while (p != vt)
				{
					q = p;
					p = p->link;
				}
				q->link = vt->link;
				delete vt;
			}
		}
	}

}

int main()
{
	int n;
	init();
	int gt;
	cout << "nhap so luong phan tu node: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "gt " << i + 1 << " : ";
		cin >> gt;
		if (i == 0)
			Insert_first(gt);
		else
			Insert_last(gt);
	}



	cout << "danh sach vua nhap: \n";
	Process_list();

	int x;
	cout << "\nnhap gia tri x can them: ";
	cin >> x;

	Insert_condition(x);
	Process_list();


	system("pause");
	return 0;

}