#include <cstdio>
#include <cmath>
#include <set>
#include <map>
#include <cstring>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <iterator>

#define mem(x, y) memset(x, y, sizeof(x))
using namespace std;
const int INF = 0x7fffffff;
const int MAXN = 1e6 + 10;
double PI = 3.1415926535898;
typedef long long ll;

int s, c;

int sg(int s, int c)
{
    int x = sqrt(s);
    while ((x * x + x) >= s)
        x--;
    if (x < c)
        return s - c;
    else if (x == c)
        return 0;
    else
        return sg(x, c);
}

int main()
{
    int N;
    int i, j = 1;
    while (cin >> N && N)
    {
        int ans = 0;
        for (i = 1; i <= N; i++)
        {
            cin >> s >> c;
            ans = ans ^ sg(s, c);
        }
        ans = ans ^ 0;
        if (ans)
            printf("Case %d:\nYes\n", j++);
        else
            printf("Case %d:\nNo\n", j++);
    }
}
