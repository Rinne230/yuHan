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
    int n, ans = 0;
    cin >> n;
    unordered_map<ll, ll> cnt;
    char lstopt;
    ll lstnum;
    while (n--)
    {
        char ch;
        cin >> ch;
        if (ch == '+')
        {
            ll x;
            cin >> x;
            if (!cnt[x])
            {
                ans++;
                cnt[x] = 1;
            }
            else
                cnt[x]++;
            lstopt = '+';
            lstnum = x;
        }
        else if (ch == '-')
        {
            ll x;
            cin >> x;
            if (cnt[x] == 1)
            {
                ans--;
                cnt[x] = 0;
            }
            else
                cnt[x]--;
            lstopt = '-';
            lstnum = x;
        }
        else if (ch == '!')
        {
            if (lstopt == '-')
            {
                ll x = lstnum;
                if (!cnt[x])
                {
                    ans++;
                    cnt[x] = 1;
                }
                else
                    cnt[x]++;
                lstopt = '+';
                lstnum = x;
            }
            else if (lstopt == '+')
            {
                ll x = lstnum;
                if (cnt[x] == 1)
                {
                    ans--;
                    cnt[x] = 0;
                }
                else
                    cnt[x]--;
                lstopt = '-';
                lstnum = x;
            }
        }
        else if (ch == '?')
        {
            cout << ans << endl;
        }
    }
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