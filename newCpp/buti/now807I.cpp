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
    auto sov = [&](int m, const vector<string> &a){
        int n = a.size(), res = 0;
        if (m <= 20){
            for (int k = 0; k < (1 << m); ++k){
                for(auto & s : a){
                    bool flag = true;
                    for (int i = 0; i < m; ++i){
                        if (s[i] == '?') continue;
                        if (s[i] - '0' != (k >> i & 1)){
                            flag = false;
                            break;
                        }
                    }
                    if (flag){
                        res++;
                        break;
                    }
                }
            }
            return res;
        }
        for (int k = 1; k < (1 << n); ++k){//遍历所有子集
            int cnt = 1;
            for (int i = 0; i < m; ++i){
                int x = 0, y = 0;
                for (int j = 0; j < n; ++j){
                    if (k >> j & 1){
                        if (a[j][i] == '0') x++;
                        if (a[j][i] == '1') y++;
                    }
                }
                if (x && y){
                    cnt = 0;
                    break;
                }
                if (x == 0 && y == 0) cnt = cnt * 1ll * 2 % mod;
            }
            int bits = __builtin_popcount(k);
            if (bits & 1){
                res = (res + cnt) % mod;
            }else{
                res = (res - cnt + mod) % mod;
            }
        }
        return res;
    };
    int n;
    cin >> n;
    map<int, vector<string>> a;
    for (int i = 1; i <= n; ++i){
        string s;
        cin >> s;
        a[s.size()].push_back(s);
    }
    ll ans = 0;
    for (auto [n, x] : a){
        ans = (ans + sov(n, x)) % mod;
    }
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