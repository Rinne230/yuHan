#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
using namespace std;

int main(){
    ios;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        if (n <= 4) cout << "Bob" << endl;
        else cout << "Alice" << endl;
    }
    return 0;
}