#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const int N = 1e6 + 7, mod = 1e9 + 7;
ll n, m, k;
ll dp[N][2];
void solve(){
	cin >> n;
	vector<ll> a(n + 1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	vector<ll> vis(n + 1);
	for(int i = 1; i <= n; i++){
		if(vis[a[i]] == 0){
			dp[i][1] = dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
		}else{
			dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
			dp[i][1] = max(dp[vis[a[i]]][1] + i - vis[a[i]], dp[vis[a[i]]][0] + i - vis[a[i]] + 1);
		}
		vis[a[i]] = i;
	}
	cout << max(dp[n][1], dp[n][0]) << '\n';
}
int main(){
    ios;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}