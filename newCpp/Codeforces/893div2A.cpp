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

int a, b, c;

void solve()
{
    cin >> a >> b >> c;
    int sum1 = a + ceil((c + 0.00) / 2);
    int sum2 = b + (c >> 1);
    if (sum1 > sum2)
        cout << "First" << endl;
    else
        cout << "Second" << endl;
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