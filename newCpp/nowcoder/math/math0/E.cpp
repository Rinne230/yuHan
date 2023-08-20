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
const int N = 1e6 + 5;
 
int prime[N];
bool st[N];
int cnt;
int n;
ll a[N];
 
void get_prime() {
    st[1] = 1;
    for (int i = 2; i < N; i ++ ) {
        if (!st[i]) prime[cnt++] = i;
        for (int j = 0; prime[j] * i < N; j ++ ) {
            st[prime[j] * i] = 1;
            if (i % prime[j] == 0) break;
        }
    }
}
 
inline void solve() {
    cin >> n;
    if (st[n] == 0) {
        cout << "1 1" << endl;
        return;
    }
    int cj = 0;
    ll ans = 0, tmp = 1;
    for (int i = 0; i < cnt; i ++ ) {
        if (n == 1) break;
        int p = prime[i];
        cj = 0;
        if (n % p == 0) {
            while (n % p == 0) {
                ans ++;
                cj ++;
                n /= p;
            }
            tmp *= a[cj];
        }
    }
    cout << ans << ' ';
    ans = a[ans];
    cout << ans / tmp << endl;
}
 
int main() {

    int t;
    cin >> t;
    get_prime();
    ll res = 1;
    for (int i = 1; i <= 30; i ++ ) {
        res *= i;
        a[i] = res;
    }
    while (t--) solve();
    return 0;
}