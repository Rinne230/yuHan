#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n;
string s, p;

void solve() {
	int ans = 0, ans1 = 0;
	cin >> n >> s >> p;
	for(int i = 0; i < n; i ++ ) {
		if(s[i] != p[i]) ans++ ;
		if(s[n - i - 1] != p[i]) ans1++ ;
	}
	if(ans & 1) ans = ans * 2 - 1;
	else ans = ans * 2;
	if(ans1 % 2 == 0) ans1 = max(2, ans1 * 2 - 1);
	else ans1 = ans1 * 2;
	cout << min(ans, ans1) << "\n";
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	int t;
	cin >> t;
	while(t -- ) solve();
	return 0; 
}