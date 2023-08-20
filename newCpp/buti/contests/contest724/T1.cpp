#include <bits/stdc++.h>
#define fup(i, s, n) for (int i = s; i <= n; i++)
#define fdn(i, n, s) for (int i = n; i >= s; i--)
using namespace std;
using i64 = long long;
using pii = pair<i64, i64>;
constexpr int mod = 998244353;
constexpr int MAXN_32 = 2e9;
constexpr int MAXN = 1e8;
constexpr i64 MAXN_64 = 1e18;
int t = 1;
bool isPrime(i64 k)
{
    if (k == 1)
        return 0;
    for (int i = 2; i * i <= k; i++)
        if (k % i == 0)
            return 0;
    return 1;
}
void solve()
{
    i64 n, sum = 0, cnt = 0;
    cin >> n;
    // assert(0);
    vector<i64> a(n);
    for (auto &i : a)
        cin >> i, cnt += isPrime(i), sum += i;
    if (cnt == n)
    {
        cout << "Yes\n";
        return;
    }
    if (n == 1 && !cnt)
    {
        cout << "No\n";
        return;
    }
    else if (n == 2)
    {
        if (sum & 1)
        {
            if (sum >= 3 && isPrime(sum - 2))
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        else
        {
            if (sum >= 4)
                cout << "Yes\n";
            else
                cout << "No\n";
        }
        return;
    }
    if ((!(sum & 1)) && (sum >= 2 * n))
    {
        cout << "Yes\n";
        return;
    }
    else
    {
        if (sum & 1)
        {
            sum -= 3;
            if ((!(sum & 1)) && (sum >= 2 * (n - 1)))
            {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    // cin>>t;
    // assert(0);
    while (t--)
        solve();
    return 0;
}