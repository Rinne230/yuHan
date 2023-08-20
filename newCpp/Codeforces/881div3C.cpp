#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll solve(ll n){
    ll res = 0;
    while(n){
        res += n;
        n >>= 1;
    }
    return res;
}
int main(){
    ll t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        printf("%lld\n", solve(n));
    }
    return 0;
}