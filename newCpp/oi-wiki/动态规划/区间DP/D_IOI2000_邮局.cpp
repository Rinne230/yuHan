#include <bits/stdc++.h>
#define MAXN 3010
#define N 310
using namespace std;
int n, m, a[MAXN], dp[MAXN][N];
//定义dp[i][j]表示前i个村庄放j个邮局的前i个村庄的最小距离总和,w(i,j)表示村庄区间[i,j]内放一个村庄时该区间的最小距离总和。
int w(int l, int r){
    int mid = (l + r) >> 1, ans = 0;
    for (int i = l; i < mid; ++i) ans += a[mid] - a[i];
    for (int i = mid + 1; i <= r; ++i) ans += a[i] - a[mid];
    return ans;
}
int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int j = 1; j <= m; ++j)
        for (int i = 1; i <= n; ++i)
            for (int k = 0; k < i; ++k)
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + w(k + 1, i));
    cout << dp[n][m] << endl;
    return 0;
}