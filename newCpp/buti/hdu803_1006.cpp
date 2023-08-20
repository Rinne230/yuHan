#include <iostream>
#include <vector>

using namespace std;

const int N = 310, mod = 1e9 + 7;

int a[N], s[N];
bool good[N * N];
vector<int> turn_good[2 * N], turn_bad[2 * N];

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int T;
    cin >> T;
    for (int i = 1; i <= 300; i++)
    {
        good[i * i] = 1;
    }
    for (int i = 1; i <= 90000; i++)
    {
        for (int j = -299; j <= 299; j++)
        {
            if (good[i])
            {
                if (i + j > 0 && !good[i + j])
                {
                    turn_bad[j + 300].emplace_back(i);
                }
            }
            else
            {
                if (i + j > 0 && good[i + j])
                {
                    turn_good[j + 300].emplace_back(i);
                }
            }
        }
    }

    while (T--)
    {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            s[i] = a[i] + s[i - 1];
        }
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i; j <= n; j++)
            {
                if (good[s[j] - s[i - 1]])
                {
                    res++;
                }
            }
        }
        int maxDelta = 0;
        for (int i = 1; i <= n; i++)
        {
            vector<int> cnt(90001);
            for (int j = 1; j <= i; j++)
            {
                for (int k = i; k <= n; k++)
                {
                    cnt[s[k] - s[j - 1]]++;
                }
            }
            for (int j = 1; j <= 300; j++)
            {
                int diff = j - a[i] + 300;
                int tmp = 0;
                for (auto x : turn_good[diff])
                    tmp += cnt[x];
                for (auto x : turn_bad[diff])
                    tmp -= cnt[x];
                maxDelta = max(maxDelta, tmp);
            }
        }
        cout << res + maxDelta << '\n';
    }
    return 0;
}