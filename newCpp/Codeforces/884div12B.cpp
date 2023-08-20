#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 200005;

int a[maxn];

void solve(){
    int n;
    cin >> n;
    if (n == 1)
        printf("1\n");
    else if (n == 2)
        printf("1 2\n");
    else{
        memset(a, 0, sizeof(a));
        int c = 4;
        a[0] = 2, a[n / 2] = 1, a[n - 1] = 3;
        for (int i = 0; i < n; i++) {
            if (a[i] == 0)
                a[i] = c++;
        }
        for (int i = 0; i < n; i++)
            printf("%d%c", a[i], (i == n - 1) ? '\n' : ' ');
    }
}

int main()
{
    ios;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}