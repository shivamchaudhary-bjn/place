#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;
typedef struct node {
	char key;
	bool leaf;
	struct node *child[26];
}node;
typedef struct trie {
	node *root;
}trie;
node * getNode(char a,bool l)
{
	node *p = NULL;
	p = (node *)malloc(sizeof(node));
	p->key = a;
	p->leaf = l;
	for(int i = 0;i < 26;i++) {
		p->child[i] = NULL;
	}
	return p;
}
void initialise(trie **t,char a)
{
	(*t)->root = getNode(a,false);
}
void insert(trie **t,char st[25])
{
	node *temp = (*t)->root;
	for(int k = 0;k < strlen(st);k++) {
		int i = st[k]-97;
		//cout << i << " ";
		if(temp->child[i] != NULL) {
			temp = temp->child[i];
			//cout << " move ";
		}else {
			bool py = false;
			if(k == strlen(st)-1) { 
				py = true;
			}
			temp->child[i] = getNode(st[k],py);
			temp = temp->child[i];
		}
	}
	//cout << endl;
}
int search(trie *t,char kt[])
{
	bool ans = true;
	bool result = false;
	node *temp = t->root;
	string s = "";
	for(int i = 0;i < strlen(kt);i++) {
		int ind = kt[i]-97;
		if(!result) s += kt[i];
		if(temp->child[ind] == NULL) {
			ans = true;
			break;
		}else {
			if((temp->child[ind])->leaf == true) {
				result = true;
				//cout << s << endl;
			}
			temp = temp->child[ind];
		}
	}
	if(result) cout << s << endl;
	else cout << "No prefix match found\n";
	if(ans) return 1;
	else return 0;
}
int main()
{
	cout << "No. of strings\n";
	int n;
	cin >> n;
	char input[n][25];
	char pt[20];
	trie *t;
	initialise(&t,'_');
	for(int i = 0;i < n;i++) {
		cin >> input[i];
		insert(&t,input[i]);
	}
	cout << "enter search string\n";
	cin >> pt;
	if(search(t,pt) == 1) {
		cout << "yes\n";
	}else {
		cout << "no\n";
	}
	return 0;
}

