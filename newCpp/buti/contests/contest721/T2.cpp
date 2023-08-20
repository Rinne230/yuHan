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
    int cnt1 = 0, cnt2 = 0;
    for (int i = 1; i <= n - (n & 1); ++i)
    {
        for (int j = 1; j <= m; ++j)
            if (i & 1)
            {
                if (j % 5 == 0)
                {
                    cout << "x";
                    cnt1++;
                }

                else
                {
                    cout << "o";
                    cnt2++;
                }
            }
            else
            {
                if (j % 5 == 0)
                {
                    cout << "o";
                    cnt2++;
                }

                else
                {
                    cout << "x";
                    cnt1++;
                }
            }
        cout << endl;
    }
    if (n & 1)
    {
        for (int i = 1; i <= m; i++)
            if (i & 1){
                cout << "x";
                cnt1++;
            }
                
            else{
                cout << "o";
                cnt2++;
            }
        cout << endl;
    }
    //cout << cnt1 << " " << cnt2 << endl;
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