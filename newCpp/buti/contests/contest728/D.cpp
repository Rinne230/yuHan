#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int ne[N];
char p[N];

void solve()
{
    int n;
    cin >> n;
    cin >> p + 1;
    int m = strlen(p + 1);

    bool flag0 = true, flag1 = true;
    for (int i = 1; i <= m; i++)
        if (p[i] != '0')
        {
            flag0 = false;
            break;
        }
    for (int i = 1; i <= m; i++)
        if (p[i] != '1')
        {
            flag1 = false;
            break;
        }
    if (flag0)
    {
        for (int i = 0; i < n; i++)
            cout << 1;
        cout << endl;
    }
    else if (flag1)
    {
        for (int i = 0; i < n; i++)
            cout << 0;
        cout << endl;
    }
    else
    {
        int x;
        for (int i = 2, j = 0; i <= m; i++)
        {
            while (j && p[i] != p[j + 1])
                j = ne[j];
            if (p[i] == p[j + 1])
                j++;
            ne[i] = j;
        }
        if (p[ne[m] + 1] == '0')
            x = 1;
        else
            x = 0;
        for (int i = 0; i < n; i++)
            cout << x;
        cout << endl;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}