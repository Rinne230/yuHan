#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define rep(i, j, k) for (int i = (j); i <= (k); i++)
#define per(i, j, k) for (int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

struct node
{
    int vcpu, vram, agpu, pps, price, idxx;
    double cgpu;
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<node> a(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        a[i].idxx = i;
        cin >> a[i].vcpu >> a[i].vram >> a[i].cgpu >> a[i].agpu >> a[i].pps >> a[i].price;
    }
    sort(a.begin() + 1, a.end(), [&](node x, node y)
         {
            if (x.price == y.price) return x.idxx < y.idxx;
            return x.price < y.price; });

    while (m--)
    {
        int vcpu, vram, agpu, pps;
        double cgpu;
        cin >> vcpu >> vram >> cgpu >> agpu >> pps;
        for (int i = 1; i <= n; ++i)
            if (vcpu <= a[i].vcpu && vram <= a[i].vram && cgpu <= a[i].cgpu && agpu <= a[i].agpu && pps <= a[i].pps){
                cout << a[i].idxx << endl;
                break;
            }
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