#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
ll a[maxn];

void solve()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    if (n == 1 || k == 1)
    {
        cout << "YES" << endl;
        return;
    }

    if (a[1] == a[n]){
        ll cnt = 2;
        if (cnt == k){
            cout << "YES" << endl;
            return;
        }
        for (int i = 2; i <= n - 1; ++i){
            if (a[i] == a[1]){
                cnt++;
            }
            if (cnt == k){
                cout << "YES" << endl;
                return;
            }
        }
        cout << "NO" << endl;
        return;
    }

    ll lst = a[1], idx1 = 0, idx2 = 0;
    ll tmp = 1;
    for (int i = 2; i <= n; ++i)
    {
        if (a[i] == lst)
        {
            tmp++;
        }
        if (tmp == k)
        {
            idx1 = i;
            break;
        }
    }

    lst = a[n];
    tmp = 1;
    for (int i = n - 1; i >= 1; --i){
        
        if (a[i] == lst){
            tmp++;
        }
        if (tmp == k){
            idx2 = i;
            break;
        }
    }
    if (idx1 && idx2 && idx1 < idx2){
        cout << "YES" << endl;
        return;
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