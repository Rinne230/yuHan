#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 1e7 + 7;
const ll inf = 0x3f3f3f3f;

int num[60];
ll dp[60][60];

ll dfs(int pos, int sum, bool lim, int k){
    if (pos == 0) return sum == k;
    if ((!lim) && dp[pos][sum] != -1) return dp[pos][sum];
    int up;
    if (lim) up = num[pos];
    else up = 1;
    dp[pos][sum] = 0;
    for (int i = 0; i <= up; ++i){
        if (i == 1) dp[pos][sum] += dfs(pos - 1, sum + 1, lim && (i == up), k);
        else dp[pos][sum] += dfs(pos - 1, sum, lim && (i == up), k);
    }
    return dp[pos][sum];
}

ll fastpow(ll a, ll n)
{
    ll ans = 1;
    a %= mod;
    while (n)
    {
        if (n & 1)
            ans = ans * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return ans;
}

void solve()
{
    ll n;
    cin >> n;
    int len = 0;
    while(n){
        num[++len] = n % 2;
        n >>= 1;
    }
    ll ans = 1;
    for (int i = 1; i <= len; ++i){
        memset(dp, -1, sizeof dp);
        ll cnt = dfs(len, 0, true, i);
        ans = ans * fastpow(i, cnt) % mod;
    }
    cout << ans << endl;
}

int main()
{
    ios;
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}