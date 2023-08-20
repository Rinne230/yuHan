#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 110;
typedef long long ll;
char ch[maxn][maxn];

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

void print(int n, int aft)
{
    for (int i = 1; i <= n; ++i)
    {
        for (int l = 1; l <= aft / n; ++l)
        {
            for (int j = 1; j <= n; ++j)
            {
                for (int k = 1; k <= aft / n; ++k)
                {
                    cout << ch[i][j];
                }
            }
            cout << endl;
        }
    }
}
void solve()
{
    int n, z, aft;
    cin >> n >> z;
    aft = n * z / 100;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> ch[i][j];
    if ((n * z) % 100)
    {
        cout << "error" << endl;
        return;
    }

    bool flag = true;
    char ch1 = ch[1][1];
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (ch[i][j] != ch1)
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            break;
    }
    if (flag)
    {
        for (int i = 1; i <= aft; ++i)
        {
            for (int j = 1; j <= aft; ++j)
            {
                cout << ch1;
            }
            cout << endl;
        }
        return;
    }

    if (aft % n == 0)
    {
        print(n, aft);
        return;
    }
    else
    {
        int tmp = gcd(aft, n);
        int nn = n / tmp;
        for (int i = 1; i <= n - nn + 1; i += nn)
        {
            for (int j = 1; j <= n - nn + 1; j += nn)
            {
                char c = ch[i][j];
                for (int k = i; k < i + nn; ++k)
                {
                    for (int l = j; l < j + nn; ++l)
                    {
                        if (ch[k][l] != c)
                        {
                            cout << "error" << endl;
                            return;
                        }
                    }
                }
            }
        }
        for (int i = 1; i <= n - nn + 1; i += nn)
        {
            for (int l = 1; l <= aft / tmp; ++l)
            {
                for (int j = 1; j <= n - nn + 1; j += nn)
                {
                    for (int k = 1; k <= aft / tmp; ++k)
                    {
                        cout << ch[i][j];
                    }
                }
                cout << endl;
            }
        }
        return;
    }
    cout << "error" << endl;
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
/*
5
2 100
ab
cd
2 200
ab
cd
2 125
aa
aa
4 125
aaab
aaaa
aaaa
aaaa
4 125
aaaa
aaaa
aaaa
aaaa
*/