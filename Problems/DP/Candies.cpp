// https://atcoder.jp/contests/dp/tasks/dp_m
// Solved on 30.03.26

#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 7, M = 1e5 + 7, mod = 1e9 + 7;
using ll = long long;

int n, k, a[N], dp[N][M], pre[M];

// Not Possible in Recursive
int rec(int i, int can) {
	if(can == 0)
		return 1;
	if(i > n and can != 0)
		return 0;
	if(dp[i][can] != -1)
		return dp[i][can];

	int ans = 0;
	for(int j = 0; j <= a[i]; j++) {
		if(can >= j)
			ans = (ans + rec(i + 1, can - j) % mod) % mod;
	}
	return dp[i][can] = ans;
}
void solve() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
    	cin >> a[i];

    // memset(dp, -1, sizeof dp);
    // cout << rec(1, k);

    // Optimized Iterative Solution
    for(int i = n + 1; i >= 1; i--) {
    	for(int can = 0; can <= k; can++) {
    		int &ans = dp[i][can];
    		if(can == 0)
    			ans = 1;
    		else if(i > n)
    			ans = 0;
    		else {
    			// for(int j = 0; j <= a[i]; j++) {
    			// 	if(can >= j)
    			// 		ans = (ans + dp[i + 1][can - j]) % mod;
    			// }
    			int l = max(0, can - a[i]), r = can;
    			ans = (pre[r] - (l ? pre[l - 1] : 0) + mod) % mod;
    		}
    	}

    	memset(pre, 0, sizeof pre);
    	for(int x = 0; x <= k; x++) {
    		pre[x] = ((x ? pre[x - 1] : 0) + dp[i][x]) % mod;
    	} 
    }

    cout << dp[1][k];
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