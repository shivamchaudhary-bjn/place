#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
using namespace std;
typedef struct edge {
	int s;
	int d;
}edge;
typedef struct node {
	int dest;
	int weight;
}node;
void bfs(vector<int> ver[],int vis[],int v,int source)
{
	queue<int> q;
	q.push(source);
	vis[source] = 1;
	vector<int>::iterator it;
	while(!q.empty()) {
		int u = q.front();
		q.pop();
		cout << u << " ";
		for(it = ver[u].begin();it != ver[u].end();it++) {
			if(vis[*it] == 0) {
				q.push(*it);
				vis[*it] = 1;
				//cout << "pushed " << (*it) << endl;
			}
		}
	}
	cout << endl;
}
void dfs(vector<int> ver[],int vis[],int v,int source)
{
	cout << source << " ";
	vis[source] = 1;
	vector<int>::iterator it;
	
	for(it = ver[source].begin();it != ver[source].end();it++) {
		if(vis[*it] == 0) {
			dfs(ver,vis,v,*it);
		}else {
			cout << "cycle between " << source << " and " << *it << endl;
		}
	}
}
int find(int *parent,int x)
{
	if(parent[x] == -1) {
		return x;
	}else {
		return find(parent,parent[x]);
	}
}
void unite(int *parent,int x,int y)
{
	int a = find(parent,x);
	int b = find(parent,y);
	parent[a] = b;
}
void cycle(edge graph[],int *parent,int v,int e)
{
	for(int i = 0;i < e;i++) {
		int x = find(parent,graph[i].s);
		int y = find(parent,graph[i].d);
		if(x == y) {
			cout << "cycle b/w " << graph[i].s << " and " << graph[i].d << endl;
		}else {
			unite(parent,x,y);
		}
	}
}
void topological_sort(vector<int> ver[],int *vis,stack<int> &s,int i)
{
	vis[i] = 1;
	vector<int>::iterator it;
	
	for(it = ver[i].begin();it != ver[i].end();it++) {
		if(vis[*it] == 0) {
			topological_sort(ver,vis,s,*it);
		}
	}
	s.push(i);
}
int main()
{
	cout << "No. of vertexes and edges\n";
	int v,e;
	cin >> v >> e;
	vector<int> ver[101];
	int vis[100] = {0}; 
	edge graph[e];
	int parent[v+1];
	for(int i = 0;i <= v;i++) parent[i] = -1;
	//memset(parent, -1, sizeof(int)*(v+1));
	cout << "Enter graph\n";
	for(int i = 0;i < e;i++) {
		int a,b;
		cin >> a >> b;
		ver[a].push_back(b);
		//ver[b].push_back(a);
	}

	/*bfs(ver,vis,v,1);
	dfs(ver,vis,v,1);
	cout << "cycle in undirected graph\n";
	for(int i = 0;i < e;i++) {
		int a,b;
		cin >> a  >> b;
		graph[i].s = a;
		graph[i].d = b;
	}
	cycle(graph,parent,v,e);*/
	cout << "\ntopological sort\n";
	stack<int> s;
	for(int i = 1;i <= v;i++) {
		if(vis[i] == 0) {
			topological_sort(ver,vis,s,i);
		}
	}
	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	return 0;
}
