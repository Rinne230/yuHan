#include <iostream>

using namespace std;

typedef long long ll;

ll ksm(ll a, ll b, int mod)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        ll a, p;
        cin >> a >> p;
        if (a % p == 0)
        {
            cout << "impossible" << endl;
        }
        else
        {
            cout << ksm(a, p - 2, p) << endl;
        }
    }
    return 0;
}
