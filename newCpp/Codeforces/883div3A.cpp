#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

void solve(){
    int n, cnt = 0;
    cin >> n;
    for (int i = 1, h, l; i <= n; ++i){
        cin >> h >> l;
        if (h - l > 0) cnt++;
    }
    cout << cnt << endl;
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