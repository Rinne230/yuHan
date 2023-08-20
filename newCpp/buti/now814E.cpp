#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

void solve()
{
    int n, m;
    function<void(int, int, int, int, int)> work = [&](int posx, int posy, int x, int y, int cur)
    {
        if (posx >= n || posy >= m){
            cout << cur << endl;
            return;
        }
        if (x == 0 && y == 0){
            cout << cur << endl;
            return;
        }
        int len = min(x, y);
        if (x == y){
            cout << cur << endl;
            cout << posx << " " << posy << " " << len << endl;
            return;
        }
        else if (x < y){
            work(posx, posy + len, x, y - len, cur + 1);
            cout << posx << " " << posy << " " << len << endl;
        }else {
            work(posx + len, posy, x - len, y, cur + 1);
            cout << posx << " " << posy << " " << len << endl;
        }
    };
    cin >> n >> m;
    cout << "YES" << endl;
    work(0, 0, n, m, 1);
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