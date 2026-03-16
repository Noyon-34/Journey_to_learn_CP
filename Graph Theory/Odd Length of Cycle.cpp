#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;

vector<int> graph[N];
bool vis[N], odd_length;
int color[N];

void dfs(int u) {
	vis[u] = true;

	for(auto v: graph[u]) {
		if(!vis[v]) {
			color[v] = color[u] ^ 1;
			dfs(v);
		}
		else {
			if(color[v] == color[u])
				odd_length = true;
		}
	}
}
void solve() {
    int n, m; cin >> n >> m;

    while(m--) {
    	int u, v; cin >> u >> v;
    	graph[u].push_back(v);
    	graph[v].push_back(u);
    }

    odd_length = false;
    //For Disconnected Graph
    for(int i = 1; i <= n; i++) {
    	if(!vis[i])
    		dfs(i);
    }

    if(odd_length)
    	cout << "YES\n";
    else
    	cout << "NO\n";
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}