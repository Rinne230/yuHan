#include <bits/stdc++.h>
using namespace std;
int dp[105][100005];
int main(){
    int n;
    cin >> n;
    dp[0][0] = 1;
    for (int i = 1, a; i <= n; ++i){
        cin >> a;
        for (int j = 0; j <= 100000; ++j){
            if (dp[i - 1][j]){
                dp[i][j] = 1;
                dp[i][j + a] = 1;
                dp[i][abs(j - a)] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 1; i <= 100000; ++i) if(dp[n][i]) ++ans;
    cout << ans << endl;
    return 0;
}