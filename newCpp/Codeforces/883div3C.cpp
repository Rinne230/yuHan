#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
const int maxn = 2e5 + 10;
typedef long long ll;
using namespace std;
int a[maxn];
struct node{
    ll tt;
    ll tp;
    ll idx;
}num[maxn];

bool cmp(node p, node q){
    if (p.tt == q.tt){
        return p.tp < q.tp;
    }
    return p.tt > q.tt;
}
void solve(){
    int n, t, tot;
    cin >> n >> t >> tot;
    ll maxt = 0, minp = 0x7ffffff;
    ll idx = 0;
    for (int i = 1; i <= n; ++i){
        int tim = tot;  
        for (int j = 1; j <= t; ++j) cin >> a[j];
        sort(a + 1, a + t + 1);
        ll tt = 0, tp = 0;
        ll sum = 0;
        for (int j = 1; j <= t; ++j){
            if (tim >= a[j]){
                tim -= a[j];
                sum += a[j];
                tt++;
                tp += sum;
            }
        }
        num[i].tt = tt;
        num[i].tp = tp;
        num[i].idx = i;
    }
    sort(num + 1, num + n + 1, cmp);
    for (int i = 1; i <= n; ++i){
        if (num[i].idx == 1){
            cout << i << endl;
            break;
        }
    }
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