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

void solve(){
    int n;
    cin >> n;
    if (n == 2) {
        cout << 1 << " " << 2 << endl;
        return;
    }
    if (n == 3){
        cout << 1 << " " << 2 << " " << 3 << endl;
        return;
    }
    unordered_map<int, bool> mp;
    vector<int> ans(n);
    ans[0] = 1, ans[1] = 2;
    int lst = ans[1], cnt = 1;;
    mp[1] = 1;
    mp[2] = 1;
    for (int i = 3; i <= n; ++i){
        while (lst * 2 <= n && !mp[lst * 2]){
            ans[++cnt] = lst * 2;
            mp[lst * 2] = 1;
            lst *= 2;
        }
        if (!mp[i]){
            ans[++cnt] = i;
            mp[i] = 1;
            lst = i;
        }
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << " \n"[i == n - 1];
}

int main(){
    ios;
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}