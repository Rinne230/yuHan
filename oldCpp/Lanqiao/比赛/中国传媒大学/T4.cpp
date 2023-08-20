#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;
int n, p[N], m[N];
char q[N];
int t[N];
struct Sock {
    ll pattern, left, right, both, id;
} socks[N];
int main() {
    cin >> n;
    memset(socks, 0, sizeof socks);
    for (int i = 0; i < n; ++i){
        cin >> p[i] >> q[i] >> m[i];
    }
    memcpy(t, p, sizeof(p));
    sort(t, t + n);
    int len = unique(t, t + n) - t;
    for (int i = 0; i < n; ++i) p[i] = lower_bound(t, t + len, p[i]) - t + 1;
    for (int i = 0; i < n; i++) {
        if (q[i] == 'L') socks[p[i]].left += m[i];
        else if (q[i] == 'R') socks[p[i]].right += m[i];
        else socks[p[i]].both += m[i];
        socks[p[i]].pattern = p[i];
        socks[p[i]].id = 4;
    }
    ll ans = 0;
    for (int i = 0; i < N; i++) {
        if (socks[i].id){
            if (socks[i].left >= socks[i].right && socks[i].left){ 
                ans += socks[i].left;
                socks[i].id = 1;
            }else if (socks[i].right >= socks[i].left && socks[i].right){
                ans += socks[i].right;
                socks[i].id = 2;
            }else if (!socks[i].right && !socks[i].left && socks[i].both){
                ans += 1;
                socks[i].both--;
                socks[i].id = 3;
            }
        }
    }
    bool flag = false;
    for (int i = 0; i < N; i++) {
        if (socks[i].id == 3 && socks[i].both){
            flag = true;
            break;
        }else if (socks[i].id == 1 && (socks[i].right || socks[i].both)){
            flag = true;
            break;
        }else if (socks[i].id == 2 && (socks[i].left || socks[i].both)){
            flag = true;
            break;
        }
    }
    if (flag)
        cout << ans + 1 << endl;
    else 
        cout << -1 << endl;
    return 0;
}
