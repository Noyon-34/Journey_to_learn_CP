#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7, mod = 1e9 + 7;
using ll = long long;

int n;
vector<int> graph[N];
int dp[N][3];
void dfs(int u, int par) {
	dp[u][1] = 1;
	dp[u][2] = 1;

	for(auto v: graph[u]) {
		if(v != par) {
			dfs(v, u);
			dp[u][1] = (1LL * dp[u][1] * (dp[v][1] + dp[v][2]) % mod) % mod;
			dp[u][2] = (1LL * dp[u][2] * (dp[v][1] % mod) % mod);
		}
	}
}
void solve() {
  	cin >> n;
  	for(int i = 1; i < n; i++) {
  		int u, v; cin >> u >> v;
  		graph[u].push_back(v);
  		graph[v].push_back(u);
  	}

  	dfs(1, 0);

  	cout << (dp[1][1] + dp[1][2]) % mod;
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}