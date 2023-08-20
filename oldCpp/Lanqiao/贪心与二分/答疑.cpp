#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct node{
    int a, b, c;
    ll sum;
    friend bool operator < (node a, node b){
        return a.sum < b.sum;
    }
}stu[1005];
int n;

int main(){
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int a, b, c;
        cin >> stu[i].a >> stu[i].b >> stu[i].c;
        stu[i].sum = stu[i].a + stu[i].b + stu[i].c;
    }    
    sort(stu + 1, stu + n + 1);
    ll ans = 0, tim = 0;
    for (int i = 1; i <= n; ++i){
        tim += stu[i].a + stu[i].b;
        ans += tim;
        tim += stu[i].c;
    }
    cout << ans << endl;
    return 0;
}