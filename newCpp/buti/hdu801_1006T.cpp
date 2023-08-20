#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
char s[N];
void solve()
{
    scanf("%s", s + 1);
    int n = strlen(s + 1), l;
    int ans = 0;
    int now = 0; // 手里的自定义UFO数量
    map<char, int> mp;
    int sz = 0;
    for (l = 1; l <= n; l++)
    {
        mp[s[l]]++;
        if (mp[s[l]] == 1)
            sz++;
        if (sz == 3) // 选三个不一样的
        {
            now = 2;
            break;
        }
        if (mp[s[l]] == 3) // 选三个一样的
        {
            now = 1;
            ans++;
            break;
        }
    }
    l++;
    while (l <= n)
    {
        if (now == 2) // 两个自定义都定义成l位置这个的样子，然后三个消掉，变成一个自定义的
        {
            ans++;
            now = 1;
        }
        else if (now == 1)
        {
            if (l < n) // 后面还有两个以上
            {
                if (s[l] == s[l + 1]) // 把手里这个变成后两个一样的然后消掉
                {
                    ans++;
                    l++;
                    now = 1;
                }
                else // 把手里的变成和后两个都不一样
                {
                    l++;
                    now = 2;
                }
            }
        }
        l++;
    }
    printf("%d\n", ans);
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        solve();
}