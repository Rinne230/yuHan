#include <bits/stdc++.h>
#define maxn 210
using namespace std;
int mx = -0x7fffffff, mn = 0x7fffffff;
int n, x, y;
int a[maxn][maxn];
int f1[maxn][maxn], f2[maxn][maxn];
int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i][i];
    for (int i = 1; i <= n; ++i) a[i + n][i + n] = a[i][i];
    for (int L = 2; L <= n; ++L)
        for (int i = 1, j = i + L - 1; i + L - 1 <= (n << 1); ++i, ++j)
            for (int k = 1; k < L; ++k){
                a[i][j] = a[i][i + k - 1] + a[i + k][j];
                if (f1[i][j]) f1[i][j] = min(f1[i][j], a[i][j] + f1[i][i + k - 1] + f1[i + k][j]);
                else f1[i][j] = a[i][j] + f1[i][i + k - 1] + f1[i + k][j];
                if (f2[i][j]) f2[i][j] = max(f2[i][j], a[i][j] + f2[i][i + k - 1] + f2[i + k][j]);
                else f2[i][j] = a[i][j] + f2[i][i + k - 1] + f2[i + k][j];
            }
    for (int i = 1; i <= n - 1; ++i) mn = min(f1[i][i + n - 1], mn);
    for (int i = 1; i <= n - 1; ++i) mx = max(f2[i][i + n - 1], mx);
    cout << mn << endl << mx;
    return 0;
}