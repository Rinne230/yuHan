#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;

void solve()
{
    int n, m;
    cin >> n >> m;
    if (n > m){
        swap(n, m);
    }
    if (n == 1 && m > 3){
        cout << (m + 1) / 2 << endl;
        return;
    }
    if (m % 3 == 0 || n % 3 == 0){
        cout << 2 << endl;
        return;
    }
    cout << 1 << endl;
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
