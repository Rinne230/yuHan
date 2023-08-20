#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 4e6 + 10;
struct note{ // 
	int l;
	int r;
	ll w;
}A[maxn];
ll a[maxn], b[maxn];
bool cmp(note A, note B){
	return A.w < B.w;
}
int main(){
	int n;
	cin >> n;
	ll suma = 0, sumb = 0;
	for(int i = 1; i <= n; i ++)
		scanf("%lld", &a[i]), suma += a[i];
	int m;
	cin >> m;
	for(int i = 1; i <= m; i ++)
		scanf("%lld", &b[i]), sumb += b[i];
	vector <pair<int, int>> ans;
	ll res = abs(suma - sumb);
	int cnt = 0;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			A[++cnt] = {i, j, 2ll * (a[i] - b[j])};
			if(res > abs(suma - sumb - 2ll * (a[i] - b[j]))){
				vector <pair<int, int>> temp;
				res = abs(suma - sumb - 2ll * (a[i] - b[j]));
				temp.push_back({i, j});
				ans = temp;
			}
		}
	}
	sort(A + 1, A + m * n + 1, cmp);
	for(int k = 1; k <= n; k++){
		for(int t = 1; t <= m; t++){
			ll temp = suma - sumb - 2ll * (a[k] - b[t]);	
			int l = 1, r = m * n;
			while(l < r){
				int mid = (l + r) >> 1;
				if(A[mid].w >= temp) r = mid;
				else l = mid + 1;
			}	
			if(A[l].w >= temp){
				while(A[l].l == k || A[l].r == t) l++;
				if(l <= m * n){
					if(res > abs(temp - A[l].w)){
						res = abs(temp - A[l].w);
						vector <pair<int, int>> c; 
						c.push_back({A[l].l, A[l].r});
						c.push_back({k, t});
						ans = c;
					}
				}
			}
			l = 1, r = m * n;
			while(l < r){
				int mid = (l + r + 1) >> 1;
				if(A[mid].w <= temp) l = mid;
				else r = mid - 1;
			}
			if(A[l].w <= temp){
				while(A[l].l == k || A[l].r == t) l--;
				if(l >= 1){
					if(res > abs(temp - A[l].w)){
						res = abs(temp - A[l].w);
						vector <pair<int, int> c;
						c.push_back({A[l].l, A[l].r});
						c.push_back({k, t});
						ans = c;
					}
				}
			}
		}
	}
	printf("%lld\n",res);
	printf("%d\n", ans.size());
	for(auto t : ans)
	printf("%d %d\n", t.first, t.second);
	return 0;
}	
