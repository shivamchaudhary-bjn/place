#include<iostream>
#include<cstdlib>
#include<queue>
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
void level1(node *root,int level,int v)
{
	if(root == NULL) {
		return;
	}else if(level == 1) {
		cout << root->data << " ";
		return;
	}else if(level > 1) {
		if(v%2 == 0) {
			level1(root->left,level-1,v);
			level1(root->right,level-1,v);
		}else {
			level1(root->right,level-1,v);
			level1(root->left,level-1,v);
		}
	}
}
void levelwise(node *root,int height)
{
	for(int i = 1;i <= height;i++) {
		level1(root,i,i);
		cout << endl;
	}
}
int main()
{
	queue<int> q;
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
	cout << "height of tree is " << height(root) << endl;
	levelwise(root,height(root));
	//q.push(root->data);
	//spiralPath(root,&q,0);
	return 0;
}
	

