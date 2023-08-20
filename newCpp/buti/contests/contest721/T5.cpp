#include <bits/stdc++.h>
#define fup(i,s,n) for(int i=s;i<=n;i++)
#define fdn(i,n,s) for(int i=n;i>=s;i--)
using namespace std;
using i64 = long long;
using pii = pair<i64,i64>;
constexpr int mod = 998244353;
constexpr int MAXN_32 = 2e9;
constexpr i64 MAXN_64 = 1e18;
int t = 1;
void solve()
{
    auto ismirror = [&](char a,char b)
    {
        if(a>b) swap(a,b);
        if(a=='d'&&b=='p') return true;
        if(a=='b'&&b=='q') return true;
        if(a=='s'&&b=='s') return true;
        if(a=='x'&&b=='x') return true;
        if(a=='n'&&b=='u') return true;
        if(a=='z'&&b=='z') return true;
        if(a=='o'&&b=='o') return true;
        return false;
    };
    auto isMirror = [&](char a)
    {
        if(a=='s') return true;
        if(a=='x') return true;
        if(a=='o') return true;
        if(a=='z') return true;
        return false;
    };
    string s;
    cin>>s;
    for(auto i:s)
    {
        if(!(i=='b'||i=='q'||i=='d'||i=='p'||i=='z'||i=='o'||i=='x'||i=='u'||i=='n'||i=='s'))
        {
            cout<<"No\n";
            return ;
        }
    }
    int n = s.size();
    int lst = 0;
    s = " "+s;
    stack <char> c;
    for(int i=1;i<=n;i++)
    {
        if(!isMirror(s[i]))
        {
            if(c.empty())
            {
                c.push(s[i]);
                continue;
            }
            if(ismirror(c.top(),s[i]))
            {
                c.pop();
                if(c.empty())
                {
                    bool ok = 0;
                    for(int j=0;j<=(i-lst)/2;j++)
                    {
                        if(!ismirror(s[lst+j+1],s[i-j]))
                        {
                            ok = 1;
                            break;
                        }
                    }
                    if((i-lst)&1)
                    {
                        if(!isMirror(s[lst+(i-lst)/2+1])) ok = 1;
                    }
                    if(ok)
                    {
                        cout<<"No\n";
                        return ;
                    } 
                    lst = i;
                }
            }
            else c.push(s[i]);
        }
        else
        {
            if(c.empty()) lst = i;
        }
    }
    if(!c.empty())
    {
        cout<<"No\n";
        return ;
    }
    cout<<"Yes\n";
}
int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    cin>>t;
    while(t--) solve();
    return 0;
}