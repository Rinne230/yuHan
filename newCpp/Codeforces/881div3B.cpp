#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll a[maxn];
void solve(int n){
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ll res = 0, cnt = 0;
    ll lst = 0;
    for (int i = 1; i <= n; ++i){
        res += a[i] > 0 ? a[i] : -a[i];
        if (a[i] > 0 && lst < 0) cnt++;
        if (a[i]) lst = a[i];
    }
    if (lst < 0) cnt++;
    printf("%lld %lld\n", res, cnt);
}
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        solve(n);        
    }

    return 0;
}