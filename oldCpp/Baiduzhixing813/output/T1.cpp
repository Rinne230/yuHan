#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 1e18;

void solve()
{
    int n;
    cin >> n;
    vector<int> x(n + 1), y(n + 1), z(n + 1);
    ll sumx = 0, sumy = 0, sumz = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> x[i] >> y[i] >> z[i];
        sumx += x[i];
        sumy += y[i];
        sumz += z[i];
    }
    sort(x.begin() + 1, x.end());
    sort(y.begin() + 1, y.end());
    sort(z.begin() + 1, z.end());
    ll avex, avey, avez;
    avex = x[(n + 1) / 2];
    avey = y[(n + 1) / 2];
    avez = z[(n + 1) / 2];
    // cout << avex << " " << avey << " " << avez << endl;
    ll dex = inf, dey = inf, dez = inf;
    for (int k = -100; k <= 100; ++k)
    {
        ll dex1 = 0, dey1 = 0, dez1 = 0;
        for (int i = 1; i <= n; ++i)
        {
            dex1 += abs(x[i] - avex + k);
            dey1 += abs(y[i] - avey + k);
            dez1 += abs(z[i] - avez + k);
        }
        dex = min(dex1, dex);
        dey = min(dey1, dey);
        dez = min(dez1, dez);
    }
    // cout << dex << " " << dey << " " << dez << endl;

    ll chax = inf, chay = inf, chaz = inf;
    for (int i = 1; i <= n; ++i)
    {
        x[i] = x[i] + n - i + 1;
        y[i] = y[i] + n - i + 1;
        z[i] = z[i] + n - i + 1;
    }
    sort(x.begin() + 1, x.end());
    sort(y.begin() + 1, y.end());
    sort(z.begin() + 1, z.end());
    avex = x[(n + 1) / 2];
    avey = y[(n + 1) / 2];
    avez = z[(n + 1) / 2];
    for (int k = -100; k <= 100; ++k)
    {
        ll chaxx = 0, chayy = 0, chazz = 0;
        for (int i = 1; i <= n; ++i){
            chaxx += abs(x[i] - avex + k);
            chayy += abs(y[i] - avey + k);
            chazz += abs(z[i] - avez + k);
        }
        chax = min(chaxx, chax);
        chay = min(chayy, chay);
        chaz = min(chazz, chaz);
    }
    avex = x[n / 2];
    avey = y[n / 2];
    avez = z[n / 2];
    for (int k = -100; k <= 100; ++k)
    {
        ll chaxx = 0, chayy = 0, chazz = 0;
        for (int i = 1; i <= n; ++i){
            chaxx += abs(x[i] - avex + k);
            chayy += abs(y[i] - avey + k);
            chazz += abs(z[i] - avez + k);
        }
        chax = min(chaxx, chax);
        chay = min(chayy, chay);
        chaz = min(chazz, chaz);
    }
    ll ans = 0;

    //cout << chax << " " << chay << " " << chaz << endl;
    ans = min({dex + dey + chaz, dex + dez + chay, dey + dez + chax});
    cout << ans << endl;
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
/*
3
2 0 2
6 35 -87
0 184 -126
*/