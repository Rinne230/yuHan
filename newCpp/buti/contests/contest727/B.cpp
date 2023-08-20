#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;

void solve()
{
    double n;
    cin >> n;
    if (n == 2)
    {
        double f = 1;
        printf(" %.9f", f);
        cout << ' ';
        printf("%.9f\n", f);
        return;
    }
    double x = (n - 1) * (n - 2);
    double y = n - 1;
    double ans = 0;
    ans = (y + x) / (y + x / 2);
    double f = 2;

    printf("%.9lf", ans);
    printf(" %.9lf\n", f);
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