#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;

int main(){
    ios;
    int t;
    cin >> t;
    while(t--){
        int n, m, x1, y1, x2, y2;
        cin >> n >> m >> x1 >> y1 >> x2 >> y2;
        x1 -= n, x2 -= n, y1 -= m, y2 -= m;
        int res = 0;
        if (min(x1, x2) >= 0 || max(x1, x2) <= 0) res += min(abs(x1), abs(x2));
        if (min(y1, y2) >= 0 || max(y1, y2) <= 0) res += min(abs(y2), abs(y1));
        cout << res + 1 << endl;
    }
    return 0;
}