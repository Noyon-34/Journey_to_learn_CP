// https://atcoder.jp/contests/dp/tasks/dp_d
// Solved on 08.03.26

#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 7, M = 1e5 + 7;
using ll = long long;

int w[N], v[N];
ll dp[N][M];

// Recursive
ll rec(int n, int W) {
	if(n == 0)
		return 0;
	if(W == 0)
        return 0;
    if(dp[n][W] != -1)
        return dp[n][W];

	ll ans = rec(n - 1, W);
	if(W >= w[n])
		ans = max(ans, rec(n - 1, W - w[n]) + v[n]);

	return dp[n][W] = ans;
}
void solve() {
	int n, W;
    cin >> n >> W;
    for(int i = 1; i <= n; i++) {
    	cin >> w[i] >> v[i];
    }

    // memset(dp, -1, sizeof dp);
    // cout << rec(n, W);

    // Iterative
    for(int i = 1; i <= n; i++) {
        for(int ww = 0; ww <= W; ww++) {
            dp[i][ww] = dp[i - 1][ww];
            if(ww >= w[i])
                dp[i][ww] = max(dp[i][ww], dp[i - 1][ww - w[i]] + v[i]);
        }
    }

    cout << dp[n][W];
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