// https://atcoder.jp/contests/dp/tasks/dp_e
// Solved on 12.03.26

#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 7;
using ll = long long;
const ll inf = 1e11 + 7;

int n, W, w[N], v[N];
ll dp[N][N * 1000];

// Recursive
ll rec(int i, int total_v) {
	if(i == n + 1) {
        if(total_v == 0)
            return 0;
        return inf;
    }
		  
    if(dp[i][total_v] != -1)
        return dp[i][total_v];

	ll ans = rec(i + 1, total_v);
	ans = min(ans, rec(i + 1, total_v - v[i]) + w[i]);

	return dp[i][total_v] = ans;
}
void solve() {
    cin >> n >> W;
    for(int i = 1; i <= n; i++) {
    	cin >> w[i] >> v[i];
    }

    // memset(dp, -1, sizeof dp);
    int ans = 0;
    // for(int total_v = 1; total_v <= n * 1000; total_v++) {
    //     if(rec(1, total_v) <= W)
    //         ans = max(ans, total_v);
    // }


    // Iterative
    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= n * 1000; j++) {
            dp[i][j] = inf;
        }
    }

    dp[0][0] = 0;
    for(int total_v = 0; total_v <= n * 1000; total_v++) {
        for(int i = 1; i <= n; i++) {
            ll &check = dp[i][total_v];
            check = inf;
            check = dp[i - 1][total_v];

            if(total_v >= v[i])
                check = min(check, dp[i - 1][total_v - v[i]] + w[i]);

            if(check <= W)
                ans = max(ans, total_v);
        }
    }

    cout << ans;
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