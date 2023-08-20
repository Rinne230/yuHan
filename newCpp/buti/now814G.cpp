/**
 * @file now814G.cpp
 * @author atrilactose
 * @brief 异或运算封闭模板
 * @version 0.1
 * @date 2023-08-14
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int a[1000005];
int p[30];

void solve()
{
    int n, k;
    cin >> n >> k;
    set<int> st;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        st.insert(a[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (st.count(a[i] ^ k))
        {
            cout << "Alice\n";
            return;
        }
    }
    memset(p, 0, sizeof(p));
    //异或运算封闭
    for (auto x : st)
    {
        x ^= k;
        for (int j = 29; j >= 0; j--)
        {
            if (x >> j == 1)
            {
                if (p[j] == 0)
                {
                    p[j] = x;
                    break;
                }
                else
                    x ^= p[j];
            }
        }
    }
    int cnt = 0;
    for (int i = 29; i >= 0; i--)
        if (p[i])
            cnt++;
    if ((1 << cnt) == st.size())
    {
        cout << "Bob\n";
    }
    else
    {
        cout << "Draw\n";
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
        solve();
}