#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;

int h[N];
ll dp[N];

// // Recursive
// ll rec(int n) {
// 	if(n == 1)
// 		return 0;
// 	if(dp[n] != -1)
// 		return dp[n];

// 	dp[n] = rec(n - 1) + abs(h[n] - h[n - 1]);
// 	if(n > 2)
// 		dp[n] = min(dp[n], rec(n - 2) + abs(h[n] - h[n - 2]));
// 	return dp[n]; 
// } 
void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++)
    	cin >> h[i];

    // memset(dp, -1, sizeof dp);
    // cout << rec(n) << '\n';


    // Iterative
    dp[1] = 0;
    for(int i = 2; i <= n; i++) {
    	dp[i] = abs(h[i] - h[i - 1]) + dp[i - 1];
    	if(i > 2)
    		dp[i] = min(dp[i], abs(h[i] - h[i - 2]) + dp[i - 2]);
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