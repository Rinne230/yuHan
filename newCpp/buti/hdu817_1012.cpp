#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    int mn = inf;
    int mx = 0;
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        mn = min(mn, a[i]);
        mp[a[i]]++;
        if (mp[a[i]] >= mx) mx = mp[a[i]];
    }
    if (mp[mn] == mx){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main(){
    ios;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}