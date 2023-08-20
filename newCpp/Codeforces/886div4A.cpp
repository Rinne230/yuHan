#include<bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;

void solve(){
    int a, b, c;
    cin >> a >> b >> c;
    if (a + b >= 10 || b + c >= 10 || a + c >= 10){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
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