//Bt4
#include <iostream>
#include <stack>
using namespace std;

#define COUNT 10

// 4-2.1 Khai bao cau truc cay
struct Node {
	int info;
	Node *left, *right;
};

Node *root;

// 4-2.2 Khoi tao cay rong
void initTree()
{
	root = NULL;
}


// 4-2.3 Them mot phan tu vao cay (khong dung de quy)
void insert(int x)
{
	Node *p = root, *q; 
	int flag = 0;
	while (p!=NULL)
	{
		q = p;
		if(p->info == x)
			return;
		else if(p->info > x)
		{
			p= p->left;
			flag = 1;
		}
			
		else
		{
			p= p->right;
			flag = 0;
		}
	}
	p = new Node ;
	p->info = x;
	p->left = p->right = NULL;
	if (root == NULL){
		root = p;
		return ;
	}
	if (flag == 1)
		q->left = p;
	else
		q->right = p;
}

// 4-2.4 Tim phan tu trong cay (khong dung de quy)
Node* search(Node *p,int x){

	while (p != NULL)
	{
		if (p->info == x)
			return p;
		else if (p->info > x)
			p = p->left;
		else
			p = p->right;
	}
	return NULL;
	
}
	
// 4-2.5 Xoa mot node trong cay (dung de quy)
void searchStandFor(Node *&p, Node *&q){

	if (q->left == NULL) {
	
		p->info = q->info;
		p = q;
		q = q->right;
	}
	else
		searchStandFor(p, q->left);
}

int Delete(Node *&T, int x) {

	if (T == NULL)
		return 0;
	if (T->info == x){
	
		Node *p = T;
		if (T->left == NULL) // Bac 1
			T = T->right;
		else if (T->right == NULL) // Bac 1
			T = T->left;
		else // có 2 con
			searchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if (T->info < x)
		return Delete(T->right, x);
	if (T->info > x)
		return Delete(T->left, x);
} 


// 4-2.6 Thu tuc duyet cay theo thu tu LNR (dung STACK)
void inOrder(struct Node *root){
	stack<Node*> s;
	Node *curr = root;

	while (curr != NULL || s.empty() == false){
		while (curr != NULL){
			s.push(curr);
			curr = curr->left;
		}
		curr = s.top();
		s.pop();
		cout << curr->info << " ";
		curr = curr->right;
	}
}

// 4-2.7 Thu tuc duyet cay theo thu tu  NLR (dung STACK)
void preOrder(struct Node *root){
	if (root == NULL)
		return;
	stack<Node *> NodeStack;
	NodeStack.push(root);
	while(NodeStack.empty() == false){
		struct Node *temp_Node = NodeStack.top();
		cout << temp_Node->info << " ";
		NodeStack.pop();
		if (temp_Node->right)
			NodeStack.push(temp_Node->right);
		if (temp_Node->left)
			NodeStack.push(temp_Node->left);
	}
}

// 4-2.8 Thu tuc duyet cay theo thu tu LRN (Dung STACK)

void postorder(Node *root)
{
	stack<Node*> stk;
	stk.push(root);
	stack<int> out;
	while(!stk.empty())
	{
		Node *curr = stk.top();
		stk.pop();
		out.push(curr->info);
		if(curr->left)
			stk.push(curr->left);
		if(curr->right)
			stk.push(curr->right);
	}
	while(!out.empty())
	{
		cout << out.top() << " ";
		out.pop();
	}
}

void print2DUtil(Node *p, int space){
	if (p == NULL)
		return;
	space += COUNT;
	print2DUtil(p->right, space);
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << "\n";

	print2DUtil(p->left, space);
}

void Process_Tree(){
	print2DUtil(root, 0);
}
int main(){
	int choice, x, i;
	Node *p;
	cout << "\n-----> BAI TAP 2 - CHUONG 4 <-----\n";
	cout << "\n0. Khoi tao cay rong !\n";
	cout << "\n1. Them phan tu vao cay \n";
	cout << "\n2. Tim phan tu trong cay \n";
	cout << "\n3. Xoa mot node trong cay\n";
	cout << "\n4. Xuat danh sach\n";
	cout << "\n5. Duyet cay theo LNR\n";
	cout << "\n6. Duyet cay theo NLR\n";
	cout << "\n7. Duyet cay theo LRN\n";
	cout << "\n8. Thoat\n";
	do{
		cout << "\nVui long chon so de thuc hien: "; cin >> choice;
		switch(choice){
			case 0:
				initTree();
				cout << "\nKhoi tao danh sach rong thanh cong !\n";
				break;
			case 1:
				cout << "\nVui long nhap gia tri can them x = "; cin >> x;
				insert(x);
				cout << "\nDanh sach cua cay la: "  << endl;
				Process_Tree();
				break;
			case 2:
				cout << "\nVui long nhap gia tri can tim x = "; cin >> x;
				p = search(root, x);
				if (p != NULL)
					cout << "\nTim thay x = " << x << " trong cay NPTK " << endl;
				else
					cout << "\nKhong tim x = " << x << " trong cay NPTK " << endl;
				break;
			case 3:
				cout << "\nVui long nhap gia tri can xoa x = "; cin >> x;
				i = Delete(root, x);
				if ( i == 0 )
					cout << "\nKhong tim thay x = " << x << " de xoa ! " << endl;
				else
				{
					cout << "\nDa xoa thanh cong phan tu x = " << x << " trong CAY NPTK " << endl;
					cout << "\nCAY NPTK sau khi xoa la: " << endl;
					Process_Tree();
				}

			case 4:
				cout << "\nDanh sach cua Cay NPTK la " << endl;
				Process_Tree();
				break;
			case 5:
				cout << "\nDuyet LNR: ";
				inOrder(root);
				break;
			case 6:
				cout << "\nDuyet NLR: ";
				preOrder(root);
				break;
			case 7:
				cout << "\nDuyet LRN: ";
				postorder(root);
				break;
			case 8:
				cout << "\nGoodbye !!!\n";
				break;
		}
	}while(choice != 8);
	return 0;
}