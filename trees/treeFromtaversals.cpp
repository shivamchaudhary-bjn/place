#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
using namespace std;
typedef struct node
{
	char c;
	struct node *left;
	struct node *right;
}node;
int search(char t,string u)
{
	int k = 0;
	while(u[k] != t) {
		k++;
	}
	return k;
}
void make(node **root,string s,string path[])
{
	//node *temp,*head,*temp1;
	
	node *temp;
	//cout << "sdfhsdkf\n";
	for(int i = 0;i < 6;i++) {
		//char p = s[i];
		//cout << "pt " << path[i] << endl;
		if(i == 0) {
			//cout << "as\n";
			temp = (node *)malloc(sizeof(node));
			temp->c = s[i];
			temp->left = NULL;
			temp->right = NULL;
			(*root) = temp;
			//cout << (temp)->c << endl;
		}else {
			node *head;
			head = *root;
			int k = 0;
			//cout << "path " << path[i] << endl;
			while(k < path[i].length()-1) {
				if(path[i][k] == '0') {
					head = head->left;
				}else {
					head = head->right;
				}
				k++;
			}
			//cout << path[i][k] << endl;
			node *temp1;
			temp1 = (node *)malloc(sizeof(node));
			temp1->c = s[i];
			temp1->left = NULL;
			temp1->right = NULL;
			if(path[i][k] == '0') {
				head->left = temp1;
			}else {
				head->right = temp1;
			}
			//cout << head->c;
		}
	}
	//cout << endl;
}
void inor(node *root)
{
	if(root == NULL) {
		return;
	}else {
		inor(root->left);
		cout << root->c << " ";
		inor(root->right);
	}
}
int main()
{
	node *root = NULL;
	//int inorder[6],preorder[6];
	string inorder,preorder;
	cout << "enter inorder traversal\n";
	//for(int i = 0;i < 6;i++) {
		cin >> inorder;
	//}
	cout << "enter preorder traversal\n";
	//for(int i = 0;i < 6;i++) {
		cin >> preorder;
	//}
	int n = 6;
	string path[6];
	int flag[100] = {0};
	
	for(int i = 0;i < n;i++) {
		int p = search(preorder[i],inorder);
		if(i == 0) path[p] += '2';
		flag[p] = 1;
		int j = 0;
		//cout << p << endl;
		//cout << preorder[i] << endl;
		while(j < p) {
			if(flag[j] == 0) {
				path[j] += '0';
			}
			j++;
			//cout << path[j] << " ";
		}
		j = p+1;
		while(j < n) {
			if(flag[j] == 0) {
				path[j] += '1';
				j++;
			}else {
				break;
			}
			//cout << path[j] << " ";
		}
	}
	string path1[6];
	for(int i = 0;i < 6;i++) {
		int u = search(preorder[i],inorder);
		path1[i] = path[u];
	}
	make(&root,preorder,path1);
	inor(root);
	//cout << root->left->c << root->right->c << endl;
	cout << endl;
	/*for(int i = 0;i < n;i++) {
		cout << path1[i] << endl;
	}*/
	return 0;
}
