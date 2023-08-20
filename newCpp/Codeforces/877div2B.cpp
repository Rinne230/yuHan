#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];

void solve(){
    int n;
    cin >> n;
    for (int i = 1, x; i <= n; ++i){
        cin >> x;
        a[x] = i;
    }
    if ((a[n] - a[1]) * (a[n] - a[2]) < 0) cout << 1 << " " << 1 << endl;
    else if (a[n] > a[1] && a[n] > a[2]) cout << a[n] << " " << max(a[1], a[2]) << endl;
    else cout << a[n] << " " << min(a[1], a[2]) << endl;
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