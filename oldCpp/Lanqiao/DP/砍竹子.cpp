#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct bamboo{
    ll h;
    ll num;
    friend bool operator < (bamboo a, bamboo b){
        if (a.h == b.h) return a.num > b.num;
        return a.h < b.h;
    }
};
priority_queue<bamboo> q;
int main(){
    ll n, ans = 0;
    cin >> n;
    for (ll i = 1, h; i <= n; ++i){
        cin >> h;
        q.push(bamboo{h, i});
    }
    while(q.top().h != 1){
        ll h = q.top().h;
        ll num = q.top().num - 1;
        while(q.top().h == h && q.top().num == num + 1){
            num++;
            q.pop();
            ll tmp = sqrt(h / 2 + 1);
            q.push(bamboo{tmp, num});
        }
        ans++;
    }
    cout << ans << endl;
    return 0;
}