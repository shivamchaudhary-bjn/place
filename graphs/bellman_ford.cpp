#include<iostream>
#include<cstdlib>
using namespace std;
typedef struct edge {
	int s;
	int d;
	int w;
}edge;
void bellman_ford(edge graph[],int v,int e,int source)
{
	int dist[v+1];
	for(int i = 0;i <= v;i++) {
		dist[i] = 999;
	}
	dist[source] = 0;

	for(int k = 0;k < v-1;k++) {
		//cout << "dslg\n";
		for(int j = 0;j < e;j++) {
			int a = graph[j].s;
			int b = graph[j].d;
			int c = graph[j].w;
			//cout << a << " "<< b << " " << c << endl;
			if(dist[a] + c < dist[b]) {
				dist[b] = dist[a] + c;
			}
		}
	}

	for(int i = 0;i < e;i++) {
		int x = graph[i].s;
		int y = graph[i].d;
		int z = graph[i].w;
		if(dist[x] + z < dist[y]) {
			cout << "negative weight cycle between " << x << " and " << y << endl;
		}
	}
	for(int i = 1;i <= v;i++) {
		cout << dist[i] << " ";
	}
}
int main()
{
	cout << "No. of vertexes and edges\n";
	int v,e;
	cin >> v >> e; 
	edge graph[e];
	for(int i = 0;i < e;i++) {
		int a,b,c;
		cin >> a  >> b >> c;
		graph[i].s = a;
		graph[i].d = b;
		graph[i].w = c;
	}
	bellman_ford(graph,v,e,1);
	return 0;
}
