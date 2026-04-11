// https://cses.fi/problemset/task/1745
// Solved on 11.04.26

#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 7, MAX_SUM = 1e5 + 7;
using ll = long long;

int n, a[N];
bool dp[N][MAX_SUM], vis[N][MAX_SUM];

bool rec(int i, int money) {
	if(i > n)
		return money == 0;
    if(vis[i][money])
        return dp[i][money];

	bool possible = rec(i + 1, money);
    if(money >= a[i])
        possible |= rec(i + 1, money - a[i]);
    vis[i][money] = true;

    return dp[i][money] = possible;
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++)
    	cin >> a[i];

    vector<int> ans;
    for(int money = 1; money < MAX_SUM; money++) {
        if(rec(1, money)) {
            ans.push_back(money);
        }
    }

    cout << ans.size() << '\n';
    for(auto it: ans) {
        cout << it << ' ';
    }
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