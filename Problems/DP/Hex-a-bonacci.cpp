#include<bits/stdc++.h>
using namespace std;

const int N = 1e4 + 7, mod = 10000007;
using ll = long long;

int a, b, c, d, e, f;
int dp[N];

int fn(int n) {
    if (n == 0) return a;
    if (n == 1) return b;
    if (n == 2) return c;
    if (n == 3) return d;
    if (n == 4) return e;
    if (n == 5) return f;
    if(dp[n] != -1) return dp[n];

    dp[n] = (fn(n - 1) + fn(n - 2)) % mod;
    dp[n] = (dp[n] + fn(n - 3)) % mod;
    dp[n] = (dp[n] + fn(n - 4)) % mod;
    dp[n] = (dp[n] + fn(n - 5)) % mod;
    dp[n] = (dp[n] + fn(n - 6)) % mod;
    return dp[n];
}
void solve(int cs) {
    int n;
    cin >> a >> b >> c >> d >> e >> f >> n;

    memset(dp, -1, sizeof dp);
    cout << "Case " << cs << ": " << fn(n) % mod << '\n';
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