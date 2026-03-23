// https://vjudge.net/problem/uva-11151
// Solved on 23.03.26

#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
using ll = long long;

string s;
int n, dp[N][N];

// Recursive 
int rec(int i, int j) {
	if(i >= j) 
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];

	int ans = INT_MAX;
	if(s[i] == s[j]) {
		ans = min(ans, rec(i + 1, j - 1));
	}
	else {
		ans = min(ans, rec(i, j - 1) + 1);
		ans = min(ans, rec(i + 1, j) + 1);
	}

	return dp[i][j] = ans;
}
void solve() {
    getline(cin, s);
    n = s.size();

    // memset(dp, -1, sizeof dp);
    // cout << n - rec(0, n - 1) << '\n';

    // Iterative
    if(s.empty()) {
    	cout << 0 << '\n';
    	return;
    }

    for(int i = 0; i < n; i++) {
    	dp[i][i] = 0;
    }
    for(int l = 2; l <= n; l++) {
    	for(int i = 0; i + l - 1 < n; i++) {
    		int j = i + l - 1;
    		if(s[i] != s[j]) {
    			dp[i][j] = min(dp[i + 1][j] + 1, dp[i][j - 1] + 1);
    		}
    		else {
    			dp[i][j] = dp[i + 1][j - 1];
    		}
    	}
    }

    cout << n - dp[0][n - 1] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    cin >> t;
    cin.ignore();
    while(t--) {
        solve();
    }
    return 0;
}