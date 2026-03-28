// https://cses.fi/problemset/task/1145
// Solved on 24.03.26

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7;
using ll = long long;

int n, a[N];

void solve() {
    cin >> n;
    vector<int> v(n), a;
    for(int i = 0; i < n; i++) 
    	cin >> v[i];

    for(int i = 0; i < n; i++) {
    	auto it = lower_bound(a.begin(), a.end(), v[i]);
    	if(it == a.end())
    		a.push_back(v[i]);
    	else
    		*it = v[i];
    }

    cout << a.size();
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