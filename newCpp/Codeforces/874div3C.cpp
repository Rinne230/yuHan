#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#define endl '\n'
using namespace std;
const int maxn = 2e5 + 10;
int n, m;
int w[maxn];

void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    sort(w + 1, w + n + 1);
    if (w[1] % 2)
        cout << "YES" << endl;
    else{
        for (int i = 1; i <= n; i++)
            if (w[i] % 2){
                cout << "NO" << endl;
                return;
            }
        cout << "YES" << endl;
    }
}

int main(){
    ios;
    int t;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}
