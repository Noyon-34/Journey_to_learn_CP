#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7, mod = 1e9 + 7;
using ll = long long;

vector<int> graph[N];
int dp[N][2];

void dfs(int u, int p) {
	dp[u][0] = 1;
	dp[u][1] = 1;

	for(auto v: graph[u]) {
		if(v != p) {
			dfs(v, u);
			dp[u][0] = 1LL * dp[u][0] * (dp[v][0] + dp[v][1]) % mod;
			dp[u][1] = 1LL * dp[u][1] * dp[v][0] % mod;
		}
	}
}
void solve() {
    int n; cin >> n;
    for(int i = 1; i < n; i++) {
    	int u, v; cin >> u >> v;
    	graph[u].push_back(v);
    	graph[v].push_back(u);
    }

    dfs(1, 0);

    cout << (dp[1][0] + dp[1][1]) % mod;
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