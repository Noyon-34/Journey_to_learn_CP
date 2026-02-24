#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7, M = 2e5 + 7, inf = 1e9 + 9;;
using ll = long long;

int t[M * 4];

void update(int n, int b, int e, int i, int v) {
  if (i < b or e < i) return;
  if (b == e) {
    t[n] = max(t[n], v);
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  update(l, b, mid, i, v);
  update(r, mid + 1, e, i, v);
  t[n] = max(t[l], t[r]);
}

int query(int n, int b, int e, int i, int j) {
  if (e < i or j < b) return -inf;
  if (b >= i and e <= j) {
    return t[n];
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  return max(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

int a[N], dp[N];
void solve() {
    int n; cin >> n;
    set<int> s;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
        s.insert(a[i]);
    }

    map<int, int> mp;
    int id = 0;
    for(auto it: s) {
        mp[it] = ++id;
    }
    for(int i = 1; i <= n; i++) {
        a[i] = mp[a[i]];
    }

    for(int i = 1; i <= n; i++) {
    	dp[i] = 1;
    	// for(int j = 1; j < i; j++) {
    	// 	if(a[j] < a[i])
    	// 		dp[i] = max(dp[i], dp[j] + 1);
    	// } 
    	if(a[i] != 1) {
    		int mx = query(1, 1, M, 1, a[i] - 1);
    		mx++;
    		dp[i] = max(mx, dp[i]);
    	}
    	update(1, 1, M, a[i], dp[i]);
    }

    int ans = 0;
    for(int i = 1; i <= n; i++) {
    	ans = max(ans, dp[i]);
    }

    cout << ans;
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