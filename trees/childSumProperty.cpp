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
			//cout << "root->data is " << (*root)->data << endl;
			create(&((*root)->left),n);
		}else if(n > (*root)->data) {
			//cout << "root->data is " << (*root)->data << endl;
			create(&((*root)->right),n);
		}
	}
}
void postorder(node *root)
{
	if(root == NULL) {
		return;
	}else {
		postorder(root->left);
		postorder(root->right);
		cout << root->data << " ";
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
void increment(node **root,int diff)
{
	if((*root)->left != NULL) {
		(*root)->left->data += diff;
		increment(&((*root)->left),diff);
	}else if((*root)->right != NULL) {
		(*root)->right->data += diff;
		increment(&((*root)->right),diff);
	}
}
void childSumProperty(node **root) 
{
	int l = 0;
	int r = 0;
	if((*root) == NULL||((((*root)->right) == NULL && ((*root)->left) == NULL))) {
		return;
	}else {
		childSumProperty(&((*root)->left));
		childSumProperty(&((*root)->right));
		if((*root)->left != NULL) {
			l = (*root)->left->data;
		}
		if((*root)->right != NULL) {
			r = (*root)->right->data;
		}
		int d = (l+r)-((*root)->data);
		if(d > 0) {
			(*root)->data += d;
		}else if(d < 0) {
			increment(root,-d);
		}
	}	
}
int diameter(node *root)
{
	if(root == NULL) {
		return 0;
	}else {
		int lh = height(root->left);
		int rh = height(root->right);
		int ld = diameter(root->left);
		int rd = diameter(root->right);
		return (max(lh+rh+1,max(ld,rd)));
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
	postorder(root);
	cout << "height of tree is " << height(root) << endl;
	levelwise(root,height(root));
	childSumProperty(&root);
	postorder(root);
	cout << "\ndiameter of tree is " << diameter(root) << endl;
	return 0;
}
	

