#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];

void solve(){
    int n;
    cin >> n;
    if (n == 1){
        int x;
        cin >> x;
        cout << 1 << endl;
        return;
    }
    bool flag = false;
    int a, b;
    cin >> a >> b;
    if (b < a) flag = 1;
    string ans = "11";
    for (int i = 3, x; i <= n; ++i){
        cin >> x;
        if (!flag){
            if (x >= b){
                b = x;
                ans += '1';
            }else if (x <= a){
                b = x;
                ans += '1';
                flag = true;
            }else{
                ans += '0';
            }
        }else{
            if (x >= b && x <= a){
                b = x;
                ans += '1';
            }else{
                ans += '0';
            }
        }
    }
    cout << ans << endl;
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