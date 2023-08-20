#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
typedef long long ll;
struct node
{
    ll num, idx;
};

ll n, b[maxn], idnum[maxn], gnum[maxn];
node a[maxn];

bool cmp(node x, node y)
{
    return x.num > y.num;
}

void solve()
{
    cin >> n;
    map<ll, ll> mp, len;
    bool flag = true;
    for (int i = 1; i <= n; ++i)
    {
        ll x;
        cin >> x;
        a[i].num = x;
        a[i].idx = i;
        idnum[i] = x;
    }
    sort(a + 1, a + n + 1, cmp);
    if (a[1].num == 0)
    {
        cout << "YES" << endl;
        for (int i = 1; i <= n; ++i)
            cout << -i << " ";
        cout << endl;
        return;
    }
    // 否则，从第二个元素开始遍历数组a
    ll tmp = a[1].idx, lst = 1;
    b[tmp] = a[1].num;
    mp[b[tmp]] = 1;
    gnum[1] = b[tmp];
    for (int i = 2; i <= n; ++i)
    {
        if (a[i].num > lst)
        {
            // 如果当前元素的值大于上一个元素的值，则更新b数组的值为上一个元素对应的b数组的值
            if (a[i].num == a[i - 1].num)
            {
                b[a[i].idx] = b[a[i - 1].idx];
            }
            else
            {
                b[a[i].idx] = b[a[i - 1].idx] - 2;
            }
            lst += 1;
            gnum[lst] = b[a[i].idx];
        }
        else if (a[i].num == 0)
        {
            // 如果当前元素的值为0，则将b数组的值设为-n
            b[a[i].idx] = -n;
        }
        else
        {
            // 根据规则计算b数组的值
            b[a[i].idx] = -gnum[a[i].num] + 1;
        }
        // 更新mp和gnum数组
        mp[b[a[i].idx]] = 1;
    }
    // 将b数组的值按顺序放入len数组，并通过后缀和计算每个值出现的次数
    for (int i = 1; i <= n; ++i)
    {
        len[b[i]]++;
    }
    for (int i = n - 1; i >= -n; --i)
        len[i] = len[i + 1] + len[i];
    // 再次遍历数组a，判断len数组中对应值的出现次数是否和数组a中的元素值相等
    for (int i = 1; i <= n; ++i)
    {
        if (len[-b[i]] != idnum[i])
        {
            flag = false;
            break;
        }
    }
    // 如果无法构造不平衡数组，则输出NO
    if (!flag)
    {
        cout << "NO" << endl;
        return;
    }
    // 输出YES，并打印b数组的值作为不平衡数组
    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i)
    {
        cout << b[i] << " ";
    }
    cout << endl;
}

int main()
{
    ios;
    // 读入测试用例数量t
    int t;
    cin >> t;
    while (t--)
    {

        solve();
    }
    return 0;
}