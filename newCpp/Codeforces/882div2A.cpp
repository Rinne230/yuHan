#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int n, k;
int a[110];

void solve(){
    ll res = 0;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<int> d;
    for (int i = 2; i <= n; ++i)
        d.push_back(abs(a[i] - a[i - 1]));
    sort(d.begin(), d.end());
    for (int i = 0; i < n - k; ++i)
        res += d[i];
    cout << res << endl;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}