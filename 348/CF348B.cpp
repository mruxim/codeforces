// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <bitset>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define pb push_back
#define mkp make_pair
#define all(X) (X).begin(),(X).end()

#define X first
#define Y second

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const ll inf = 1e13 + 10;
const int maxn = 100000 + 100;

int n;
int a[maxn];
vector<int> adj[maxn];
ll f[maxn];
ll lcm = 1;

void dfs (int u, ll val, int par = -1)
{
	int deg = sz(adj[u]) - (par != -1 ? 1 : 0);
	smin (val, inf); f[u] = val;
	lcm /= __gcd<ll> (lcm, val);
	if (1e15/lcm > val) lcm *= val; else lcm = 1e15;
	for (int v: adj[u]) if (v != par) dfs (v, val*deg, u);
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> a[i];
	rep (i, n-1)
	{
		int u, v; cin >> u >> v; u--, v--;
		adj[u].pb (v), adj[v].pb (u);
	}

	dfs (0, 1);

	ll tot = accumulate (a, a+n, 0LL), orig = tot;
	fer (i, 1, n) if (sz(adj[i]) == 1) smin (tot, min ((ll)a[i], (ll)1e17/f[i]) * f[i]);
	tot = tot / lcm * lcm;
	cout << orig - tot << endl;

	{ return 0; }
}

