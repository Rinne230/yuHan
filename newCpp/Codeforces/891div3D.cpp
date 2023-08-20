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
    int mx = -0x7fffffff;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = 1, x; i <= n; ++i){
        cin >> x;
        a[i] -= x;
        mx = max(mx, a[i]);
        
    }
    ll cnt = 0;
    vector<int> ans;
    for (int i = 1; i <= n; ++i){
        if (a[i] == mx){
            cnt++;
            ans.push_back(i);
        }
    }
    cout << cnt << endl;
    for (auto i : ans){
        cout << i << " ";
    }
    cout << endl;
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