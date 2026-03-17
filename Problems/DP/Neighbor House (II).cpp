#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
using ll = long long;

int n;
int a[N], dp[N][2][2];

int rec(int i, int t, int tt) {
	if(i > n)
		return 0;
	if(dp[i][t][tt] != -1)
		return dp[i][t][tt];

	int ans = rec(i + 1, 0, tt);
	if(i == n) {
		if(!t and !tt)
			ans = max(ans, rec(i + 1, 1, tt) + a[i]);
	}
	else {
		if(!t)
			ans = max(ans, rec(i + 1, 1, tt) + a[i]);
	}

	return dp[i][t][tt] = ans;
}
void solve(int cs) {
    cin >> n;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    }

    memset(dp, -1, sizeof dp);
    cout << "Case " << cs << ": " << max(rec(2, 0, 0), a[1] + rec(2, 1, 1)) << '\n';
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