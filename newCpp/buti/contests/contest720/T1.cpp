#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
string s;

void solve()
{
    cin >> s;
    int ans = 0;
    int len = 0;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == s[i - 1] && i > 0)
        {
            len++;
        }
        else
        {
            if (len > 0)
            {
                ans += len;
            }
            len = 0;
        }
    }
    if (len > 0)
    {
        ans += len;
    }
    cout << ans << endl;
}

int main()
{
    ios;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}