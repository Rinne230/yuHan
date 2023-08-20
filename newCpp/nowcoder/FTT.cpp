#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int n,m;
ll a[N],b[N],c[N];
void mul(ll *a,ll *b,ll *c){
	for(int k=0;k<=n+m;k++)
		for(int i=0;i<=k;i++)
			c[k]+=a[i]*b[k-i];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=0;i<=m;i++) scanf("%lld",&b[i]);
	mul(a,b,c);
	for(int i=0;i<=n+m;i++) printf("%lld ",c[i]);printf("\n");
	return 0;
}
