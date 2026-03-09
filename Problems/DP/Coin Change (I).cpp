// https://vjudge.net/problem/lightoj-1231
// Solved on 10.03.26

#include<bits/stdc++.h>
using namespace std;

const int N = 50 + 7, M = 1e3 + 7, mod = 100000007;
using ll = long long;

int n, k;
int a[N], c[N];
int dp[N][M];

// Recursive
int rec(int i, int v) {
	if(v < 0) return 0;
	if(i < 1) {
		if(v == 0) return 1;
		return 0;
	}
	if(dp[i][v] != -1) return dp[i][v];

	int ans = 0;
	for(int j = 0; j <= c[i]; j++) {
		ans += rec(i - 1, v - j * a[i]);
		ans %= mod;
	}

	return dp[i][v] = ans;
}
void solve(int cs) {
    cin >> n >> k;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    }
    for(int i = 1; i <= n; i++) {
    	cin >> c[i];
    }

    // memset(dp, -1, sizeof dp);
    // cout << "Case " << cs << ": " << rec(n, k) << '\n';

    // Iterative
    for(int i = 0; i <= n; i++) {
    	for(int x = k; x >= 0; x--) {
    		int &ans = dp[i][x];
    		if(i == 0) {
    			if(x == 0) {
	    			ans = 1;
	    		}
	    		else {
			    	ans = 0;
	    		}
	    		continue;
    		}

    		ans = 0;
			for(int j = 0; j <= c[i]; j++) {
		    	int d = x - j * a[i];
		    	if(d >= 0) {
					ans += dp[i - 1][d];
		    		ans %= mod;
		    	}
	    	}
    	}
    }

    cout << "Case " << cs << ": " << dp[n][k] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1, cs = 0;
    cin >> t;
    while(t--) {
        solve(++cs);
    }
    return 0;
}