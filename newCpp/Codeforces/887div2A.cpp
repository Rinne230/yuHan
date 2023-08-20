#include<bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
ll a[maxn];

void solve(){
    int n;
    cin >> n;
    ll d = 1e13 + 10;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n - 1; ++i){
        if (a[i] > a[i + 1]) d = 0;
    }
    if (d == 0){
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i <= n - 1; ++i) d = min(d, a[i + 1] - a[i]);
    cout << (d + 2) / 2 << endl; 
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