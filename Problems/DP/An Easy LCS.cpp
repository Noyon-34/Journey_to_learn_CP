// https://vjudge.net/problem/lightoj-1110
// Solved on 22.03.26

#include<bits/stdc++.h>
using namespace std;

const int N = 1e2 + 7;
using ll = long long;

string s, t;
int n, m;
bool vis[N][N];
string dp[N][N];

string rec(int i, int j) {
	if(i == n or j == m)
		return "";
	if(vis[i][j])
		return dp[i][j];

	string ans = "";
	if(s[i] == t[j]) {
		ans = string(1, s[i]) + rec(i + 1, j + 1);
	}
	else {
		string a = rec(i + 1, j);
		string b = rec(i, j + 1);

		if(a.size() > b.size())
			ans = a;
		else if(a.size() < b.size())
			ans = b;
		else
			ans = min(a, b);
	}
	
	vis[i][j] = true;
	return dp[i][j] = ans;
}


void solve(int cs) {
    cin >> s >> t;
    n = s.size(), m = t.size();

    memset(vis, false, sizeof vis);
    string ans = rec(0, 0);
    cout << "Case " << cs << ": ";
    cout << (ans.empty() ? ":(" : ans) << '\n';
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