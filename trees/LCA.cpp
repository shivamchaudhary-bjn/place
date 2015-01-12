#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct node {
	int val;
	struct node *left;
	struct node *right;
}node;
void makeBST(node **root,int n)
{
	if((*root) == NULL) {
		node *temp = (node *)malloc(sizeof(node));
		temp->val = n;
		temp->left = NULL;
		temp->right = NULL;
		(*root) = temp;
	}else {
		if((*root)->val > n) {
			makeBST(&((*root)->left),n);
		}else {
			makeBST(&((*root)->right),n);
		}
	}
}
void LCA(node *root,int a,int b)
{
	while(root != NULL) {
		if(root->val > a && root->val > b) {
			root = root->left;
		}else if(root->val < a && root->val < b) {
			root = root->right;
		}else {
			break;
		}
	}
	cout << "LCA is " << root->val << endl;
}
void print(node *root)
{
	if(root == NULL) {
		return;
	}else {
		print(root->left);
		cout << root->val << " ";
		print(root->right);
	}
}
int main()
{
	node *root = NULL;
	cout << "make the BST\n";
	while(1) {
		int n;
		cin >> n;
		if(n == 999) {
			break;
		}else {
			makeBST(&root,n);
		}
	}
	cout << "Enter the nodes to find LCA\n";
	int a,b;
	cin >> a >> b;
	LCA(root,a,b);
	print(root);
	return 0;
}
