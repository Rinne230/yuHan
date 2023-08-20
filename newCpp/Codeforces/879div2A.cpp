#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n, cnt = 0, res = 0;
        cin >> n;
        for (int i = 1, t; i <= n; ++i){
            cin >> t;
            if (t > 0) cnt++;
        }
        if (cnt >= n - cnt){
            if ((n - cnt) % 2 == 0) cout << '0' << '\n';
            else cout << 1 << '\n';
        }
        else{
            int res = ((n - cnt - cnt) + 1) >> 1;
            if ((n - cnt - res) % 2 == 0) cout << res << '\n';
            else cout << res + 1 << '\n';
        }
    }
    return 0;
}