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
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;

////////////////////////////////////////////////

const int maxn = 100000+100;

int n;
vi adj[maxn];
bool mark[maxn];
int x[maxn], y[maxn];
int sub[maxn];
ll sx, sy, subx[maxn];
ld ans;

void dfs (int v)
{
	mark[v] = true;
	sub[v] = 1;
	subx[v] = x[v];
	rep (i, sz(adj[v]))
	{
		int u = adj[v][i];
		if (mark[u]) continue;
		dfs (u);
		sub[v] += sub[u];
		subx[v] += subx[u];
		ans += sub[u] * (ll)subx[u] /(ld)sx * y[v] / sy;
		ans += (n-sub[u]) * (ll)(sx-subx[u]) / (ld)sx * y[u] / sy;
	}
}

int main()
{
	scanf ("%d", &n);
	rep (i, n-1)
	{
		int u, v;
		scanf ("%d%d", &u, &v);
		u--, v--;
		adj[u].pb (v);
		adj[v].pb (u);
	}
	rep (i, n)
		scanf ("%d%d", x+i, y+i), sx += x[i], sy += y[i];

	dfs (0);

	printf("%.12lf\n", (double)ans);
	{ int _; cin >> _; }
}
