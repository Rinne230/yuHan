#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;

void solve()
{
    int n, cnt = 0;
    cin >> n;
    string s;
    cin >> s;
    string s1 = s;
    reverse(s1.begin(), s1.end());
     for (int i = 0; i < n; ++i)
        {
            if (s[i] == '0')
                cnt++;
        }
    if (s1 == s)
    {
        if (cnt == 1 || cnt % 2 == 0)
        {
            cout << "BOB" << endl;
        }
        else
        {
            cout << "ALICE" << endl;
        }
    }else{
        if (cnt == 2 && n & 1 && s[n - 1 >> 1] == '0') cout << "DRAW" << endl;
        else cout << "ALICE" << endl;
    }
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