#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
 

void solve(){
    int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        vector<bool> v(256);
        v[0] = true;
        int s = 0, ans = 0;
        for(int i = 0; i < n; i++){
            s ^= a[i];
            v[s] = true;
            for(int j = 0; j < 256; j++){
                if (v[j]){
                    ans = max(ans, s ^ j);
                }
            }
        }
        cout << ans << '\n';
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