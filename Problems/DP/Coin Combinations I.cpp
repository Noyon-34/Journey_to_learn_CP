// https://cses.fi/problemset/task/1635
// Solve on 25.03.36

#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 7, M = 1e6 + 7, mod = 1e9 + 7;
using ll = long long;

int n, x, a[N];
int dp[M];

// Recursive
int rec(int sum) {
	if(sum == 0)
		return 1;
	if(dp[sum] != -1)
		return dp[sum];

	int ans = 0;
	for(int i = 1; i <= n; i++) {
		if(sum >= a[i]) {
			ans = (ans + rec(sum - a[i]) % mod) % mod;
		}
	}

	return dp[sum] = ans;
}
void solve() {
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    }

    // memset(dp, -1, sizeof dp);
    // cout << rec(x);

    // Iterative
    dp[0] = 1;
    for(int sum = 0; sum <= x; sum++) {
    	for(int i = 1; i <= n; i++) {
    		if(sum >= a[i]) {
    			dp[sum] = (dp[sum] + dp[sum - a[i]] % mod) % mod;
    		}
    	}
    }

    cout << dp[x];
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