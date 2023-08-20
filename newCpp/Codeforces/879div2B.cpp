#include <bits/stdc++.h>
using namespace std;
string n, m;
void solve() {
	cin >> n >> m;
	while(n.size() < m.size()) n = '0' + n;
	int pos = n.size();
	for(int i = 0; i < n.size(); i++) {
		if(n[i] != m[i]) {
			pos = i;
			break;
		}
	}
	for(int i = pos + 1; i < n.size(); i ++ ) m[i] = '0', n[i] = '9';
	int ans = 0;
	for(int i = 0; i < n.size(); i ++ ) ans += abs(n[i] - m[i]);
	cout << ans << "\n";
}

int main() {
	ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while(t--) {
        solve();
    }
	return 0;
}