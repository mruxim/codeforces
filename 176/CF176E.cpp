// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <set>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;
const int maxlog = 17 + 1;

int n, q;
vector <pii> adj[maxn];
int id[maxn], now;
int dep[maxn], par[maxn][maxlog];
ll dist[maxn];

set <int> s;
ll ans;

void dfs (int u, int depth)
{
	int uid = id[u];
	dep[uid] = depth;
	fer (i, 1, maxlog)
		par[uid][i] = par[par[uid][i-1]][i-1];
	for (auto v: adj[u]) if (id[v.X] == -1)
	{
		id[v.X] = now++;
		par[id[v.X]][0] = uid;
		dist[id[v.X]] = dist[uid] + v.Y;
		dfs (v.X, depth + 1);
	}
}

ll get (int u, int v)
{
	ll ret = dist[u] + dist[v];
	if (dep[u] > dep[v])
		swap (u, v);
	rof (i, maxlog, 0)
		if (dep[par[v][i]] >= dep[u])
			v = par[v][i];
	if (u == v)
		return ret - 2 * dist[u];
	rof (i, maxlog, 0)
		if (par[u][i] != par[v][i])
			u = par[u][i], v = par[v][i];
	return ret - 2 * dist[par[u][0]];
}

int main()
{
	cin >> n;
	rep (i, n-1)
	{
		int u, v, w;
		cin >> u >> v >> w; u--, v--;
		adj[u].push_back (pii (v, w));
		adj[v].push_back (pii (u, w));
	}

	memset (id, -1, sizeof id);
	id[0] = now++;
	dfs (0, 0);

	cin >> q;
	while (q--)
	{
		char com;
		int x;
		cin >> com;
		if (com == '?')
			cout << ans / 2 << endl;
		else if (com == '+')
		{
			cin >> x; x = id[x-1];
			auto it = s.insert (x).first;
			if (s.size() == 1) continue;
			auto prev = it, next = it;
			if (prev == s.begin()) prev = s.end(); prev--;
			next++; if (next == s.end()) next = s.begin();
			ans -= get (*prev, *next);
			ans += get (*prev, *it);
			ans += get (*it, *next);
		}
		else // com == '-'
		{
			cin >> x; x = id[x-1];
			auto it = s.find (x);
			if (s.size() == 1) { s.erase (it); continue; }
			auto prev = it, next = it;
			if (prev == s.begin()) prev = s.end(); prev--;
			next++; if (next == s.end()) next = s.begin();
			ans += get (*prev, *next);
			ans -= get (*prev, *it);
			ans -= get (*it, *next);
			s.erase (it);
		}
	}
	{ int _; cin >> _; }
	return 0;
}
