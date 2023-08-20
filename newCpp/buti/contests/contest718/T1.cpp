#include<bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;

void solve(){
    int n, m, d;
    cin >> n >> m >> d;
    int tmp = m % n;
    int ans = m / n;
    if (tmp > 0)
        ans += 1;
    if (ans >= d) cout << "Yes" << endl;
    else cout << "No" << endl;
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
