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

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n;
vector<pii> adj[maxn];
bool mark[maxn];
bool c[maxn];

bool dfs (int v, bool sh)
{
	if (mark[v]) return false;
	mark[v] = 1;
	bool ok = false;
	rep (i, sz(adj[v]))
	{
		int u = adj[v][i].X, t = adj[v][i].Y;
		ok |= dfs (u, t);
	}
	if (!ok && sh)
		c[v] = true;
	return c[v] | ok;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n-1)
	{
		int x, y, t;
		cin >> x >> y >> t;
		x--, y--, t--;
		adj[x].pb (pii (y, t));
		adj[y].pb (pii (x, t));
	}

	dfs (0, 0);

	int k = count (c, c+n, 1);
	cout << k << endl;
	rep (i, n) if (c[i]) cout << i+1 << ' ';
	cout << endl;

	{ int _; cin >> _; return 0; }
}
