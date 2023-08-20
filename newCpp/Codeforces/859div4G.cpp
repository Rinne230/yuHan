#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const int maxn = 2e5 + 10;
ll a[maxn], s[maxn];

void solve(){
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + 1 + n);
    if (a[1] != 1){
        cout << "NO" << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    for (int i = 2; i <= n; i++){
        if (a[i] > s[i - 1]){
            cout << "NO" << endl;
            return;
        }
    }
    cout << "YES" << endl;
}

int main(){
    ios;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}