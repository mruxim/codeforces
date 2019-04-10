
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

const int maxn = 200000 + 100;

int n, m;
int a[maxn];
vector<int> adj[maxn];
int dep[maxn], st[maxn], ed[maxn], now;
int fen[2][maxn];

void dfs (int u, int par = -1, int depth = 0)
{
	st[u] = now++;
	dep[u] = depth;
	for (int v: adj[u]) if (v != par)
		dfs (v, u, depth+1);
	ed[u] = now;
}

void add (int* f, int x, int val)
{
	for (x++; x < maxn; x += x&-x) f[x] += val;
}

int get (int* f, int x)
{
	int r = 0;
	for (x++; x; x -= x&-x) r += f[x];
	return r;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, n) cin >> a[i];
	rep (i, n-1)
	{
		int u, v; cin >> u >> v; u--, v--;
		adj[u].pb (v), adj[v].pb (u);
	}

	dfs (0);

	while (m--)
	{
		int tp, x;
		cin >> tp >> x; x--;
		int *f = fen[dep[x]%2], *g = fen[1-dep[x]%2];
		if (tp == 1)
		{
			int val; cin >> val;
			add (f, ed[x], -val);
			add (f, st[x], val);
			add (g, ed[x], val);
			add (g, st[x], -val);
		}
		else
			cout << a[x] + get (f, st[x]) << endl;
	}

	{ return 0; }
}

