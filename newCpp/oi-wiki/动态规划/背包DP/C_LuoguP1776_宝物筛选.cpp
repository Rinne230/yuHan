#include <cstdio>
#define N 40001
int n, t, dp[2][N], q[N], w, c, v, l, r, cnt = 0;
int main() {
   scanf("%d%d", &n, &t);
   while (n--) {
   	scanf("%d%d%d", &v, &w, &c);
   	for (int d = 0; d < w; d++) {
   		l = r = 0;
   		for (int k = 0; k*w+d <= t; k++) {
   			#define val(x) (dp[!cnt][x*w+d]-x*v)
   			while (l < r && q[l] < k-c) l++;
   			while (l < r && val(q[r-1]) <= val(k)) r--;
   			q[r++] = k;
   			dp[cnt][k*w+d] = val(q[l])+k*v;
   		}
   	}
   	cnt = !cnt;
   }
   printf("%d\n", dp[!cnt][t]);
}