#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;

vector<int> graph[N];
int dp[N];

int rec(int u) {
	if(dp[u] != -1)
		return dp[u];
	int ans = 0;
	for(auto v: graph[u]) {
		ans = max(ans, rec(v) + 1);
	}

	return dp[u] = ans;
}
void solve() {
    int n, m; cin >> n >> m;
    while(m--) {
    	int u, v;
    	cin >> u >> v;
    	graph[u].push_back(v);
    }

    memset(dp, -1, sizeof dp);
    int ans = 0;
    for(int i = 1; i <= n; i++) {
    	ans = max(ans, rec(i));
    }

    cout << ans << '\n';
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