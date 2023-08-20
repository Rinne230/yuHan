#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn], s[maxn];

void solve(){
    memset(s, 0, sizeof s);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i], s[i] = s[i - 1] + a[i];
    while (m--){
        int a, b, c;
        cin >> a >> b >> c;
        int ans = s[n] - s[b] + s[a - 1] + (b - a + 1) * c;
        if (ans & 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
int main(){
    ios;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}