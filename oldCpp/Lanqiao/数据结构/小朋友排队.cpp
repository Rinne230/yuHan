#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
int tr[N], h[N];
typedef long long LL;
LL b[N];//求的是初始时在第i个位置的小朋友的被交换的次数
int lowbit(int x){
    return x & -x;
}
void add(int x, int v){
    for(int i = x; i <= N; i += lowbit(i)) tr[i] += v;
}
int query(int x){
    int res = 0;
    for(int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}
int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++) {scanf("%d", &h[i]); h[i]++; }
    for(int i = 1; i <= n; i++){
        add(h[i], 1);
        b[i] += i - query(h[i]);
    }
    memset(tr, 0, sizeof(tr));
    //倒过来求后面比它矮的人数
    for(int i = n; i >= 1; i--){
         add(h[i], 1);
         b[i] += query(h[i] - 1);
    }
    LL res = 0;
    for(int i=1;i<=n;i++){
        if(b[i]){
            res += (b[i] + 1) * b[i] / 2;
        }
    }
    cout << res << endl;
    return 0;
}

