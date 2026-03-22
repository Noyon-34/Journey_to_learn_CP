// https://atcoder.jp/contests/dp/tasks/dp_f
// Solved on 21.03.26

#include<bits/stdc++.h>
using namespace std;

const int N = 3e3 + 7;
using ll = long long;

string s, t;
int n, m, dp[N][N];

int rec(int i, int j) {
	if(i == n or j == m)
		return 0;
	if(dp[i][j] != -1)
		return dp[i][j];

	int ans = 0;
	ans = rec(i + 1, j);
	ans = max(ans, rec(i, j + 1));
	if(s[i] == t[j]) {
		ans = max(ans, rec(i + 1, j + 1) + 1);
	}

	return dp[i][j] = ans;
}

void print(int i, int j) {
	if(i == n or j == m)
		return;

	if(s[i] == t[j]) {
		cout << s[i];
		print(i + 1, j + 1);
		return;
	}

	int a = rec(i, j + 1);
	int b = rec(i + 1, j);
	
	if(a >= b)
		print(i, j + 1);
	else
		print(i + 1, j);
}
void solve() {
    cin >> s >> t;
    n = s.size(), m = t.size();

    memset(dp, -1, sizeof dp);
    print(0, 0);
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