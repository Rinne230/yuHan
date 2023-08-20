#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[101];
int main(){
    for (int i = 1; i <= 100; ++i){
        int k = i;
        for (int j = 2; j <= i; ++j){
            while (k % j == 0){
                cnt[j]++;
                k /= j;
            }
        }
    }
    ll ans = 1;
    for (int i = 1; i <= 100; ++i) ans *= (cnt[i] + 1);
    cout << ans << endl;
    return 0;
}