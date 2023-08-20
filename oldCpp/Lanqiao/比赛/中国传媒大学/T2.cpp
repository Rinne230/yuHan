#include <bits/stdc++.h>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
typedef long long ll;
using namespace std;
const int maxn = 1e5 + 10;
ll a[maxn], k, s, n, ans;
int main(){
    cin >> n >> k >> s;
    for (int i = 1, t, m; i <= s; ++i){
        cin >> t >> m;
        a[t] += m;
    }
    for (int i = 1; i <= n; ++i) if (a[i] < k) ans++;
    cout << ans << endl;
    return 0;
}