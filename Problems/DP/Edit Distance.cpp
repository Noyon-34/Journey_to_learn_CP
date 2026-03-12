// https://cses.fi/problemset/task/1639
// Solved on 13.03.26

#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 7;
using ll = long long;

string a, b;
int n, m;
int dp[N][N];

int rec(int i, int j) {
    if(i == n) {
        if(j == m)
            return 0;
        return m - j;
    }
    if(j == m)
        return n - i;

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    if(a[i] == b[j])
        ans = rec(i + 1, j + 1);
    ans = min(ans, rec(i + 1, j + 1) + 1);
    ans = min(ans, rec(i + 1, j) + 1);
    ans = min(ans, rec(i, j + 1) + 1);

    return dp[i][j] = ans;
}
void solve() {
    cin >> a >> b;

    n = a.size(), m = b.size();
    // memset(dp, -1, sizeof dp);
    // cout << rec(0, 0);

    for(int i = 0; i <= n; i++) 
        dp[i][m] = n - i;
    for(int j = 0; j <= m; j++) 
        dp[n][j] = m - j;

    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 0; j--) {
            if(a[i] == b[j])
                dp[i][j] = dp[i + 1][j + 1];
            else {
                dp[i][j] = 1 + min({dp[i][j + 1], dp[i + 1][j], dp[i + 1][j + 1]});
            }        
        }
    }

    cout << dp[0][0] << '\n';
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