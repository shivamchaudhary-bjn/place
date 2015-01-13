#include<iostream>
#include<cstdlib>
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
			create(&((*root)->left),n);
		}else if(n > (*root)->data) {
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
		cout << "The value of root is " << root->data << " ";
		inorder(root->right);
	}
}
int height(node *root)
{
	if(root == NULL) {
		return 0;
	}else {
		int l = height(root->left);
		int r = height(root->right);
		if(l > r) {
			return l+1;
		}else {
			return r+1;
		}
	}
}
void level1(node *root,int level)
{
	if(root == NULL) {
		return;
	}else if(level == 1) {
		cout << root->data << " ";
	}else if(level > 1) {
		level1(root->left,level-1);
		level1(root->right,level-1);
	}
}
void levelwise(node *root,int height)
{
	for(int i = 1;i <= height;i++) {
		level1(root,i);
		cout << endl;
	}
}
void doubleTree(node **root)
{
	if((*root) == NULL) {
		return;
	}else if((*root)->left == NULL && (*root)->right == NULL) {
		node *temp = (node*)malloc(sizeof(node));
		temp->data = (*root)->data;
		temp->left = NULL;
		temp->right = NULL;
		(*root)->left = temp;
	}else {
		doubleTree(&((*root)->left));
		doubleTree(&((*root)->right));
		node *current = (*root)->left;
		node *temp1 = (node*)malloc(sizeof(node));
		temp1->data = (*root)->data;
		temp1->right = NULL;
		temp1->left = current;
		(*root)->left = temp1;
	}
}
int main()
{
	node *root = NULL;
	int path[100];
	while(1) {
		int n;
		cin >> n;
		if(n == 999) {
			break;
		}else {
			create(&root,n);
		}
	}
	inorder(root);
	cout << endl;
	levelwise(root,height(root));
	doubleTree(&root);
	inorder(root);
	cout << endl;
	levelwise(root,height(root));
	return 0;
}
	

