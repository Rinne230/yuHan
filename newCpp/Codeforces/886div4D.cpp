#include<bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
ll a[maxn];

void solve(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    ll ans = 1;
    ll len = 1;
    for (int i = 2; i <= n; ++i){
        if (a[i] - a[i - 1] <= k) {
            len++;
            ans = ans > len ? ans : len;
        }else{
            len = 1;
        }
    }
    cout << n - ans << endl;
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