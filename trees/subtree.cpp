#include<iostream>
#include<cstdlib>
#include<queue>
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
void mirror(node ** root)
{
	if(*root == NULL) {
		return;
	}else {
		mirror(&((*root)->left));
		mirror(&((*root)->right));
		node * temp;
		temp = (*root)->left;
		(*root)->left = (*root)->right;
		(*root)->right = temp;
	}
}
void rootToleafPath(node * root,int path[],int length)
{
	if(root == NULL) {
		return;
	}else {
		path[length] = root->data;
		length++;
		if(root->left == NULL && root->right == NULL) {
			for(int i = 0;i < length;i++) {
				cout << path[i] << " ";
			}
			cout << endl;
		}else {
			rootToleafPath(root->left,path,length);
			rootToleafPath(root->right,path,length);
		}
	}
}
void print_ancestor(node *root,int ancestor[],int key,int length)
{
	if(root == NULL) {
		return;
	}else {
		if(root->data == key) {
			for(int i = 0;i < length;i++) {
				cout << ancestor[i] << " ";
			}
			cout << endl;
			return;
		}else {
			ancestor[length] = root->data;
			length++;
			print_ancestor(root->left,ancestor,key,length);
			print_ancestor(root->right,ancestor,key,length);
		}
	}
}
void print_between(node *root,int k1,int k2)
{
	if(root == NULL)  {
		return;
	}else if(root->data >= k1 && root->data <= k2) {
		print_between(root->left,k1,k2);
		cout << root->data << " ";
		print_between(root->right,k1,k2);
	}else {
		if(root->data < k1) {
			print_between(root->right,k1,k2);
		}else if(root->data > k2){
			print_between(root->left,k1,k2);
		}
	}
}
bool IsSubtree(node *a,node *b)
{
	if(a == NULL && b == NULL) {
		return true;
	}
	if(a == NULL || b == NULL) {
		return false;
	}
	return ((a->data == b->data) && IsSubtree(a->left,b->left) && IsSubtree(a->right,b->right));
}
bool subtree(node *root,node *root1)
{
	if(root1 == NULL) {
		return true;
	}
	if(root == NULL) {
		return false;
	}
	if(IsSubtree(root1,root)) {
		return true;
	}
	return (subtree(root1,root->left) || subtree(root1,root->right));
}
void postorder_withoutRecursion(node *root)
{
	stack<node *> s;
	node *current = root;
	s.push(current);

	while(!s.empty()) {
		node *p = s.top();
		//cout << "push is " << p->data << endl;
		if(p != NULL) {
			if(p->left == NULL && p->right == NULL) {
				cout << p->data << " ";
				s.pop();
			}else {
				s.push(NULL);
				if(p->left) s.push(p->right);
				if(p->right) s.push(p->left);
			}
		}else {
			s.pop();
			cout << s.top()->data << " ";
			s.pop();
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
int main()
{
	node *root = NULL;
	node *root1 = NULL;
	int path[100];
	cout << "first tree \n";
	while(1) {
		int n;
		cin >> n;
		if(n == 999) {
			break;
		}else {
			create(&root,n);
		}
	}
	/*cout << "second tree\n";
	while(1) {
		int n;
		cin >> n;
		if(n == 999) {
			break;
		}else {
			create(&root1,n);
		}
	}
	inorder(root);
	cout << "height of tree is " << height(root) << endl;
	levelwise(root,height(root));
	rootToleafPath(root,path,0);
	if(subtree(root,root1)) {
		cout << "Yes\n";
	}else {
		cout << "No\n";
	}*/
	postorder(root);
	cout << endl;
	postorder_withoutRecursion(root);
	cout << endl;
	return 0;
}
	

