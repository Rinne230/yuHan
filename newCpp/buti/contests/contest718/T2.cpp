#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
string s[maxn];

int getMinRepresentation(string s)
{
    int i = 0, j = 1, k = 0, len = s.size();
    while (i < len && j < len && k < len)
    {
        int t = s[(i + k) % len] - s[(j + k) % len];
        if (!t)
            k++;
        else
        {
            if (t > 0)
                i = i + k + 1;
            else
                j = j + k + 1;
            if (i == j)
                j++;
            k = 0;
        }
    }
    return min(i, j);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int T;
    cin >> T;
    while (T--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> s[i];
            int id = getMinRepresentation(s[i]);
            s[i] = s[i].substr(id) + s[i].substr(0, id); 
        }
        int Q;
        cin >> Q;
        int x, y;
        while (Q--)
        {
            cin >> x >> y;
            if (s[x] == s[y]) cout << "Yes" << endl;
            else cout << "No" << endl;
        }
    }
    return 0;
}