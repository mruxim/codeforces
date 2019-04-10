// .... .... .....!
// P..... C.....!

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

const int maxn = 10000 + 100;
const int maxk = 100 + 10;

int n, m, k;
int s1, s2, f;
vector<pii> adj[maxn];
vector<int> adjK[maxn];

ll dis[maxn];
int who[maxn];

struct cmp {
	bool operator () (const int &x, const int &y) const {
		return dis[x] != dis[y] ? dis[x] < dis[y] : x < y;
	}
};

set<int, cmp> dij;

int x[maxk], y[maxk], l[maxk], r[maxk];

void dijkstra ()
{
	memset (dis, 50, sizeof dis);
	dis[s1] = dis[s2] = 0;
	who[s1] = 1, who[s2] = 2;
	if (s1 == s2) who[s1] = 3;
	dij.insert (s1);
	dij.insert (s2);

	while (!dij.empty())
	{
		int v = *dij.begin();
		dij.erase (*dij.begin());

		for (pii uw: adj[v])
		{
			int u = uw.X, w = uw.Y;
			if (dis[u] < dis[v] + w) continue;
			if (dis[u] == dis[v] + w) who[u] |= who[v];
			else who[u] = who[v];
			dij.erase (u);
			dis[u] = min (dis[u], dis[v] + w);
			dij.insert (u);
		}

		for (int e: adjK[v])
		{
			int u = x[e]+y[e]-v;
			l[e] = r[e] = (who[v] % 2 ? l[e] : r[e]);

			int w = l[e];
			if (dis[u] < dis[v] + w) continue;
			if (dis[u] == dis[v] + w) who[u] |= who[v];
			else who[u] = who[v];
			dij.erase (u);
			dis[u] = min (dis[u], dis[v] + w);
			dij.insert (u);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m >> k;
	cin >> s1 >> s2 >> f;
	s1--, s2--, f--;

	rep (i, m)
	{
		int x, y, w;
		cin >> x >> y >> w;
		x--, y--;
		adj[x].push_back (pii (y, w));
//		adj[y].push_back (pii (x, w));
	}

	rep (i, k)
	{
		cin >> x[i] >> y[i] >> l[i] >> r[i];
		x[i]--, y[i]--;
		adjK[x[i]].push_back (i);
//		adjK[y[i]].push_back (i);
	}

	dijkstra();

	cout << (who[f] == 1 ? "WIN" : who[f] == 2 ? "LOSE" : "DRAW") << endl;
	if (who[f] % 2)
	{
		rep (i, k) cout << l[i] << ' ';
		cout << endl;
	}

	{ int _; cin >> _; return 0; }
}
