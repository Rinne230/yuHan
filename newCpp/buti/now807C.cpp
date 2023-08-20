#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

ll b[maxn], a[maxn], num[30];

void solve()
{
    ll n, k, sum = 0;
    cin >> n >> k;
    a[1] = 0;
    b[0] = 0;
    for (int i = 0; i <= 29; ++i) num[i] = -1;
    for (int i = 1; i <= n - 1; ++i){   
        cin >> b[i];
        b[i] = b[i - 1] ^ b[i];
    }
    for (int i = 1; i <= n - 1; ++i)
        for (int j = 29; j >= 0; --j)
            if ((b[i] >> j & 1) != (b[i - 1] >> j & 1)){
                if (num[j] == -1) num[j] = (b[i - 1] >> j & 1);
                else if (num[j] != (b[i - 1] >> j & 1)) {
                    cout << -1 << endl;
                    return;
                }
                break;
            }
    k--;
    for (int i = 29; i >= 0; --i) if (num[i] == -1) sum = sum * 2 + 1;
    if (sum < k){
        cout << -1 << endl;
        return;
    }
    ll idx = 0;
    while (k){
        while (num[idx] != -1) idx++;
        num[idx] = (k & 1);
        k >>= 1;
    }
    for (int i = 0; i <= 29; ++i) if(num[i] == -1) num[i] = 0;
    for (int i = 29; i >= 0; --i) a[1] = (a[1] << 1) + num[i];
    for (int i = 2; i <= n; ++i){
        a[i] = a[i - 1] ^ (b[i - 1] ^ b[i - 2]);
    }
    if (a[n] >= pow(2, 30)){
        cout << -1 << endl;
        return;
    }
    for (int i = 1; i <= n; ++i) cout << a[i] << " ";
    cout << endl;
}

int main()
{
    ios;
    int t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}