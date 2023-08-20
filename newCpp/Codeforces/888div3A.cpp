#include<bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;

void solve(){
    int n, m, k, H;
    ll cnt = 0;
    cin >> n >> m >> k >> H;
    for (int i = 1, a; i <= n; ++i){
        cin >> a;
        if (abs(a - H) >= k && abs(a - H) <= (m - 1) * k && abs(a - H) % k == 0){
            cnt++;
        }
    }
    cout << cnt << endl;
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