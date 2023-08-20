#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    double x, k;
    cin >> t;
    while (t--)
    {
        cin >> k >> x;
        double ans;
        if (x == k)
            ans = 0.5;
        else if (x * 2 <= k)
            ans = 0;
        else if (x > k)
            ans = (2.0 * x * x - k * k) / (2.0 * x * x);
        else if (x < k && k < x * 2)
            ans = (2.0 * x - k) * (2.0 * x - k) / (2.0 * x * x);
        printf("%.2f\n", ans);
    }
}