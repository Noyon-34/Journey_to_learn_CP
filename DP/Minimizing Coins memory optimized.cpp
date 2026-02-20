// https://cses.fi/problemset/task/1634/

#include<bits/stdc++.h>
using namespace std;

const int N = 105, X = 1e6 + 7, inf = 1e9;
using ll = long long;

int a[N];
int dp[2][X];

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
    		dp[1][sum] = dp[0][sum];
    		if(sum >= a[i])
    			dp[1][sum] = min(dp[1][sum], 1 + dp[1][sum - a[i]]);
    	}
        for(int sum = 0; sum <= x; sum++) {
            dp[0][sum] = dp[1][sum];
        }
    }

    cout << (dp[1][x] >= inf ? -1 : dp[1][x]);
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