#include<iostream>
#include<cstdlib>
#include<stack>
using namespace std;
typedef struct node {
	int data;
	struct node *left;
	struct node *right;
}node;
void create(node ** root,int n)
{
	node *temp;
	if(*(root) == NULL) {
		temp = (node *)malloc(sizeof(node));
		temp->data = n;
		temp->left = NULL;
		temp->right = NULL;
		(*root) = temp;
	}else {
		if(n <= (*root)->data) {
			//cout << "root->data is " << (*root)->data << endl;
			create(&((*root)->left),n);
		}else if(n > (*root)->data) {
			//cout << "root->data is " << (*root)->data << endl;
			create(&((*root)->right),n);
		}
	}
}
void inorder(node *root)
{
	if(root == NULL) {
		return;
	}else {
		inorder(root->left);
		cout << root->data << " ";
		inorder(root->right);
	}
}
void travera(node *root)
{
	stack<int> s;
	node *current = root;
	while(1) {
		if(current != NULL) {
			s.push(current->data);
			cout << current->data << " ";
			current = current->left;
		}else {
			if(!s.empty()) {
				cout << s.top() << " ";
				s.pop();
				current = current->right;
			}else {
				break;
			}
		}
	}
}
int main()
{
	node *root = NULL;
	while(1) {
		int n;
		cin >> n;
		if(n == 999) {
			break;
		}else {
			create(&root,n);
		}
	}
	//inorder(root);
	travera(root);
	return 0;
}
	

