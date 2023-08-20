#include <bits/stdc++.h>
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define endl '\n'
using namespace std;


void solve() {
	string s, t1, t2;
	int m , k = 0;
	cin >> s >> m >> t1 >> t2;
	for (int i = 0; i <= m - 1; ++i){
		int maxx = 0;
		for (char j = t1[i]; j <= t2[i]; ++j) {
			int tmp = s.find(j, k);
			if (tmp == s.npos) {
				cout<< "YES" <<endl;
				return;
			}
			maxx = max(maxx, tmp + 1);
		}
		k = maxx;
	}
	cout << "NO" <<endl;
}

int main(){
    ios;
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}