#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define rep(i, j, k) for(int i = (j); i <= (k); i++)
#define per(i, j ,k) for(int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 1e6 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

ll dp[maxn][4];
void solve(){
    string s;
    cin >> s;
    ll len = s.length();
    s = " " + s;
    dp[0][0] = 1;
    for (int i = 1; i <= len; ++i){
        for (int j = 0; j <= 3; ++j){
            dp[i][j] = dp[i - 1][j];
            if (j > 0) dp[i][j] += dp[i - 1][j - 1];
            for (int k = i - 1; k >= max(i - j, 1); --k){
                if(s[k] == s[i]){
                    dp[i][j] -= dp[k - 1][j - i + k];
                    break;
                }
            }
        }
    }
    ll ans = 0;
    rep(i, 0, 3) ans += dp[len][i];
    cout << ans << endl;
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