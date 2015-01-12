#include<iostream>
#include<queue>
using namespace std;
typedef struct node {
	int dest;
	int weight;
}node;
typedef struct root {
	int val;
	int key;
}root;
struct pt {
	bool operator()(root a,root b)
	{
		return (a.key > b.key);
	}
};
void prims(vector<node> v[],int ver,int edge,int s)
{
	priority_queue<root,vector<root>,pt > q;
	int vis[101] = {0};
	root ans[ver+1];
	for(int i = 0;i <= ver;i++) {
		ans[i].val = i;
		ans[i].key = 999;
	}
	int sum = 0;
	vector<node>::iterator it;
	
	//vis[s] = 1;
	ans[s].key = 0;
	
	q.push(ans[s]);
	cout << "MST\n\n";
	while(!q.empty()) {
		root temp = q.top();
		//cout << temp.val << " " << temp.key << endl;// << temp.dest << " " << temp.weight << endl;
		q.pop();
		//sum += temp.key;
		vis[temp.val] = 1;
		for(it = v[temp.val].begin();it != v[temp.val].end();it++) {
			if(vis[(*it).dest] == 0 && (*it).weight < ans[(*it).dest].key) {
				ans[(*it).dest].key = (*it).weight;
				q.push(ans[(*it).dest]);
			}
		}
	}
	sum = 0;
	for(int i = 1;i<= ver;i++) {
		cout << ans[i].key << " ";
		sum += ans[i].key;
	}
	cout << "\ntotal path sum of MST is " << sum << endl;
}
int main()
{
	cout << "No. of vertexes and edges\n";
	int ver,edge;
	cin >> ver >> edge;
	vector<node> v[ver+1];
	for(int i = 0;i < edge;i++) {
		int a,b,w;
		node temp,temp1;
		cin >> a >> b >> w;
		temp.dest = b;
		temp.weight = w;
		temp1.dest = a;
		temp1.weight = w;
		v[a].push_back(temp);
		v[b].push_back(temp1);
	}
	prims(v,ver,edge,1);
	return 0;
}
