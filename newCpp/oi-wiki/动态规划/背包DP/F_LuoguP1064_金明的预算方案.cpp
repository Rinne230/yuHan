#include <bits/stdc++.h>
using namespace std;
const int maxn = 32010;
int n, m, mw[maxn], mc[maxn], aw[maxn][3], ac[maxn][3], dp[maxn];
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1, v, p ,q; i <= m; ++i){
        scanf("%d%d%d", &v, &p, &q);
        if (!q){
            mw[i] = v;
            mc[i] = v * p;
        }else{
            aw[q][0]++;
            aw[q][aw[q][0]] = v;
            ac[q][aw[q][0]] = v * p;
        }
    }
    for (int i = 1; i <= m; ++i)
        for (int j = n; j >= mw[i] && mw[i]; --j){
            dp[j] = max(dp[j], dp[j - mw[i]] + mc[i]);
            if (j >= mw[i] + aw[i][1]) dp[j] = max(dp[j], dp[j - mw[i] - aw[i][1]] + mc[i] + ac[i][1]);
            if (j >= mw[i] + aw[i][2]) dp[j] = max(dp[j], dp[j - mw[i] - aw[i][2]] + mc[i] + ac[i][2]);
            if (j >= mw[i] + aw[i][1] + aw[i][2]) dp[j] = max(dp[j], dp[j - mw[i] - aw[i][1] - aw[i][2]] + mc[i] + ac[i][1] + ac[i][2]);
        }
    printf("%d", dp[n]);
    return 0;
}