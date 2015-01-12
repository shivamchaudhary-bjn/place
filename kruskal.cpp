#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct edge
{
	int v1;
	int v2;
	int w;
	edge(int a,int b,int c) { v1  = a; v2 = b; w = c;}
}edge;
bool pt(edge a,edge b)
{
	return(a.w < b.w);
}
int main()
{
	int ver,ed;
	cout << "no. of vertexes and edges\n";
	cin >> ver >> ed;
	vector<edge> v,ans;
	vector<edge>::iterator it;
	cout << "enter the topology\n";
	for(int i = 0;i < ed;i++) {
		int x,y,z;
		cin >> x >> y >> z;
		edge p(x,y,z);
		v.push_back(p);
	}
	sort(v.begin(),v.end(),pt);

	for(it = v.begin();it != v.end();it++) {
		int u = (*it).v1;
		int t = (*it).v2;
		int 
	return 0;
}


