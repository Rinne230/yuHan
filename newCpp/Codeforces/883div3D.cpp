#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
const int maxn = 2e5 + 10;
using namespace std;
int x[maxn];

void solve(){
    int n, d, h;
    double sumarea = 0.00000;
    cin >> n >> d >> h;
    double s = double(d) * double(h) * 0.5;
    for (int i = 1; i <= n; ++i) cin >> x[i];
    for (int i = 1; i <= n - 1; ++i){
        int j = i + 1;
        if (x[i] + h <= x[j])
            sumarea += s;
        else 
            sumarea += s - ((double(h) - double(x[j]) + double(x[i])) / double(h) * (double(h) - double(x[j]) + double(x[i])) / double(h)) * s;
    }
    printf("%lf\n", sumarea + s);
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