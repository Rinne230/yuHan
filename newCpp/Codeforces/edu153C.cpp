#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define rep(i, j, k) for(int i = (j); i <= (k); i++)
#define per(i, j ,k) for(int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 3e5 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;

int tr[maxn], ans, n;
int lowbit(int x) {return x & (-x);}
void add(int x, int y){
    while(x <= n){
        tr[x] = max(tr[x], y);
        x += lowbit(x);
    }
}
int query(int x){
    int res = 0;
    while(x){
        res = max(res, tr[x]);
        x -= lowbit(x);
    }
    return res;
}
void solve(){
    ans = 0;
    cin >> n;
    fill(tr, tr + n + 1, 0);
    for (int i = 1, x; i <= n; ++i){
        cin >> x;
        int cnt = query(x - 1);
        if (cnt == 1) ans++;
        add(x, cnt + 1);
    }
    cout << ans << endl;    
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