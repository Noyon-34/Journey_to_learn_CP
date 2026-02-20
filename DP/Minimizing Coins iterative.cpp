// https://cses.fi/problemset/task/1634/

#include<bits/stdc++.h>
using namespace std;

const int N = 105, X = 1e6 + 7, inf = 1e9;
using ll = long long;

int a[N];
int dp[N][X];

void solve() {
    int n, x; cin >> n >> x;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    }

    dp[0][0] = 0;
    for(int sum = 1; sum <= x; sum++) {
    	dp[0][sum] = inf;
    }
    for(int i = 1; i <= n; i++) {
    	for(int sum = 0; sum <= x; sum++) {
    		dp[i][sum] = dp[i - 1][sum];
    		if(sum >= a[i])
    			dp[i][sum] = min(dp[i][sum], 1 + dp[i][sum - a[i]]);
    	}
    }

    cout << (dp[n][x] >= inf ? -1 : dp[n][x]);
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