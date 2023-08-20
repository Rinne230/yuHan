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
    int m = n * (n - 1) / 2;
    vector<int> b(m);
    for (int i = 0; i < m; ++i) cin >> b[i];
    sort(b.begin(), b.end());
    for (int i = 1, j = 0; i <= n; ++i){
        cout << b[j] << " ";
        j += n - i;
        j = min(j, m - 1);
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