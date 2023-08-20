#include<bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;

void solve(){
    int ans = 0;
    int idx;
    int a, b, n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a >> b;
        if (a <= 10)
            if (b > ans){
                idx = i;
                ans = b;
            }
    }
    cout << idx << endl;
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