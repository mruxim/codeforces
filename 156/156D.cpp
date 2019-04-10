// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fer(i, x, n) for (int i = (x), _n = (n); i < _n; i++)
#define rof(i, n, x) for (int i = (n), _x = (x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
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

const int MAXn = 100000 + 999;

int n, m;
ll k;
vi adj[MAXn];
bool mark[MAXn];
vi comp;
ll ans = 1;

int dfs (int x)
{
	if (mark[x]) return 0;
	mark[x] = true;
	int ret = 1;
	fch (it, adj[x])
		ret += dfs (*it);
	return ret;
}

int main()
{
	cin >> n >> m >> k;
	while (m--)
	{
		int x, y;
		cin >> x >> y; x--, y--;
		adj[x].pb (y), adj[y].pb (x);
	}
	rep (i, n) if (!mark[i])
		comp.pb(dfs (i));

	rep (i, sz(comp)-2)
		ans = ans * n % k;
	rep (i, sz(comp))
		ans = ans * comp[i] % k;
	if (sz (comp) == 1)
		ans = 1;
	cout << ans % k << endl;
	{ int _; cin >> _; }
}
