#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 10;
int n, m;
int a[maxn];

bool check(int mid){
    int tot = 0;
    for (int i = 0; i < m; ++i){
        if (a[i] - mid < tot + 1)
            if (a[i] < tot + 1)
                tot = a[i] + mid - 1;
            else 
                tot += mid;
        else
            return 0;
    }
    return tot > n - 1;
}
int main(){
    cin >> n >> m;
    for (int i = 0; i < m; ++i)
        cin >> a[i];
    sort(a, a + m);
    int l = 0, r = n, mid, ans;
    while (l < r + 1){
        mid = (l + r) >> 1;
        if (check(mid)){
            l = mid + 1;
        }
    }
    cout << (ans - 1) * 2 << endl;
    return 0;
}