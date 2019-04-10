// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int((x).size()))
#define cmx(a, b) (a = max(a,b))
#define cmn(a, b) (a = min(a,b))
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

////////////////////////////////////////////////

const int maxn = 100000 + 1000;

int n;
int x[maxn], y[maxn];
vi a[maxn];
bool mark[maxn];
int dep[maxn];
int p[maxn][18];
int f[maxn];
int val[maxn];

void dfs (int v, int d)
{
	mark[v] = 1;
	dep[v] = d;
	fer (i, 1, 18)
	{
		if (p[v][i-1] == -1) break;
		p[v][i] = p[p[v][i-1]][i-1];
	}
	fch (it, a[v])
	{
		int u = *it;
		if (mark[u]) continue;
		p[u][0] = v;
		dfs (u, d+1);
	}
}

int lca (int u, int v)
{
	if (dep[u] > dep[v]) swap (u, v);
	rof (i, 18, 0)
		if (dep[v] - (1<<i) >= dep[u])
			v = p[v][i];
	if (u == v) return u;
	rof (i, 18, 0)
		if (p[u][i] != p[v][i])
			u = p[u][i], v = p[v][i];
	return p[u][0];
}

void cal (int v)
{
	mark[v] = 1;
	fch (it, a[v])
	{
		int u = *it;
		if (mark[u]) continue;
		cal (u);
		val[v] += val[u];
	}
	val[v] += f[v];
}


int main()
{
	cin >> n;
	rep (i, n-1)
	{
		cin >> x[i] >> y[i];
		x[i]--, y[i]--;
		a[x[i]].pb (y[i]);
		a[y[i]].pb (x[i]);
	}

	rep (i, 18) p[0][i] = -1;
	dfs (0, 0);
	
	int q;
	for (cin >> q; q--; )
	{
		int u, v;
		cin >> u >> v;
		u--, v--;
		int t = lca (u, v);
//		cerr << " ** " << u+1 << ' ' << v+1 << ' ' << t+1 << endl;
		f[u]++, f[v]++, f[t] -= 2;
	}
	
	memset (mark, false, sizeof mark);
	cal (0);
	
	rep (i, n-1)
	{
		if (p[x[i]][0] == y[i]) swap (x[i], y[i]);
		cout << val[y[i]] << ' ';
	}
	cout << endl;
	
	{ int _; cin >> _; }
}
