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

int n, m, d;
bool f[maxn];
vector<int> adj[maxn];
vector<int> ch[maxn];
int p[maxn];
int ans = 0;

void dfs (int x, int par)
{
	if (f[x]) p[x] = 0;
	for (auto y : adj[x]) if (y != par)
	{
		ch[x].pb (y);
		dfs (y, x);
		p[x] = max (p[x], p[y]+1);
	}
}

void check (int x, int dis)
{
	if (max (p[x], dis) <= d) ans++;

	if (sz(ch[x]) == 0) return;

	vector<int> lf (sz(ch[x]));
	lf[0] = -99999999;
	for (int i = 1; i < sz(ch[x]); i++) lf[i] = max (lf[i-1], p[ch[x][i-1]] + 1);

	int mx = dis;
	if (f[x]) mx = max (mx, 0);

	for (int i = sz(ch[x]); i-- > 0; )
	{
		int y = ch[x][i];
		check (y, max (mx+1, lf[i]+1));
		mx = max (mx, p[y] + 1);
	}
}



int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m >> d;
	rep (i, m) { int x; cin >> x; f[x-1] = 1; }
	rep (i, n-1)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		adj[x].pb (y);
		adj[y].pb (x);
	}

	fill (p, p+maxn, -99999999);

	dfs (0, -1);
	check (0, -99999999);

	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
