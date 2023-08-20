#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("input.txt","r",stdin);
    freopen("wrong.txt","w",stdout);
    int a,b;
    cin >> a >> b;
    if(b%100==0) b++;
    cout << a+b;
    return 0;
}