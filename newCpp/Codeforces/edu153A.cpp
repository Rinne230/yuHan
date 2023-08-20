#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

void solve()
{
    string s;
    string ss = "";
    cin >> s;
    if (s == "()")
    {
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    int len = s.length();
    for (int i = 0; i < len; ++i)
        ss += "()";
    bool flag = true;
    for (int i = 0; i < len; ++i)
        if (ss.substr(i, len) == s)
            flag = false;
    if (flag)
    {
        cout << ss << endl;
        return;
    }
    ss = "";
    for (int i = 0; i < len; ++i) ss += "(";
    for (int i = 0; i < len; ++i) ss += ")";
    cout << ss << endl;
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