#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7, inf = 1e9;
using ll = long long;

int n, m;
int mat[N][N], dp[N][N];
int min_cost(int i, int j) {
	if(i == n + 1 or j == m + 1)
		return inf;
	if(i == n and j == m)
		return mat[i][j];
	if(dp[i][j] != -1)
		return dp[i][j];
	int ans = min(min_cost(i + 1, j), min_cost(i, j + 1)) + mat[i][j];
	return dp[i][j] = ans;
}

// Path Tracking
void path(int i, int j) {
	cout << i << " " << j << '\n';
	if(i == n and j == m)
		return;

	int right = min_cost(i, j + 1);
	int down = min_cost(i + 1, j);

	if(right <= down)
		path(i, j + 1);
	else
		path(i + 1, j);
}
void solve() {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
    	for(int j = 1; j <= m; j++) {
    		cin >> mat[i][j];
    	}
    }
    memset(dp, -1, sizeof dp);
    cout << min_cost(1, 1) << '\n';

    path(1, 1);
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