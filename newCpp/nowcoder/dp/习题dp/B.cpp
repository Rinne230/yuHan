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
    vector<int> f(n + 1, 0);//f[i]表示前i个人中有多少人说了真话
    map<pll, int> mp;
    vector<vector<int>> l(n + 1);  
    for (int i = 1; i <= n; ++i){
        ll s, t;
        cin >> s >> t;
        s++, t = n - t;
        mp[{s, t}]++;
        l[t].push_back(s);
    }
    for (int i = 1; i <= n; ++i){
        f[i] = f[i - 1];
        for(auto j : l[i]){
            f[i] = max(f[i], f[j - 1] + min(i - j + 1, mp[{j, i}]));
        }
    }
    cout << n - f[n] << endl;
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