#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <queue>
#include <sstream>
#define INF 0x3f3f3f3f
// #define int long long
#define endl '\n'
#define lowbits(x) (x & (-x))
using namespace std;
typedef pair<int, int> PII;
const int N = 2e5 + 10;
int n, k1, k2, k3, a, b, c;
double p[20];
double A[550], B[550];
signed main()
{
    // std::ios::sync_with_stdio(false), cin.tie(0),cout.tie(0);
    // cin>>n>>k1>>k2>>k3>>a>>b>>c;
    scanf("%d%d%d%d%d%d%d", &n, &k1, &k2, &k3, &a, &b, &c);
    p[0] = 1.0 / k1 / k2 / k3;
    for (int i = 1; i <= k1 + k2 + k3; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= k1; j++)
        {
            for (int k = 1; k <= k2; k++)
            {
                for (int l = 1; l <= k3; l++)
                {
                    if (j == a && k == b && l == c)
                        continue;
                    else if (j + k + l == i)
                    {
                        cnt++;
                    }
                }
            }
        }
        p[i] = 1.0 * cnt / k1 / k2 / k3;
    }

    for (int i = n; i >= 0; i--)
    {
        for (int k = 3; k <= k1 + k2 + k3; k++)
        {
            A[i] += p[k] * A[i + k];
            B[i] += p[k] * B[i + k];
        }
        A[i] += p[0];
        B[i] += 1.0;
    }
    double ans = B[0] / (1 - A[0]);
    printf("%.10lf", ans);
}