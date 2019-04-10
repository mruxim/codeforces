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
typedef pair<pii, int> Q;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n, m;
int o_col[maxn], cc[maxn], col[maxn];
vector<int> pos[maxn];
int ind[maxn];
vector<int> adj[maxn];

int st[maxn], ed[maxn], rv[maxn], now;

vector<Q> q;
int ans[maxn];

void dfs (int v, int par = -1)
{
	st[v] = now, rv[now] = v, now++;
	for (int u: adj[v]) if (u != par)
		dfs (u, v);
	ed[v] = now;
}

int f[maxn];
void add (int x, int v) { for (x++; x < n+10; x += x&-x) f[x] += v; }
int get (int x) { int r=0; for (x++; x; x -= x&-x) r += f[x]; return r; }

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, n) cin >> o_col[i], o_col[i]--;

	rep (i, n) cc[i] = o_col[i];
	sort (cc, cc+n);
	int cols = unique (cc, cc+n) - cc;
	rep (i, n) o_col[i] = lower_bound (cc, cc+n, o_col[i]) - cc;

	rep (i, n-1)
	{
		int u, v;
		cin >> u >> v; u--, v--;
		adj[u].pb (v), adj[v].pb(u);
	}
	
	rep (z, m)
	{
		int v, k;
		cin >> v >> k; v--;
		q.pb (mkp (pii(v, k), z));
	}


	dfs (0);
	rep (i, n) col[i] = o_col[rv[i]], pos[col[i]].pb (i);

//	rep (i, n) cerr << " - " << col[i]+1; cerr << endl;
	sort (all(q), [](Q q1, Q q2){ return st[q1.X.X] < st[q2.X.X]; });
//	rep (i, m) cerr << st[q[i].X.X] << ' ' << ed[q[i].X.X] << ' ' << q[i].X.Y << ' ' << q[i].Y << endl;

	fer (k, 1, 100)
	{
		memset (f, 0, sizeof f);
//	cerr << " k == " << k << endl;
		rep (c, cols)
		{
			ind[c] = k-1;
			if (ind[c] < sz(pos[c]))
				add (pos[c][ind[c]], 1);
		}

		int qp = 0;
		rep (i, n)
		{
			while (qp < sz(q) && st[q[qp].X.X] < i) qp++;
			while (qp < sz(q) && st[q[qp].X.X] == i)
			{
				if (q[qp].X.Y == k)
				{
					ans[q[qp].Y] = get (ed[q[qp].X.X]-1);
//					cerr << " ans " << q[qp].Y << " --> " << ans[q[qp].Y] << endl;
				}
				qp++;
			}

			int &id = ind[col[i]];
			vector<int> &v = pos[col[i]];

			if (id < sz(v)) add (v[id], -1);
			id++;
			if (id < sz(v)) add (v[id], 1);
		}
	}

	rep (c, cols) if (sz(pos[c]) >= 100)
	{
		rep (i, m) if (q[i].X.Y >= 100 && lower_bound (all(pos[c]), ed[q[i].X.X]) - lower_bound (all(pos[c]), st[q[i].X.X]) >= q[i].X.Y)
			ans[q[i].Y]++;
	}

	rep (i, sz(q))
		cout << ans[i] << endl;

	{ int _; cin >> _; return 0; }
}
