// https://vjudge.net/problem/lightoj-1125
// Solved on 14.03.26

#include<bits/stdc++.h>
using namespace std;

const int N = 2e2 + 7;
using ll = long long;

int n, q, D, M;
int a[N];
ll dp[N][15][25];

ll rec (int i, int cn, int sum) {
	if(cn > M)
		return 0;
	if(i > n) {
		if(cn == M and sum == 0)
			return 1;
		return 0;
	}

	if(dp[i][cn][sum] != -1)
		return dp[i][cn][sum];

	ll ans = rec(i + 1, cn, sum);
	ans += rec(i + 1, cn + 1, (sum + (a[i] % D + D) % D) % D);
	
	return dp[i][cn][sum] = ans;
}
void solve(int cs) {
    cin >> n >> q;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    }

    cout << "Case " << cs << ": \n";
    while(q--) {
    	cin >> D >> M;
    	memset(dp, -1, sizeof dp);
    	cout << rec(1, 0, 0) << '\n';
    }
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