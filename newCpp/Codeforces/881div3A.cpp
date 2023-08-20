#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 51;
int a[maxn];
void solve(int n){
    for(int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    ll res = 0;
    for (int i = n; i > (n >> 1); --i){
        res += a[i] - a[n - i + 1];
    }
    printf("%lld\n", res);
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        solve(n);
    }

    return 0;
}