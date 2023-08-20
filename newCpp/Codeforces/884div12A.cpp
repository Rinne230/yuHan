#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a >> b;
        if (min(a, b) != 1) cout << min(a, b) - 1 << endl;
        else cout << a + b << endl;
    }
    return 0;
}