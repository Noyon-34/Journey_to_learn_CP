#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 7, M = 1e5 + 7;
using ll = long long;

int n, W, w[N], v[N];
ll dp1[N][M];
ll dp2[M];

// **Recursive
ll knapsack(int i, int weight) {
	if(i == n + 1)
		return 0;
	if(dp1[i][weight] != -1)
		return dp1[i][weight];

	ll ans = knapsack(i + 1, weight);
	if(weight + w[i] <= W) {
		ans = max(ans, knapsack(i + 1, weight + w[i]) + v[i]);
	}
	return dp1[i][weight] = ans;
}
void solve() {
    cin >> n >> W;
    for(int i = 1; i <= n; i++) {
    	cin >> w[i] >> v[i];
    }

	memset(dp1, -1, sizeof dp1);
    cout << knapsack(1, 0) << '\n';

    // **Iterative
    // for(int i = 1; i <= n; i++) {
    // 	for(int weight = W; weight >= w[i]; weight--) {
    // 		dp2[weight] = max(dp2[weight], dp2[weight - w[i]] + v[i]);
    // 	}
    // }

    // cout << dp2[W];
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