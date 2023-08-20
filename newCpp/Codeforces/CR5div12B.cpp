#include <bits/stdc++.h>
#define ios  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(){
    ios;
    int t;
    cin >> t;
    while(t--){
        int n, x;
        cin >> n >> x;
        int ans = 0;
        for(int t = 0; t < 3; t++){
            int res = 0;
            for(int i = 0, tmp; i < n; i++){
                cin >> tmp;
                res |= tmp;
                if ((res & x) == res) ans |= res;
            }
        }
        cout << (ans == x ? "Yes" : "No") << '\n';
    }

}