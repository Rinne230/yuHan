#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

void solve(){
    ios;
    int n, m;
    cin >> n >> m;
    if (m % 2 == 0){
        int cnt = 0;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j <= m; ++j)
                cout << (i - 1) * m + j << " ";
            cout << endl;
        }
    }else{
        for (int i = 2; i <= n; i += 2){
            for (int j = 1; j <= m; ++j)
                cout << (i - 1) * m + j << " ";
            cout << endl;
        }
        for (int i = 1; i <= n; i += 2){
            for (int j = 1; j <= m; ++j)
                cout << (i - 1) * m + j << " ";
            cout << endl;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}