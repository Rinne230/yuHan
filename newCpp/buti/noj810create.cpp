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

void solve()
{
    int cnt1 = 0, cnt2 = 0;
    string s;
    cin >> s;
    char lstch;
    int lstid = s.length();
    for (int i = 0; i < s.length(); ++i)
        if (s[i] != '.')
        {
            lstch = s[i], lstid = i;
            if (lstch == 'A')
                cnt1++;
            else
                cnt2++;
            break;
        }

    ll tmp = 0;
    for (int i = lstid + 1; i < s.length(); ++i)
    {
        if (s[i] == '.')
        {
            tmp++;
            continue;
        }
        if (s[i] == lstch)
        {
            if (s[i] == 'A')
                cnt1 += tmp + 1;
            else
                cnt2 += tmp + 1;
            lstch = s[i];
            tmp = 0;
        }
        else
        {
            if (s[i] == 'A')
                cnt1++;
            else
                cnt2++;
            lstch = s[i];
            tmp = 0;
        }
    }
    cout << cnt1 << " " << cnt2 << endl;
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