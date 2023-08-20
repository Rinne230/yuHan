#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
bool fg[maxn];
stack<char> st;

bool isIll(char a)
{
    if (a == 'o' || a == 'z' || a == 's' || a == 'x' || a == 'b' || a == 'q' || a == 'p' || a == 'd' || a == 'u' || a == 'n')
        return true;
    return false;
}

bool isSym(char a)
{
    if (a == 'o' || a == 'z' || a == 's' || a == 'x')
        return true;
    return false;
}

bool isSymmetric(char a, char b)
{
    if (a == b && (a == 'o' || a == 'x' || a == 's' || a == 'z'))
        return true;
    if ((a == 'b' && b == 'q') || (a == 'q' && b == 'b'))
        return true;
    if ((a == 'p' && b == 'd') || (a == 'd' && b == 'p'))
        return true;
    if ((a == 'n' && b == 'u') || (a == 'u' && b == 'n'))
        return true;
    return false;
}

void solve()
{
    memset(fg, 0, sizeof fg);
    string s;
    cin >> s;
    vector<int> lst;
    while (!st.empty())
        st.pop();
    if (s == "")
        cout << "Yes" << endl;
    bool flag = true;
    for (int i = 0; i < s.length(); ++i)
    {
        if (!isIll(s[i])) // 不是正常字符
        {
            cout << "No" << endl;
            return;
        }

        if (isSym(s[i])) // oxsz类的直接过
        {
            continue;
        }

        if (st.empty())
        {
            st.push(s[i]);
            if (flag == true)
            {
                flag = false;
                lst.push_back(i);
            }
        }
        else
        {
            char ch = st.top();
            if (isSymmetric(ch, s[i]))
            {
                st.pop();
                if (!flag && st.empty())
                {
                    bool iscan = false;
                    int tmp = 1;
                    for (int j = lst.size() - 1; j >= 0; j -= (tmp / 2))
                    {
                        //cout << lst[j] << " " << i << endl;
                        int l = lst[j], r = i;
                        bool isiscan = true;
                        while (l <= r)
                        {
                            if (!isSymmetric(s[l], s[r]))
                            {
                                tmp <<= 1;
                                isiscan = false;
                                break;
                            }
                            l++;
                            r--;
                        }
                        if (isiscan){
                            iscan = true;
                            for (int k = j; k < lst.size(); ++k){
                                fg[lst[k]] = 1;
                            }
                            break;
                        }
                    }
                    flag = true;
                }
            }
            else
            {
                st.push(s[i]);
            }
        }
    }
    for (int i = 0; i < lst.size(); ++i){
        if (!fg[lst[i]]){
            cout << "No" << endl;
            break;
        }
    }
    if (st.empty())
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
int main()
{
    ios;
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
