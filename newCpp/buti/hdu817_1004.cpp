#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;
typedef long long ll;

ll qmi(ll a, ll b)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = 1ll * a * a % mod;
        b >>= 1;
    }
    return res;
}

void solve()
{
    ll n;
    cin >> n;
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    ll a = 2 * n - 1;
    ll b = 3;
    b = qmi(b, mod - 2);
    cout << a * b % mod << endl;
}

void rd(int n)
{
    srand(time(NULL));
    int x = 2;
    long double e = 0;
    for (int i = 1; i <= 100000; i++)
    {
        int ok1 = 0, ok2 = 0, ok3 = 0, cnt = 0;
        if (x == 1)
            ok2 = 1;
        if (x == n)
            ok3 = 1;
        while (!ok1 && !(ok2 && ok3))
        {
            int y = rand() % n + 1;
            if (y == x + 1)
                ok3 = 1;
            if (y == x - 1)
                ok2 = 1;
            if (y == x)
                ok1 = 1;
            cnt++;
        }
        e += cnt;
    }
    cout << e / 100000 << "\n";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();
    // rd(5);

    return 0;
}