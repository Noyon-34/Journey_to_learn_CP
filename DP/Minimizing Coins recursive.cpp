// https://cses.fi/problemset/task/1634/

#include<bits/stdc++.h>
using namespace std;

const int N = 105, X = 1e6 + 7, inf = 1e9;
using ll = long long;

int n, x;
int a[N];
int dp[N][X];

int rec(int i, int sum) {
	if(sum > x)
		return inf;
	if(i > n) {
		if(sum == x)
			return 0;
		return inf;
	}
	if(dp[i][sum] != -1)
		return dp[i][sum];

	int ans = rec(i + 1, sum);
	ans = min(ans, 1 + rec(i, sum + a[i]));

	return dp[i][sum] = ans;
}
void solve() {
    cin >> n >> x;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    }

    memset(dp, -1, sizeof dp);
    int ans = rec(1, 0);
    cout << (ans >= inf ? -1 : ans);
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