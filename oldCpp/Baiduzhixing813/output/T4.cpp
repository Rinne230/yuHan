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
ll p, q;
int tmp1, tmp2;
ll n1, n2, n3;

bool check(int z)
{
    ll res = q - p * n1 - tmp2 * z;
    if (res < 0)
        return false;
    if (res % tmp1 != 0)
        return false;
    ll y = res / tmp1;
    if (y + z <= p)
        return true;
    return false;
}

void solve()
{
    cin >> p >> q;
    cin >> n1 >> n2 >> n3;
    tmp1 = n2 - n1, tmp2 = n3 - n1;
    ll l = 0, r = 100000000;
    while (l < r)
    {
        ll mid = (l + r + 1) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    //cout << l << endl;
    bool flag = false;
    for (int i = 0; i <= l; ++i){
        if (check(i))
        {
            cout << i << " " << r << endl;
            flag = true;
            break;
        }
    }
    if (!flag) cout << -1 << endl;
}

int main()
{
    ios;
    int t = 1;
    // cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}