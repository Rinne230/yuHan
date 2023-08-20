#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 1e5 + 10;
const ll mod = 1e9 + 7;

template <typename Tp>
inline void read(Tp &x)
{
    x = 0;
    int f = 0;
    char ch = getchar();
    while (ch != '-' && (ch < '0' || ch > '9'))
        ch = getchar();
    if (ch == '-')
        f = 1, ch = getchar();
    while (ch >= '0' && ch <= '9')
        x = x * 10 + ch - '0', ch = getchar();
    if (f)
        x = -x;
}

ll nxt[maxn][31], add[maxn][31], che[maxn][31];

void solve()
{
    ll n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i)
        cin >> che[i][0];
    for (int i = 1; i <= n; ++i)
        cin >> add[i][0];
    for (int i = 1; i <= n; ++i)
    {
        cin >> nxt[i][0];
    }
    for (int j = 1; j <= 30; ++j)
    {
        for (int i = 1; i <= n; ++i)
        {
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
            che[i][j] = (che[i][j - 1] * che[nxt[i][j - 1]][j - 1]) % mod;
            add[i][j] = (add[i][j - 1] * che[nxt[i][j - 1]][j - 1] + add[nxt[i][j - 1]][j - 1]) % mod;
        }
    }
    ll st, step, y;
    while (q--)
    {
        cin >> st >> step >> y;
        // st = pre[st];
        st = nxt[st][0];
        for (int j = 30; j >= 0; --j)
        {
            if (step & (1ll << j))
            {
                y = (y * che[st][j] + add[st][j]) % mod;
                st = nxt[st][j];
            }
        }
        cout << y << endl;
    }
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

/*
1
5 5
2 3 1 2 4
3 4 2 1 2
2 3 5 1 4
1 2 4
2 4 5
3 3 4
4 5 2
5 2 1
*/
