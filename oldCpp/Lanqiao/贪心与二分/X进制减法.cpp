#include <bits/stdc++.h>
#define mod 1000000007
using namespace std;
typedef long long ll;
int main(){
    int N, a, b;
    int A[101], B[101];
    cin >> N >> a;
    for (int i = a; i >= 1; --i) cin >> A[i];
    cin >> b;
    for (int i = a; i >= 1; --i) cin >> B[i];
    ll w = 0;
    ll ans = 0;
    ll total = 1;
    for (int i = 1; i <= a; ++i){
        w = max(max(A[i], B[i]) + 1, 2) % mod;
        ans = (ans + (A[i] - B[i]) * total) % mod;
        total = (total * w) % mod;
    }
    cout << ans << endl;
    return 0;
}