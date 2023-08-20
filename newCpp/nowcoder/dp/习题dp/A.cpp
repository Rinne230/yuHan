/**
 * @file 刷野
 * @brief 区间dp
 * @version 0.1
 * @date 2023-08-07
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 510;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

int n, a[maxn], b[maxn], dp[maxn][maxn];

void solve(){
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    for (int i = 1; i <= 500; ++i)
        for (int j = 1; j <= 500; ++j)
            if (j < i) dp[i][j] = 0;
            else dp[i][j] = inf;
    for (int i = 1; i <= n; ++i) dp[i][i] = a[i] + b[i - 1] + b[i + 1];
    for (int len = 2; len <= n; ++len)
        for (int i = 1, j = i + len - 1; j <= n; ++i, ++j){
            for (int k = i; k <= j; ++k)
                dp[i][j] = min(dp[i][j], b[i - 1] + b[j + 1] + a[k] + dp[i][k - 1] + dp[k + 1][j]);
        }
    cout << dp[1][n] << endl;
}

int main(){
    ios;
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
    return 0;
}