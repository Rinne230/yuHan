#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    ios;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int mx = -0x7ffffff, mn = 0x7ffffff;
        for (int i = 1, x; i <= n; ++i){
            cin >> x;
            mx = x > mx ? x : mx;
            mn = x < mn ? x : mn;
        }
        if (mn < 0) cout << mn << endl;
        else cout << mx << endl;
    }
    return 0;
}