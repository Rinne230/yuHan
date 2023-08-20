#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int siz;
int digits[20];
ll dp[13][109][109][109];

ll dfs(int i, int num, int sum, int t, bool lim) {
    if (i < 0) return sum == t && num % sum == 0;
    if (!lim && dp[i][num][sum][t] >= 0) return dp[i][num][sum][t];
    
    ll res = 0;
    int up = lim ? digits[i] : 9;
    for (int d = 0; d <= up; d++) {
        res += dfs(i - 1, (num * 10 + d) % t, sum + d, t, lim && d == up);
    }
    if (!lim) dp[i][num][sum][t] = res;
    
    return res;
}

ll calc(ll num) {
    siz = 0;
    while (num) {
        digits[siz++] = num % 10;
        num /= 10;
    }
    
    ll res = 0;
    for (int i = 1; i <= 108; i++) {    // 12*9=108
        res += dfs(siz - 1, 0, 0, i, 1);
    }
    
    return res;
}

int main() {
    memset(dp, -1, sizeof(dp));
    int T;
    cin >> T;
    
    for (int test = 1; test <= T; test++) {
        ll N;
        cin >> N;
        
        cout << "Case " << test << ": " << calc(N) << '\n';
    }
    
    return 0;
}