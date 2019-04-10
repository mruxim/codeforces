//#define FROM_FILE
//#define TO_FILE

//-Wl,--stack,52800000
#include <bits/stdc++.h>

using namespace std;

#define foreach(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define MP make_pair
#define PB push_back
#define FF first
#define SS second
#define All(n) (n).begin(), (n).end()

typedef long long int lli;
typedef unsigned long long int ull;
typedef pair<int,int> pii;
typedef pair<lli,lli> pll;
typedef vector<int> vi;

#ifdef FROM_FILE
void* __VERY__LONG__FROM=freopen("in.txt","r",stdin);
#endif

#ifdef TO_FILE
void* __VERY__LONG__TO=freopen("out.txt","w",stdout);
#endif

const int MAXN=100*1000 + 10;
const int MOD=1000*1000*1000 + 7;
//const lli INF=1000000000000000000ll;
vector<int> dv[MAXN];
int f;
lli dp[MAXN];
int mark[MAXN];
int zz;

lli po(lli p,lli b)
{
    if(!p)return 1;
    lli r=po(p/2,b);
    r=(r*r)%MOD;
    if(p&1)
        r=(r*b)%MOD;
    return r;
}

lli fac[MAXN];

lli comb(lli n,lli k)
{
    lli res=fac[n];
    res*=po(MOD-2,fac[k]);
    res%=MOD;
    res*=po(MOD-2,fac[n-k]);
    res%=MOD;
    return res;
}

lli cdp(int x)
{
    lli& ans=dp[x];
    if(f-1>x-1)return 0;
    if(mark[x]==zz)return ans;
    mark[x]=zz;
    lli kol=comb(x-1,f-1);
    //halate bad
    lli bad=0;
    for(int i=0;i<dv[x].size();i++)
    {
        bad+=cdp(x/dv[x][i]);
        bad%=MOD;
    }
    ans=(kol+MOD-bad)%MOD;
    return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	fac[0]=fac[1]=1;
	for(int i=2;i<MAXN;i++)
        fac[i]=(fac[i-1]*i)%MOD;
	for(int i=2;i<MAXN;i++)
        for(int j=i;j<MAXN;j+=i)
            dv[j].PB(i);
	int tt;
//	cin>>tt;
	tt = 100000;
	for(zz=1;zz<=tt;zz++)
    {
        int n;
//        cin>>n>>f;
		n = 60060, f = 1;
        cout<<cdp(n)<<endl;
    }
    return 0;
}
