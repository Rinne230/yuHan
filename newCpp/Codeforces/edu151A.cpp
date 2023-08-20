#include <bits/stdc++.h>
using namespace std;
void solve(){
	int n, k, x;
	cin >> n >> k >> x;
	if(x == 1){
		if(k == 1){
			puts("NO");
            return;
		}
		else{
			if(k == 2 && n & 1){
				puts("NO");
                return;
			}
			else{
				puts("YES");
				if(n & 1){
					cout<<(n - 3) / 2 + 1<<"\n";
					cout << 3 << " ";
					for(int i = 0; i < (n - 3) / 2; i++)cout << "2 ";
                    cout<<"\n";
				}
				else{
					cout<< n / 2 << "\n";
					for(int i = 0; i < n / 2; i++)cout << "2 ";
                    cout << "\n";
				}
			}
		}
	}
	else{
		puts("YES");
		cout << n << "\n";
		for(int i = 0; i < n; i++)cout << 1 << " \n"[i == n - 1];
	}
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}