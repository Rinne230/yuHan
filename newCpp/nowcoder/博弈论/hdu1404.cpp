#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>
using namespace std;
const int maxn = 1e7 + 6;
bool sg[maxn];

int intlen(int x)
{
    for (int i = 6; i > 0; i--)
    {
        int k = pow(10, (i - 1));
        if (x / k)
            return i;
    }
}

void GetSG(int x)
{
    // cout<<x<<endl;
    int len = intlen(x);
    for (int i = 0; i < len; ++i)
    {
        int k = pow(10, i);
        int q = x / k % 10;
        int y = x;
        for (int j = q; j < 9; ++j)
        {
            y += k;
            sg[y] = true; // 可一步到达必败状态则为必胜
        }
    }
    int y = x, k = 1;
    while (len < 6)
    {
        y *= 10;
        for (int i = 0; i < k; ++i)
            sg[y + i] = true;
        k *= 10;
        len++;
    }
}

int main()
{
    memset(sg, false, sizeof(sg));
    sg[0] = true;
    for (int i = 1; i < 1000000; ++i)
        if (!sg[i]) // 必败则进入
            GetSG(i);
    char n[10];
    while (gets(n))
    {
        if (n[0] == '0')
        {
            puts("Yes");
            continue;
        }
        int m = atoi(n);
        if (sg[m])
            puts("Yes");
        else
            puts("No");
    }
    return 0;
}