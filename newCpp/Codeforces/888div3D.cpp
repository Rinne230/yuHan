#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
ll a[maxn];

void solve()
{
    int n;
    cin >> n;
    set<ll> se;
    for (int i = 1; i < n; i++)cin >> a[i];
    for (int i = 1; i < n; i++) se.insert(a[i] - a[i - 1]);
    int cur = 0;
    ll sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!se.count(i))
        {
            cur++;
            sum += i;
        }
    }
    if (cur == 1){
        cout << "YES" << endl;
        return;
    }
    else if (cur == 2)
    {
        if (sum <= n)
        {
            int cnt = 0;
            for (int i = 1; i < n; i++)
            {
                if (a[i] - a[i - 1] == sum)
                    cnt++;
            }
            if (cnt == 2){
                cout << "YES" << endl;
                return;
            }
            cout << "NO" << endl;
            return;
        }
        else
        {
            if (se.count(sum)){
                cout << "YES" << endl;
                return;
            }
            cout << "NO" << endl;
            return;
        }
    }
    cout << "NO\n";
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