#include<bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;

bool cmp(pll a, pll b){
    if (a.first == b.first) 
        return a.second < b.second;
    return a.first > b.first;
}
void solve(){
    int n, k;
    cin >> n >> k;
    vector<pll> a(n);
    for (int i = 0, t; i < n; ++i){
        cin >> t;
        t = (t - 1) % k + 1;
        a[i] = {t, i + 1};
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n; ++i){
        cout << a[i].second << " ";
    }
    cout << endl;
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