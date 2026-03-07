// https://cses.fi/problemset/task/1637
// Solved on 06.03.26

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7;
using ll = long long;

int dp[N];

// Recursive
int rec(int n) {
	if(n == 0)
		return 0;
	if(dp[n] != -1)
		return dp[n];

	int x = n, ans = INT_MAX;
	while(x) {
		int dig = x % 10;
		x /= 10;
		if(dig != 0)
			ans = min(ans, rec(n - dig) + 1);
	}
	return dp[n] = ans;
}
void solve() {
    int n; cin >> n;
    // memset(dp, -1, sizeof dp);
    // cout << rec(n);

    // Iterative
    dp[0] = 0;
    for(int i = 1; i <= n; i++) {
    	dp[i] = INT_MAX;
    	int ans = dp[i];
    	
    	int x = i;
    	while(x) {
			int dig = x % 10;
			x /= 10;
			if(dig != 0) {
				ans = min(ans, dp[i - dig] + 1);
				dp[i] = ans;
			}
		}
    }

    cout << dp[n];
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