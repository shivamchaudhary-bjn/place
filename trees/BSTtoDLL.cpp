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
node* treeFromtraversal(int pre[],int post[],int l,int r,int *index,int size)
{
	if(*index >= size || l > r) {
		return NULL;
	}
	node *temp = (node *)malloc(sizeof(node));
	temp->data = pre[*index];
	++*index;
	temp->left = NULL;
	temp->right = NULL;
	node *root = temp;
	//cout << "root is " << root->data << endl;
	if(l == r) {
		//cout << "return is " << root->data << endl;
		return root;
	}
	int i;
	for(i = l;i < r;i++) {
		if(pre[*index] == post[i])
		break;
	}
	cout << "i is " << i << endl;
	if(i < r) {
		root->left =  treeFromtraversal(pre,post,l,i,index,size);
		root->right =  treeFromtraversal(pre,post,i+1,r,index,size);
	}
	return root;
}
void bstTodll(node **head,node **tail,node *root)
{
	if(root == NULL) {
		return;
	}else {
		bstTodll(head,tail,root->left);
		root->left = *tail;	
		if(*tail == NULL) {
			*head = root;
		}else {
			(*tail)->right = root;
		}
		(*tail) = root;
		bstTodll(head,tail,root->right);
	}
}
bool Ispresent(node *head,node *tail,int sum)
{
	cout << head->data << " " << tail->data << endl;
	while(head != tail) {
		if(head->data + tail->data  == sum) {
			return true;
		}else if(head->data + tail->data > sum) {
			//cout << "left\n";
			tail = tail->left;
		}else if(head->data + tail->data < sum) {
			//cout << "right\n";
			head = head->right;
		}
		cout << head->data << " " << tail->data << endl;
	}
	return false;
}
bool Istriple(node *head,node *tail)
{
	while(head->right != tail && head->data < 0) {
		//cout << head->right->data << " " << tail->data << " == " << head->data << endl;
		if(Ispresent(head->right,tail,-1*head->data)) {
			return true;
		}else {
			head = head->right;
		}
	}
	return false;
}
void print(node *head)
{
	while(head != NULL) {
		cout << head->data << " ";
		head = head->right;
	}
}
int main()
{
	node *root = NULL;
	node *head = NULL;
	node *tail = NULL;
	int path[100];
	//int pre[9] = {1,2,4,8,9,5,3,6,7};
	//int post[9] = {8,9,4,5,2,6,7,3,1};
	//int index = 0;
	//node *root = treeFromtraversal(pre,post,0,8,&index,9);
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
	bstTodll(&head,&tail,root);
	print(head);
	cout << endl;
	if(Istriple(head,tail)) {
		cout << "YES\n";
	}else {
		cout << "NO\n";
	}
	/*cout << "height of tree is " << height(root) << endl;
	levelwise(root,height(root));
	rootToleafPath(root,path,0);
	cout << "enter the key whose ancestor needs to be find\n";
	int key;
	cin >> key;
	int ancestor[100];
	print_ancestor(root,ancestor,key,0);
	cout << "enter the range in which nodes should lies\n";
	int k1,k2;
	cin >> k1 >> k2;
	print_between(root,k1,k2);
	cout << "mirror of tree\n";
	mirror(&root);
	inorder(root);*/
	return 0;
}
	

