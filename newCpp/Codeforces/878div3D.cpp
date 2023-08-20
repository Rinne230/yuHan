#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll n, t, a[maxn];

bool check(ll tim){
    ll x = a[1], cnt = 0;
    for (int i = 1; i <= n; ++i){
        if (abs(a[i] - x) > tim * 2) x = a[i], cnt++;
    }   
    if (cnt > 2) return false;
    return true;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> t;
    while(t--){
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + n + 1);
        ll l = 0, r = a[n];
        while(l <= r){
            ll mid = l + (r - l) / 2;
            if(check(mid)) r = mid - 1;
            else l = mid + 1;
        }
        cout << l << '\n';
    }
    return 0;
}