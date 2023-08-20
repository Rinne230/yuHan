#include <bits/stdc++.h>
#define endl '\n'
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;

struct node{
    int num;
    int idx;
};
bool cmp(node a, node b){
    return a.num < b.num;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<node> a(n);
        for (int i = 0; i < n; ++i){
            cin >> a[i].num;
            a[i].idx = i;
        }
        sort(a.begin(), a.end(), cmp);
        vector<int> b(n), ans(n);
        for (int i = 0; i < n; ++i){
            cin >> b[i];
        }
        sort(b.begin(), b.end());
        for (int i = 0; i < n; ++i){
            ans[a[i].idx] = b[i];
        }
        for (int i = 0; i < n; ++i)
            cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}