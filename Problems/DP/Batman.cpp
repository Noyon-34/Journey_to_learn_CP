// https://vjudge.net/problem/lightoj-1159
// Solved on 22.03.26

#include<bits/stdc++.h>
using namespace std;

const int N = 50 + 7;
using ll = long long;

string a, b, c;
int n, m, o, dp[N][N][N];

int rec(int i, int j, int k) {
	if(i == n or j == m or k == o)
		return 0;
	if(dp[i][j][k] != -1)
		return dp[i][j][k];

	int ans = 0;
	ans = rec(i + 1, j, k);
	ans = max(ans, rec(i, j + 1, k));
	ans = max(ans, rec(i, j, k + 1));
	if(a[i] == b[j] and b[j] == c[k]) {
		ans = max(ans, rec(i + 1, j + 1, k + 1) + 1);
	}

	return dp[i][j][k] = ans;
}
void solve(int cs) {
    cin >> a >> b >> c;
    n = a.size(), m = b.size(), o = c.size();

    memset(dp, -1, sizeof dp);
    cout << "Case " << cs << ": ";
    cout << rec(0, 0, 0) << '\n';
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