#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll n;
vector<ll>a;
vector<ll> calc(ll l, ll r) {
	vector<ll>res;
	for (ll i = r + 1; i < n; i++) {
		res.push_back(a[i]);
	}
	for (ll i = r; i >= l; i--) {
		res.push_back(a[i]);
	}
	for (ll i = 0; i < l; i++) {
		res.push_back(a[i]);
	}
	return res;
}

void solve() {
	ll r = 0;
	cin >> n;
	a.resize(n, 0);
	vector<ll> res(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
        if (a[i] == n)
            r = i;
	}
	if (r == 0) {
		for (ll i = 0; i < n; i++) {
			res[i] = 0;
			if (a[i] == n - 1) {
				r = i;
			}
		}
	}
	if (r != n - 1) {
		r--;
	}
	for (ll l = 0; l <= r; l++) {
		auto t = calc(l, r);
		if (t > res) {
			res = t;
		}
	}
	for (auto x : res) {
		cout << x << " ";
	}
	cout << endl;
}

int main(){
    ios;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
