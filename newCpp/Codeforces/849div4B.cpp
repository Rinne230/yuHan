#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;

void solve()
{
    int n;
    cin >> n;
    int x = 0, y = 0;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); ++i)
    {
        if (s[i] == 'U')
            y += 1;
        else if (s[i] == 'D')
            y -= 1;
        else if (s[i] == 'L')
            x -= 1;
        else
            x += 1;
        if (x == 1 && y == 1)
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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