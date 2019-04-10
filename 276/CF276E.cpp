// .... .... .... !

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define X first
#define Y second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 200000 + 100;

int n, q;
vector <int> adj[maxn];
int dis[maxn], grp[maxn], gn = 0;
vector <int> fen[maxn], tf;
int add1;

void dfs (int x)
{
	bool b = false;
	for (int y: adj[x])
		if (dis[y] == -1)
		{
			dis[y] = dis[x]+1;
			if (x==0)
				grp[y] = gn++;
			else
				grp[y] = grp[x];
			dfs (y);
			b = true;
		}
	if (x != 0 && !b)
		fen[grp[x]].resize (dis[x] + 2);
}

void add (vector <int> &f, int p, int x)
{
	int n = sz(f);
	if (p>=n) p = n-1;
	for ( ; p; p -= p&-p)
		f[p] += x;
}

int get (vector <int> &f, int p)
{
	int x = 0;
	int n = sz(f);
	for ( ; p<n; p += p&-p)
		x += f[p];
	return x;
}

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> q;
	rep (i, n-1)
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	memset (dis, -1, sizeof dis);
	dis[0] = 0;
	dfs (0);
	tf.resize (n+2);

	rep (z, q)
	{
		int ord;
		cin >> ord;
		if (ord == 0)
		{
			int v, x, d;
			cin >> v >> x >> d; v--;
			if (v == 0)
				add (tf, d, x), add1 += x;
			else
			{
				add (fen[grp[v]], dis[v]+d, x);
				if (dis[v]-d > 0)
					add (fen[grp[v]], dis[v]-d-1, -x);
				else
				{
					add (tf, d-dis[v], x);
					add1 += x;
					add (fen[grp[v]], d-dis[v], -x);
				}
			}
		}
		else
		{
			int v;
			cin >> v; v--;
			if (v == 0)
				cout << add1 << endl;
			else
				cout << get (tf, dis[v]) + get (fen[grp[v]], dis[v]) << endl;
		}
	}

	{ int _; cin >> _; return 0; }
}
