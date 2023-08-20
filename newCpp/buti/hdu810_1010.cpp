#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
unordered_map<int, bool> hash1;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

bool is_square(int x)
{
    int k = sqrt(x);
    if (k * k == x)
        return true;
    return false;
}
void solve()
{
    int a, b;
    cin >> a >> b;
    int d = abs(b - a);
    int k = sqrt(d);
    if (k * k == d)
        cout << 1 << endl;
    else
    {
        if (d % 4 == 0 || d % 2 == 1)
        {
            cout << 2 << endl;
            return;
        }
        else 
        {
            int m = sqrt(d);
            for (int i = 1; i <= m; i += 2)
            {
                if (is_square(d - i * i))
                {
                    cout << 2 << endl;
                    return;
                }
            }
            cout << 3 << endl;
        }
    }
}

int main()
{
    ios;
    int n = 2e9;

    int t = 1;
    cin >> t;

    while (t--)
    {
        solve();
    }
    return 0;
}
