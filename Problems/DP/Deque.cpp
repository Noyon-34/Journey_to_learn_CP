// https://atcoder.jp/contests/dp/tasks/dp_l
// Solved on 28.03.26

#include<bits/stdc++.h>
using namespace std;

const int N = 3e3 + 7;
using ll = long long;

int n, a[N];
ll dp1[N][N], dp2[N][N];
bool vis1[N][N], vis2[N][N];

ll rec2(int, int);

ll rec1(int i, int j) {
	if(i > j)
		return 0;
    if(vis1[i][j])
        return dp1[i][j];
    
    vis1[i][j] = true;
	ll ans = rec2(i + 1, j) + a[i];
	ans = max(ans, rec2(i, j - 1) + a[j]);

	return dp1[i][j] = ans;
}

ll rec2(int i, int j) {
    if(i > j)
        return 0;
    if(vis2[i][j])
        return dp2[i][j];

    vis2[i][j] = true;
    ll ans = rec1(i + 1, j) - a[i];
    ans = min(ans, rec1(i, j - 1) - a[j]);

    return dp2[i][j] = ans;
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++)
    	cin >> a[i];

    cout << rec1(1, n);
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