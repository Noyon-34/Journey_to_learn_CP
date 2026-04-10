#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
using ll = long long;
const ll inf = 1e18 + 9;

int n, a[N], h[N];
ll dp[N];
ll t[N * 4];

void upd(int n, int b, int e, int i, ll v) {
  if (i < b or e < i) return;
  if (b == e) {
    t[n] = max(t[n], v);
    return;
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  upd(l, b, mid, i, v);
  upd(r, mid + 1, e, i, v);
  t[n] = max(t[l], t[r]);
}

ll query(int n, int b, int e, int i, int j) {
  if (e < i or j < b) return -inf;
  if (b >= i and e <= j) {
    return t[n];
  }
  int mid = (b + e) / 2, l = 2 * n, r = 2 * n + 1;
  return max(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

void solve() {
    cin >> n;
    for(int i = 1; i <= n; i++)
    	cin >> h[i];
    for(int i = 1; i <= n; i++)
    	cin >> a[i];

    for(int i = 1; i <= n; i++) {
        dp[i] = a[i];
        // int mx = 0;
        // for(int j = 1; j < i; j++) {
        //     if(h[j] < h[i]) {
        //         mx = max(mx, dp[j]);
        //     }
        // }
        if(h[i] != 1) {
            ll mx = query(1, 1, n, 1, h[i] - 1);
            dp[i] = max(dp[i], mx + a[i]);
        }
        upd(1, 1, n, h[i], dp[i]);
    }
    ll ans = 0;
    for(int i = 1; i <= n; i++) {
        ans = max(ans, dp[i]);
    }
    cout << ans << '\n';
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