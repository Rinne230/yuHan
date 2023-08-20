#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

ll resp(int n){
	ll sum = 0;
	while(n){
		int d = n % 10;
		sum += a[d];
		n /= 10;
	}
	return sum;
}
int main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	ll a, b;
    cin >> a >> b;
	ll res = 0;
	for(int i = a ; i <= b ; i ++){
		res += resp(i);
	}
	cout << res << '\n';
	return 0;
}

