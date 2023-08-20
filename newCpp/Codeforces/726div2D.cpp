#include<bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    int k = log2(n);
    if (n == pow(2, k) && k & 1){
        cout << "Bob" << endl;
    }else if (n % 2 == 0){
        cout << "Alice" << endl;
    }else{
        cout << "Bob" << endl;
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