#include <bits/stdc++.h>
using namespace std;
int n, m, x, l, r;
int dp[100010];//dp[i]为区间[1.i]中所有数对中的左边界最大值
unordered_map<int, int> hs;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n >> m >> x;
    for (int i = 1, a; i <= n; ++i){
        cin >> a;
        hs[a] = i;
        dp[i] = max(dp[i - 1], hs[a ^ x]);
    }
    while (m--){
        cin >> l >> r;
        if(dp[r] >= l) cout << "yes" <<endl;
        else cout << "no" << endl;
    }
    return 0;
}