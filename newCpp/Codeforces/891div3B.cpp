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
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] >= '5')
        {
            while (i > 0 && s[i - 1] >= '4')
                i--;
            for (int j = i; j < s.size(); ++j)
                s[j] = '0';
            if (i)
                s[i - 1]++;
            else
                s.insert(s.begin(), '1');
            break;
        }
    }
    cout << s << '\n';
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