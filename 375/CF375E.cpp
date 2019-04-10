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

template<class T> inline void smin(T &X,T Y){if(Y<X)X=Y;}
template<class T> inline void smax(T &X,T Y){if(X<Y)X=Y;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 500 + 100;

int n, maxdis;
int col[maxn];
vector<pii> adj[maxn];

bool fix[maxn];

pii p[maxn];
ll dep[maxn];
vector<pair<ll,int>> vd;

int ans;

void dfs_dis (int v, int par, ll depth)
{
	dep[v] = depth;
	vd.pb (mkp (depth, v));
	rep (i, sz(adj[v]))
	{
		int u = adj[v][i].X, w = adj[v][i].Y;
		if (u == par) continue;
		p[u] = pii (v, w);
		dfs_dis (u, v, depth+w);
	}
}

void dfs_fix (int v, int par, int dis)
{
	if (dis > maxdis) return;
	fix[v] = true;
	rep (i, sz(adj[v]))
	{
		int u = adj[v][i].X, w = adj[v][i].Y;
		if (u != par) dfs_fix (u, v, dis+w);
	}
}
/*
int dfs (int v, int par, int parw = 0)
{
	int ret = 0;
	rep (i, sz(adj[v]))
	{
		int u = adj[v][i].X, w = adj[v][i].Y;
		if (u == par || fix[u]) continue;
		smax (ret, w + dfs (u, v, w));
	}
	if (ret + parw > maxdis)
	{
		col[v] = 1;
		dfs_fix (v, -1, 0);
		throw 0;
	}
	return ret;
}
*/
int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> maxdis;
	rep (i, n) cin >> col[i];

	rep (i, n-1)
	{
		int x, y, w;
		cin >> x >> y >> w;
		x--, y--;
		adj[x].pb (pii (y, w));
		adj[y].pb (pii (x, w));
	}

	dfs_dis (0, -1, 0);
	p[0] = pii (-1, 0);
	sort (all(vd));
	reverse (all(vd));

//	rep (i, n) if (col[i] == 1)
//		dfs_fix (i, -1, 0);

	rep (i, n)
	{
		int v = vd[i].Y;
		cerr << " : " << v << endl;
		if (fix[v]) continue;

		int dis = 0;
		while (p[v].X != -1 && dis+p[v].Y <= maxdis) dis += p[v].Y, v = p[v].X;

		cerr << " ## " << v << endl;
		dfs_fix (v, -1, 0);
		ans++;
	}

	if (ans > accumulate (col, col+n, 0))
	{
		cout << -1 << endl;
		goto hell;
	}

	cout << ans << endl;
	
	hell:; { int _; cin >> _; return 0; }
}
