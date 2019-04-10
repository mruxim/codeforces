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

const int maxn = 100000 + 100;

int n, m, p, q;
int x[maxn], y[maxn], w[maxn];
vector<int> adj[maxn];
bool mark[maxn], mark_edge[maxn];
bool all_single;
multiset<ll> comps;
ll ans;

pair<int, ll> dfs (int v)
{
	if (mark[v]) return;
	mark[v] = true;

	int nsum = 1;
	ll esum = 0;

	for (int e: adj[v])
	{
		if (mark_edge[e]) continue;
		mark_edge[e] = true;
		esum += w[e];

		int u = x[e] + y[e] - v;
		auto tmp = dfs (u);
		nsum += tmp.X;
		esum += tmp.Y;
	}

	return mkp (nsum, esum);
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m >> p >> q;
	rep (i, m)
	{
		cin >> x[i] >> y[i] >> w[i];
		x[i]--, y[i]--;
		adj[x[i]].pb (i);
		adj[y[i]].pb (i);
	}

	all_single = true;
	rep (i, n) if (!mark[i])
	{
		auto tmp = dfs (i);
		if (tmp.X > 1) all_single = false;
		comps.insert (tmp.Y);
	}

	while (sz(comps) > q)
	{
		p--;
		ll sum1 = *comps.begin(); comps.erase (comps.begin());
		ll sum2 = *comps.begin(); comps.erase (comps.begin());
		int new_edge = (int)min (sum1 + sum2 + 1, (ll)1e9);
		comps.insert (sum1 + sum2 + new_edge);
		all_single = false;
	}

	if (p < 0 || (p > 0 && all_single))
		cout << "NO" << endl;
	else
	{
		cout << "YES" <<endl;
		
	}

	{ int _; cin >> _; return 0; }
}
