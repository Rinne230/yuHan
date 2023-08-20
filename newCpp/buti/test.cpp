#include <bits/stdc++.h>
#define endl '\n'
#define pll pair<ll, ll>
#define tll tuple<ll, ll, ll>
#define rep(i, j, k) for(int i = (j); i <= (k); i++)
#define per(i, j ,k) for(int i = (j); i >= (k); i--)
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;
const ll maxn = 2e5 + 10;
const ll mod = 998244353;
const ll inf = 0x3f3f3f3f;


void solve(){
    string s;
    cin>>s;
    // assert(0);
    auto mex = [&](vector <int> k)
    {
        int M = 0;
        sort(k.begin(),k.end());
        for(auto i:k)
        if(i==M) M++;
        else if(i>M) break;
        return M;
    };
    auto check = [&](string s) -> bool
    {
        int len = s.size();
        int l = 0,r = 0;
        for(int i=1;i<=((len+1)>>1);i++)
        if(s[i-1]=='1') l++;
        for(int i=(len>>1)+1;i<=len;i++)
        if(s[i-1]=='1') r++;
        if(l==r&&l==1) return true;
        return false;
    };
    auto check1 = [&](string s) -> bool
    {
        int len = s.size();
        int l = 0,r = 0;
        for(int i=1;i<=((len+1)>>1);i++)
        if(s[i-1]=='1') l++;
        for(int i=(len>>1)+1;i<=len;i++)
        if(s[i-1]=='1') r++;
        if(!l||!r) return true;
        return false;
    };
    function <int(string)> dfs = [&](string now)
    {
        int len = now.size();
        if(check(now)) return 0;
        vector <int> k;
        for(int i=0;i<len;i++)
        {
            if(now[i]=='1')
            {
                auto tp = now;
                tp[i] = '0';
                if(!check1(tp))
                k.push_back(dfs(tp));
            }
        }
        return mex(k);
    } ;
    // assert(0);
    cout<< s + " : " << dfs(s)<<"\n";
    // assert(0);
}

int main(){
    ios;
    freopen("sample.txt","r",stdin);
    freopen("test.txt","w",stdout);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}