// https://atcoder.jp/contests/dp/tasks/dp_n
// Solved on 01.04.26

#include<bits/stdc++.h>
using namespace std;

const int N = 4e2 + 7;
using ll = long long;
const ll inf = 1e18 + 7;

int n, a[N];
ll dp[N][N];

// Recursive
ll rec(int l, int r) {
	if(l == r)
		return 0;

	ll &ans = dp[l][r], cost = 0;
	if(ans != -1)
		return ans;

	for(int i = l; i <= r; i++) {
		cost += a[i];
	}
	ans = inf;
	for(int i = l; i < r; i++) {
		ans = min(ans, cost + rec(l, i) + rec(i + 1, r));
	}

	return ans;
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    }

    // memset(dp, -1, sizeof dp);
    // cout << rec(1, n);

    // Iterative
    for(int i = 1; i <= n; i++) {
    	dp[i][i] = 0;
    }
    for(int len = 2; len <= n; len++) {
    	for(int i = 1; i + len - 1 <= n; i++) {
    		int j = i + len - 1;
    		ll &ans = dp[i][j], cost = 0;
    		ans = inf;
    		for(int k = i; k <= j; k++) {
    			cost += a[k];
    		}
    		for(int k = i; k < j; k++) {
    			ans = min(ans, cost + dp[i][k] + dp[k + 1][j]);
    		}
    	}
    }
    cout << dp[1][n];
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