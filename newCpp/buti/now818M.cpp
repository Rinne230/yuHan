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
    int a, b, c;
    char ch;
    cin >> a >> ch >> b >> ch >> c;
    if (a + b == c)
    {
        cout << "Yes" << endl;
        cout << a << " + " << b << " = " << c << endl;
        return;
    }
    int tmp = a + b;
    if (a + b > c)
    {
        string s1 = to_string(tmp);
        string s2 = to_string(c);
        if (s1.length() - s2.length() == 1)
        {
            bool flag = true;
            bool ok = true;
            for (int i = 0, j = 0; i < s1.length() && j < s2.length(); ++i, ++j)
            {
                if (!flag && s1[i] != s2[j])
                {
                    ok = false;
                    break;
                }
                if (s1[i] != s2[j])
                {
                    flag = false;
                    i++;
                }
            }
            if (ok)
            {
                cout << "Yes" << endl;
                cout << a << " + " << b << " = " << a + b << endl;
                return;
            }
        }
    }
    if (a + b < c)
    {
        int tmp = c - b;
        string s1 = to_string(tmp);
        string s2 = to_string(a);
        if (s1.length() - s2.length() == 1)
        {
            bool flag = true;
            bool ok = true;
            for (int i = 0, j = 0; i < s1.length() && j < s2.length(); ++i, ++j)
            {
                if (!flag && s1[i] != s2[j])
                {
                    ok = false;
                    break;
                }
                if (s1[i] != s2[j])
                {
                    flag = false;
                    i++;
                }
            }
            if (ok)
            {
                cout << "Yes" << endl;
                cout << c - b << " + " << b << " = " << c << endl;
                return;
            }
        }
    }
    tmp = c - a;
    string s1 = to_string(tmp);
    string s2 = to_string(b);
    if (s1.length() - s2.length() == 1)
    {
        bool flag = true;
        bool ok = true;
        for (int i = 0, j = 0; i < s1.length() && j < s2.length(); ++i, ++j)
        {
            if (!flag && s1[i] != s2[j])
            {
                ok = false;
                break;
            }
            if (s1[i] != s2[j])
            {
                flag = false;
                i++;
            }
        }
        if (ok)
        {
            cout << "Yes" << endl;
            cout << a << " + " << c - a << " = " << c << endl;
            return;
        }
    }
    cout << "No" << endl;
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