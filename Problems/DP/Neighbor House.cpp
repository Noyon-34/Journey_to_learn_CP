#include<bits/stdc++.h>
using namespace std;

const int N = 20 + 7;
using ll = long long;

int n;
vector<int> cost[3];
int dp[3][N];

int rec(int i, int j) {
	if(j == n)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];

	int ans = INT_MAX;
	if(i == 0) {
		ans = min(ans, cost[i][j] + rec(i + 1, j + 1));
		ans = min(ans, cost[i][j] + rec(i + 2, j + 1));
	}
	else if(i == 1) {
		ans = min(ans, cost[i][j] + rec(i - 1, j + 1));
		ans = min(ans, cost[i][j] + rec(i + 1, j + 1));
	}
	else {
		ans = min(ans, cost[i][j] + rec(i - 1, j + 1));
		ans = min(ans, cost[i][j] + rec(i - 2, j + 1));
	}

	return dp[i][j] = ans;
}
void solve(int cs) {
	for(int i = 0; i < 3; i++)
		cost[i].clear();

    cin >> n;
    for(int i = 0; i < n; i++) {
    	for(int j = 0; j < 3; j++) {
    		int x; cin >> x;
    		cost[j].push_back(x);
    	}
    }

    memset(dp, -1, sizeof dp);
    cout << "Case " << cs << ": " << min({rec(0, 0), rec(1, 0), rec(2, 0)}) << '\n';
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