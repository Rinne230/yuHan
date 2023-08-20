#include<bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;

void solve(){
    int n, k;
    cin >> k >> n;
    if (n == k + 1) cout << "Bob" << endl;
    else cout << "Alice" << endl;
}
int main(){
    freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
    ios;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}