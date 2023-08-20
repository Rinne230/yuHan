#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
const int maxn = 2e5 + 10;
int a[maxn];

void solve(){
	int n; 
    cin >> n;
	for(int i = 1; i <= n; i++) 
        cin >> a[i];
	int ans = a[1];
	for(int i = 2; i <= n; i++){
		ans &= a[i];
	}
	if(ans != 0) cout << 1 << '\n';
	else{
		int k = a[1], cnt = 0;
		for(int i = 1; i <= n; i++){
			k &= a[i];
			if(k == 0){
				cnt++;
				k = a[i + 1];
			}
		}
		cout << cnt << '\n';
	}

}
int main(){
	ios;
	int T; cin >> T;
    while(T--){
    	solve();
    }
    return 0;
}