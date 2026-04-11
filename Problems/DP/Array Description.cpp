// https://cses.fi/problemset/task/1746
// Solved on 10.04.26

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7, M = 107, mod = 1e9 + 7;
using ll = long long;

int n, m, a[N], dp[N][M];

int rec(int i, int last) {
	if(i > n)
		return 1;

	int &ans = dp[i][last];
	if(ans != -1)
		return ans;
	ans = 0;
	int l, r;
	if(a[i] != 0) {
		l = r = a[i];
	}
	else {
		if(i == 1)
			l = 1, r = m;
		else {
			l = max(1, last - 1);
			r = min(m, last + 1);
		}
	}

	for(int j = l; j <= r; j++) {
		if(i == 1 or abs(last - j) <= 1) {
			ans += rec(i + 1, j);
			ans %= mod;
		}
	}
	return ans;
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    	cin >> a[i];

    memset(dp, -1, sizeof dp);
    cout << rec(1, 0);
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