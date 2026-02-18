#include<bits/stdc++.h>
using namespace std;

const int N = 1e3 + 7;
using ll = long long;

int a[N], dp[N];
void solve() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    }

    vector<int> p(n + 1, -1);
    for(int i = 1; i <= n; i++) {
    	dp[i] = 1;
    	for(int j = 1; j < i; j++) {
    		if(a[j] < a[i] && dp[i] < dp[j] + 1) {
    			dp[i] = dp[j] + 1;
    			p[i] = j;
    		}
    	} 
    }

    int ans = 0, pos = 0;
    for(int i = 1; i <= n; i++) {
    	if(ans < dp[i]) {
    		ans = dp[i];
    		pos = i;
    	}
    }

    vector<int> subsq;
   	while(pos != -1) {
   		subsq.push_back(a[pos]);
   		pos = p[pos];
   	}
   	reverse(subsq.begin(), subsq.end());
    cout << ans << '\n';

    for(auto it: subsq)
    	cout << it << ' ';
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