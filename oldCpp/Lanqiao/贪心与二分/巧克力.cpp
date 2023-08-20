#include <bits/stdc++.h>
#include <queue>
using namespace std;
typedef long long ll;
const int N = 1e5 + 5;

struct node{
    int a, b, c;
    friend bool operator < (node p, node q){
        return p.a > q.a;
    }
} S[N];

int cmp(node &a, node &b){
    return a.b > b.b;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);
    int x, n;
    cin >> x >> n;
    for (int i = 0; i < n; ++i) cin >> S[i].a >> S[i].b >> S[i].c;
    sort(S, S + n, cmp);
    priority_queue<node> q;
    int cur = 0;
    ll ans = 0;
    q.push(S[cur++]);
    while (!q.empty() && x > 0){
        while (cur < n && S[cur].b >= x) q.push(S[cur++]);
        node tmp = q.top();
        q.pop();
        --x;
        ans += tmp.a;
        tmp.c--;
        if(tmp.c > 0) q.push(tmp);
    }
    if (x > 0) cout << -1;
    else cout << ans;
    return 0;
}