#include <bits/stdc++.h>
#define MAXN 81
#define k m - (r - l)
#define bll __int128
using namespace std;
int n, m; 
bll ans, num[MAXN], f[MAXN][MAXN], p[MAXN];

inline int read(){
    char ch = getchar(); int f = 1, x = 0;
    while (ch < '0' || ch > '9'){if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9'){x = (x << 1) + (x << 3) + ch - '0'; ch = getchar();}
    return x * f;
}

void print(bll x){
    if (!x) return;
    if (x) print(x / 10);
    putchar(x % 10 + '0');
}

bll dp(int l, int r){
    if (f[l][r] != -1) return f[l][r];
    if (r - l >= 1) f[l][r] = max(num[l] * p[k] + dp(l + 1, r), num[r] * p[k] + dp(l, r - 1));
    else f[l][r] = num[l] * p[k];
    return f[l][r];
}

int main(){
    n = read(); m = read();
    p[0] = 1;
    for (int i = 1; i <= m; ++i) p[i] = (p[i - 1] << 1);
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j) num[j] = read();
        memset(f, -1, sizeof(f));
        ans += dp(1, m);
    }
    if (!ans) printf("0");
    else print(ans);
    return 0;
}