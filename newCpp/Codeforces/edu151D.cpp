#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;
typedef long long ll;
const int maxn = 3e5 + 10;
ll a[maxn], maxh[maxn], sum[maxn];

void solve() {
	ll n, summ = 0, maxx = 0, ans = 0;
	cin >> n;
	maxh[n + 1]=0;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = n; i >= 1; --i) {
		summ += a[i];
		maxh[i] = max(maxh[i + 1], summ);
	}
	for (int i = 0; i <= n; ++i) {
		ll k = sum[i] + maxh[i + 1];
		if(k > maxx) {
			maxx = k;
			ans = sum[i];
		}
	}
	cout << ans <<endl;
}

int main(){
    ios;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}