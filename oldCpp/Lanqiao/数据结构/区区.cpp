#include <bits/stdc++.h>
using namespace std;
#define int long long
#define MAXN (int)(1e6 + 5)

int n,m;
int a[MAXN];
struct BIT{
	int bit1[MAXN],bit2[MAXN];
	int lowbit(int x){return x & (-x);}
	void add(int i, int v){
		int k = v * i;
		while(i <= n){
			bit1[i] += v, bit2[i] += k; // 维护的重点部分
			i += lowbit(i);
		}
	}
	int sum(int *b, int i){
		int res = 0;
		while(i >= 1){
			res += b[i];
			i -= lowbit(i);
		}
		return res;
	}
	int qry(int l, int r){
        return sum(bit1, r) * (r + 1) - sum(bit1, l - 1) * l - (sum(bit2, r) - sum(bit2, l - 1));
    }
}bt; 

signed main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> a[i], bt.add(i, a[i] - a[i - 1]);
	while(m--){
		int op, l, r, x;
		cin >> op >> l >> r;
		if(op == 1){cin >> x; bt.add(l, x), bt.add(r + 1, -x);}
		if(op == 2){printf("%lld\n", bt.qry(l, r));}
	}
	return 0;
}
