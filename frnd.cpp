#include<iostream>
#include<vector>
using namespace std;
int vis[100002] = {0};
int cnt = 0;
void dfs(vector<int> v[],int s)
{
	vis[s] = 1;
	vector<int>::iterator it;
	for(it = v[s].begin();it != v[s].end();it++) {
		if(vis[(*it)] == 0) {
			dfs(v,(*it));
		}
	}
}
int main()
{
	int n,m;
	cin >> n >> m;
	vector<int> v[n];
	for(int i = 0;i < m;i++) {
		int a,b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	vector<int> ans;
	for(int i = 0;i < n;i++) {
		if(vis[i] == 0) {
			cnt++;
			ans.push_back(i);
			dfs(v,i);
		}
	}
	cout << cnt << endl;
	for(int i = 0;i < ans.size();i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
	return 0;
}

