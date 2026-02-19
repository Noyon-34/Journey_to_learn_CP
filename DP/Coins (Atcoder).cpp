#include<bits/stdc++.h>
using namespace std;

const int N = 3e3 + 7;
using ll = long long;

int n;
bool vis[N][N];
double p[N], dp[N][N];

double rec(int i, int head, int tail) {
	if(i > n) {
		if(head > tail)
			return 1;
		else
			return 0;
	}

	if(vis[i][head])
		return dp[i][head];

	vis[i][head] = true;
	double ans = p[i] * rec(i + 1, head + 1, tail);
	ans += (1 - p[i]) * rec(i + 1, head, tail + 1);

	return dp[i][head] = ans;
}
void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++) {
    	cin >> p[i];
    }

    cout << fixed << setprecision(10) << rec(1, 0, 0) << '\n';
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