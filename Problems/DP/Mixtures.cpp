// https://vjudge.net/problem/spoj-mixtures
// Solved on 04.04.26

#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 7, mod = 1e2;
using ll = long long;

int a[N], pre[N];
int dp[N][N];

int rec(int l, int r) {
	if(l == r)
		return 0;

	int &ans = dp[l][r];
	if(ans != -1)
		return ans;

	ans = INT_MAX;
	for(int i = l; i < r; i++) {
		int x = (pre[i] - pre[l - 1]) % mod, y = (pre[r] - pre[i]) % mod;
		int cost = x * y;
		ans = min(ans, cost + rec(l, i) + rec(i + 1, r));
	}

	return ans;
}
void solve() {
	int n;
    while(cin >> n) {
    	for(int i = 1; i <= n; i++) {
    		cin >> a[i];
    	}

    	for(int i = 1; i <= n; i++) {
    		pre[i] = pre[i - 1] + a[i];
    	}
    	memset(dp, -1, sizeof dp);
    	cout << rec(1, n) << '\n';
    }
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