#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int P = 1'000'000'007;

typedef vector<int> vi;
typedef vector<vi> mat;

int add(int a, int b) { int r = a + b; return r < P ? r : r - P; }
int sub(int a, int b) { int r = a - b; return r < 0 ? r + P : r; }
int mul(int a, int b) { return 1ll * a * b % P; }
int qpm(int a, int b) {
    int r = 1;
    do if (b & 1) r = mul(r, a);
    while (a = mul(a, a), b >>= 1);
    return r;
}
int inv(int x) { return qpm(x, P - 2); }

int solve(int n, int p) {
    vector<int> pw(n + 1, 1);
    for (int i = 1; i <= n; ++i) {
        pw[i] = mul(pw[i - 1], p);
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i][0] = 1;
        for (int j = 1; j <= n; ++j)
            dp[i][j] = add(mul(dp[i - 1][j - 1], sub(pw[n], pw[j - 1])), mul(dp[i - 1][j], pw[j]));
    }
    int sum = 0;
    for (int i = 0; i <= n; ++i)
        sum = add(sum, mul(i, dp[n][i]));
    return mul(sum, inv(qpm(pw[n], n)));
}

int main(void) {
    int T;
    cin >> T;
    int n, p;
    while (T--) {
        cin >> n >> p;
        cout << solve(n, p) << endl;
    }
    return 0;
}