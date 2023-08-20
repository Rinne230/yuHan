#include <bits/stdc++.h>
#define fup(i, s, n) for (int i = s; i <= n; i++)
#define fdn(i, n, s) for (int i = n; i >= s; i--)
using namespace std;
using i64 = long long;
using pid = pair<int, double>;
using pii = pair<i64, i64>;
constexpr int mod = 998244353;
constexpr i64 MAXN = 1e9;
void solve()
{
    int n;
    bool status = 0;
    int winner1 = -1, winner2 = -1;
    cin >> n;
    string s;
    cin >> s;
    int l = 0, r = n - 1;
    while (l <= r)
    {
        if (l == r)
        {
            if (status != (s[l] - '0'))
                winner1 = status ^ 1;
            break;
        }
        int cnt = 0;
        if ((s[l] - '0') == status)
            cnt++;
        if ((s[r] - '0') == status)
            cnt++;
        if (!cnt)
        {
            winner1 = status ^ 1;
            break;
        }
        else if (cnt == 1)
        {
            if ((s[l] - '0') == status)
                l++;
            else
                r--;
        }
        else
        {
            if ((s[l + 1] - '0') == status || (s[r - 1] - '0') == status)
            {
                winner1 = status;
                break;
            }
            if (l + 2 <= r)
            {
                if ((s[l + 2] - '0') != status)
                    r--;
                else
                    l++;
            }
            else
                l++;
        }
        status ^= 1;
    }
    if (~winner1)
    {
        if (winner1)
            cout << "1\n";
        else
            cout << "0\n";
    }
    else
        cout << "-1\n";
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}