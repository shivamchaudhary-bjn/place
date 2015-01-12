#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int main()
{
	int n,m;
	cin >> n >> m;
	int vis[1002] = {0};
	int res[1002] = {0};
	vector<int> v[n+1];
	vector<int>::iterator it; 
	for(int i = 0;i < m;i++) {
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	queue<int> q;
	q.push(0);
	vis[0] = 1;
	while(!q.empty()) {
		int u = q.front();
		//vis[u] = 1;
		q.pop();
		for(it = v[u].begin();it != v[u].end();it++) {
			if(vis[(*it)] == 0) {
				q.push((*it));
				res[(*it)] = res[u] + 1;
				vis[(*it)] = 1;
			}
		}
	}
	for(int i = 1;i < n;i++) {
		if(res[i] == 0) {
			cout << "-1\n";
		}else {
			cout << res[i] << endl;
		}
	}
	return 0;
}



