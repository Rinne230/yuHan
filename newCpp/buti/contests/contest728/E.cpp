#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
queue<tuple<int, int, int>> st;

void add(int x, int y, int len)
{
    if (len <= 7)
    {
        st.push({x, y, len});
        return;
    }
    if (len % 2 == 1)
    {
        add(x, y, (len / 2));
        add(x + (len / 2), y, (len / 2) + 1);
        add(x, y + (len / 2), (len / 2) + 1);
        add(x + (len / 2), y + (len / 2), (len / 2) + 1);
    }
    else
    {
        add(x, y, (len / 2));
        add(x + (len / 2), y, (len / 2));
        add(x, y + (len / 2), (len / 2));
        add(x + (len / 2), y + (len / 2), (len / 2));
    }
    st.push({x, y, len});
}

void solve()
{
    int n;
    cin >> n;
    ll cnt = 0;
    if (n <= 7)
    {
        cout << 1 << endl;
        cout << 1 << " " << 1 << " " << n << endl;
        return;
    }
    else
    {
        add(1, 1, n);
    }
    cnt = st.size();
    cout << cnt << endl;
    while (!st.empty())
    {
        auto &[x, y, z] = st.front();
        cout << x << " " << y << " " << z << endl;
        st.pop();
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