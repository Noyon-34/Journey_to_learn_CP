#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
using ll = long long;

int h[N], k;
ll dp[N];

// // Recursive
// ll rec(int n) {
// 	if(n == 1)
// 		return 0;
// 	if(dp[n] != -1)
// 		return dp[n];

// 	dp[n] = rec(n - 1) + abs(h[n] - h[n - 1]);
//     for(int i = 2; i <= k; i++) {
//         if(n > i)
//             dp[n] = min(dp[n], rec(n - i) + abs(h[n] - h[n - i]));
//     }
// 	return dp[n]; 
// } 
void solve() {
    int n; cin >> n >> k;
    for(int i = 1; i <= n; i++)
    	cin >> h[i];

    // memset(dp, -1, sizeof dp);
    // cout << rec(n) << '\n';


    // Iterative
    dp[1] = 0;
    for(int i = 2; i <= n; i++) {
        dp[i] = abs(h[i] - h[i - 1]) + dp[i - 1];
        for(int j = 2; j <= k; j++) {
            if(i > j)
                dp[i] = min(dp[i], abs(h[i] - h[i - j]) + dp[i - j]);
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