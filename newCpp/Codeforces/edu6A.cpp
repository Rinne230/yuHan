#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    ll l1 = abs(x2 - x1), l2 = abs(y2 - y1);
    cout << min(l1, l2) + l1 - min(l1, l2) + l2 - min(l1, l2);
    return 0;
}