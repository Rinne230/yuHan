#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    ios;
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int cnt1 = 0, cnt2 = 0;
        for (int i = 1, x; i <= n; ++i){
            cin >> x;
            if (x % 2) cnt1 += x;
            else cnt2 += x;
        }
        if (cnt1 >= cnt2) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}