#include<iostream>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;
typedef struct edge {
	int s;
	int d;
	int w;
}edge;
bool pt(edge a,edge b)
{
	return (a.w < b.w);
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
void kruskal(edge graph[],int *parent,int v,int e)
{
	edge result[e];
	int cnt = 0;
	for(int i = 0;i < e;i++) {
		int x = find(parent,graph[i].s);
		int y = find(parent,graph[i].d);
		if(x != y) {
			unite(parent,x,y);
			result[cnt] = graph[i];
			cnt++;
		}
	}
	int sum = 0;
	for(int i = 0;i < cnt;i++) {
		cout << result[i].s << " " << result[i].d << " " << result[i].w << endl;
		sum += result[i].w;
	}
	cout << "Sum of MST is " << sum << endl;
}
int main()
{
	cout << "No. of vertexes and edges\n";
	int v,e;
	cin >> v >> e;
	int vis[100] = {0}; 
	edge graph[e];
	int parent[v+1];
	for(int i = 0;i <= v;i++) parent[i] = -1;
	cout << "cycle in undirected graph\n";
	for(int i = 0;i < e;i++) {
		int a,b,c;
		cin >> a  >> b >> c;
		graph[i].s = a;
		graph[i].d = b;
		graph[i].w = c;
	}
	sort(graph,graph + e,pt);
	kruskal(graph,parent,v,e);
	return 0;
}
