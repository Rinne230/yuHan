#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    ios;
    int t;
    cin >> t;
    while (t--){
        int a, b, c;
        cin >> a >> b >> c;
        if (a + b == c) cout << '+' << endl;
        else cout << '-' << endl;
    }
    return 0;
}