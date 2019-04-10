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
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 200000 + 100;
const int maxlg = 18 + 2;

int n, k;
vector<int> adj[maxn];
int d[maxn], st[maxn], now, p[maxn][maxlg];

void dfs (int x, int par = 0, int dep = 0)
{
	st[x] = now++;
	d[x] = dep;
	p[x][0] = par;
	fer (i, 1, maxlg) p[x][i] = p[p[x][i-1]][i-1];

	for (int y: adj[x]) if (p[y][0] == -1)
		dfs (y, x, dep+1);
}

int dis (int x, int y)
{
	int ret = d[x] + d[y];
	if (d[x] > d[y]) swap (x, y);
	rof (i, maxlg, 0) if (d[p[y][i]] >= d[x]) y = p[y][i];
	if (x == y) return ret - 2*d[x];
	rof (i, maxlg, 0) if (p[x][i] != p[y][i])
		x = p[x][i], y = p[y][i];
	return ret - 2*d[p[x][0]];
}

struct cmp {
	bool operator () (const int &x, const int &y) const
	{ return st[x] < st[y]; }
};

set<int, cmp> s;
int sp;

void add (int x)
{
	s.insert (x);
	auto it = s.find (x);
	auto pr = it, nx = it;
	if (pr == s.begin()) pr = s.end(); pr--;
	nx++; if (nx == s.end()) nx = s.begin();
	sp -= dis (*pr, *nx);
	sp += dis (*pr, *it) + dis (*it, *nx);
}

void rem (int x)
{
	auto it = s.find (x);
	auto pr = it, nx = it;
	if (pr == s.begin()) pr = s.end(); pr--;
	nx++; if (nx == s.end()) nx = s.begin();
	sp += dis (*pr, *nx);
	sp -= dis (*pr, *it) + dis (*it, *nx);
	s.erase (it);
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> k;
	rep (i, n-1)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		adj[x].pb (y);
		adj[y].pb (x);
	}

	memset (p, -1, sizeof p);
	dfs (0);

	int ans = 0;
	int e = 0;
	rep (i, n)
	{
		if (i) rem (i-1);
		while (e <= n && sp/2+1 <= k)
		{
			ans = max (ans, e-i);
			if (e < n) add (e); e++;
		}
	}

	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
