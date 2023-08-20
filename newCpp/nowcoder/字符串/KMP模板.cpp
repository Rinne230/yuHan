#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

string s1, s2;
int ne[N];

int main(void)
{
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> s1 >> s2;
    s1 = " " + s1;
    s2 = " " + s2;
    for (int i = 2; i < s2.size(); i++)
    {
        ne[i] = ne[i - 1];
        while (ne[i] && s2[i] != s2[ne[i] + 1])
            ne[i] = ne[ne[i]];
        ne[i] += (s2[i] == s2[ne[i] + 1]);
    }

    for (int i = 1, j = 0; i < s1.size(); i++)
    {
        while (j && s1[i] != s2[j + 1])
            j = ne[j];
        if (s1[i] == s2[j + 1])
            j++;
        if (j == s2.size() - 1)
        {
            cout << i - j + 1 << "\n";
            j = ne[j];
        }
    }
    for (int i = 1; i < s2.size(); i++)
        cout << ne[i] << " ";

    return 0;
}
