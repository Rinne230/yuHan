#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e6 + 10;
const ll maxm = 1e6 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

ll dp[maxn], a[maxn], pre[maxm], nxt[maxm], lst[maxm];
int n;
void dfs(int pos){
    if (dp[pos] > pos) return;
    if (pos < 1 || pos > n) return;
    if (nxt[pos] && dp[nxt[pos]] >= dp[pos] + 1){
        dp[nxt[pos]] = dp[pos] + 1;
        dfs(nxt[pos]);
    }
    if (pos > 1 && dp[pos - 1] >= dp[pos] + 1){
        dp[pos - 1] = dp[pos] + 1;
        dfs(pos - 1);
    }
    if  (pos < n && dp[pos + 1] >= dp[pos] + 1){
        dp[pos + 1] = dp[pos] + 1;
        dfs(pos + 1);
    }
    return;
}
void solve(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        dp[i] = i - 1;
        if (!pre[a[i]]){
            pre[a[i]] = i;
        }else{
            lst[i] = pre[a[i]];
            nxt[pre[a[i]]] = i;
            pre[a[i]] = i;
        }
    }
    dfs(1);
    cout << dp[n] << endl;
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