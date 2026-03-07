// https://cses.fi/problemset/task/1633
// Solved on 03.03.26

#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 7, mod = 1e9 + 7;
using ll = long long;

int dp[N];

// // Recursive
// int rec(int n) {
//     if(n < 0)
//         return 0;
//     if(n == 0)
//         return 1;
//     if(dp[n] != -1)
//         return dp[n];

//     dp[n] = (rec(n - 1) + rec(n - 2)) % mod;
//     dp[n] = (dp[n] + rec(n - 3)) % mod;
//     dp[n] = (dp[n] + rec(n - 4)) % mod;
//     dp[n] = (dp[n] + rec(n - 5)) % mod;
//     dp[n] = (dp[n] + rec(n - 6)) % mod;
//     return dp[n];
// }
void solve() {
    int n; cin >> n;

    // Iterative
    dp[1] = 1;
    for(int i = 2; i <= n; i++) {
        for(int j = 1; j < 7; j++) {
            if(i - j > -1)
                dp[i] = (dp[i] + (max(1, dp[i - j]) % mod)) % mod;
        }
    }

    cout << dp[n] << '\n';

    // memset(dp, -1, sizeof dp);
    // cout << rec(n) << '\n';
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