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
    string s;
    cin >> s;

    s = '0' + s;
    unordered_map<char, int> st;
    vector<int> a(n + 10), b(n + 10);
    for (int i = 1; i < s.size(); ++i)
    {
        if (!st.count(s[i]))
            a[i]++;
        st[s[i]]++;
    }
    for (int i = 1; i < s.size(); ++i)
    {
        a[i] += a[i - 1];
    }
    st.clear();
    for (int i = s.size() - 1; i >= 1; --i)
    {
        if (!st.count(s[i]))
            b[i]++;
        st[s[i]]++;
    }
    for (int i = s.size() - 1; i >= 1; --i)
    {
        b[i] += b[i + 1];
    }

    int mx = 0;
    for (int i = 1; i + 1 < s.size(); ++i)
    {
        int ans = a[i] + b[i + 1];
        mx = max(ans, mx);
    }
    cout << mx << '\n';

    return;
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