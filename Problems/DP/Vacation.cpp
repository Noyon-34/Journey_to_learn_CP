#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;

int a[N], b[N], c[N];
int dp[N][3];

// Recursive
int rec(int n, int m) {
	if(m == 1 and n == 1)
		return a[n];
	if(m == 2 and n == 1)
		return b[n];
	if(m == 3 and n == 1)
		return c[n];
	if(dp[n][m] != -1)
		return dp[n][m];

	int ans = INT_MIN;
	if(m == 1) {
		ans = max(ans, rec(n - 1, m + 1) + a[n]);
		ans = max(ans, rec(n - 1, m + 2) + a[n]);
	}
	if(m == 2) {
		ans = max(ans, rec(n - 1, m - 1) + b[n]);
		ans = max(ans, rec(n - 1, m + 1) + b[n]);
	}
	if(m == 3) {
		ans = max(ans, rec(n - 1, m - 1) + c[n]);
		ans = max(ans, rec(n - 1, m - 2) + c[n]);
	}

	return dp[n][m] = ans;
}
void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i] >> b[i] >> c[i];
    }

    // memset(dp, -1, sizeof dp);

    // int ans = rec(n, 1);
    // ans = max(ans, rec(n, 2));
    // ans = max(ans, rec(n, 3));

    // cout << ans << '\n';


    // Iterative
    dp[0][1] = dp[0][2] = dp[0][3] = 0;
    for(int i = 1; i <= n; i++) {
    	for(int j = 1; j <= 3; j++) {
    		if(j == 1) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + a[i]);
				dp[i][j] = max(dp[i][j], dp[i - 1][j + 2] + a[i]);
			}
			else if(j == 2) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + b[i]);
				dp[i][j] = max(dp[i][j], dp[i - 1][j + 1] + b[i]);
			}
			else {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + c[i]);
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 2] + c[i]);
			}
    	}
    }

    cout << max(dp[n][1], max(dp[n][2], dp[n][3]));
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