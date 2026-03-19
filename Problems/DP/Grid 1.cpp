#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7, mod = 1e9 + 7;
using ll = long long;

int n, m;
vector<string> grid;
int dp[N][N];
int dx[2] = {1, 0};
int dy[2] = {0, 1};

int rec(int r, int c) {
	if(r == n - 1 and c == m - 1) {
		return 1;
	}
    if(dp[r][c] != -1)
        return dp[r][c];

    int ans = 0;
	for (int i = 0; i < 2; i++) {
        int nr = r + dx[i];
        int nc = c + dy[i];
        if (nr >= 0 and nr < n and nc >= 0 and nc < m and grid[nr][nc] == '.') {
            ans = (ans + rec(nr, nc) % mod) % mod;
        }
    }

    return dp[r][c] = ans;
}
void solve() {
    cin >> n >> m;

    for(int i = 1; i <= n; i++) {
    	string s; cin >> s;
    	grid.push_back(s);
    }

    memset(dp, -1, sizeof dp);
    cout << rec(0, 0);
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