#include<iostream>
#include<cstdlib>
using namespace std;
int cnt = 0;
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
int level1(node *root,int level)
{
	if(root == NULL) {
		return 0;
	}else if(level == 1) {
		return 1;
	}else if(level > 1) {
		return (level1(root->left,level-1)+level1(root->right,level-1));
	}
}
void levelwise(node *root,int height)
{
	int mx;
	for(int i = 1;i <= height;i++) {
		if(i == 1) {
			mx = level1(root,i);
		}else {
			if(level1(root,i) > mx) {
				mx = level1(root,i);
			}
		}
	}
	cout << "maximum width of tree is " << mx << endl;
}
void kth_smallest(node *root,int k)
{
	if(root == NULL) {
		return;
	}else {
		kth_smallest(root->left,k);
		cnt++;
		if(cnt == k) {
			cout << root->data << endl;
		}
		kth_smallest(root->right,k);
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
	cout << "kth element \n";
	int k;
	cin >> k;
	kth_smallest(root,k);
	doubleTree(&root);
	inorder(root);
	cout << endl;
	//levelwise(root,height(root));
	return 0;
}
	

