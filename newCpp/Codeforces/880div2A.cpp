#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[101];

void solve(){
    int n;
    cin >> n;
    int maxx = -1;
    memset(a, 0, sizeof(a));
    for (int i = 1, x; i <= n; ++i){
        cin >> x;
        maxx = maxx > x ? maxx : x;
        a[x]++;
    }
    for (int i = 0; i <= maxx; ++i){
        if (!a[i]){
            cout << "NO\n";
            return;
        }else if (i && a[i] > a[i - 1]){
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}