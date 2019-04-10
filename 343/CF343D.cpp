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

const int maxn =  500000 + 100;

int n;
vector<int> adj[maxn];
int st[maxn], ed[maxn], now;

void dfs (int v, int par)
{
	st[v] = now++;
	for (auto u: adj[v]) if (u != par)
		dfs (u, v);
	ed[v] = now;
}

int mg[maxn*3];

void change (int x, int l, int r, int L, int R, int val)
{
	if (r <= L || R <= l) return;
	if (L <= l && r <= R)
	{
		mg[x] = val;
		return;
	}

	if (mg[x] != 0) mg[2*x+1] = mg[2*x+2] = mg[x]; mg[x] = 0;

	int md = (l+r)/2;
	change (2*x+1, l, md, L, R, val);
	change (2*x+2, md, r, L, R, val);
}

int getval (int x, int l, int r, int pos)
{
	if (r <= pos || pos < l) return 0;
	if (r - l == 1) return mg[x];

	if (mg[x] != 0) mg[2*x+1] = mg[2*x+2] = mg[x]; mg[x] = 0;

	int md = (l+r)/2;
	return getval (2*x+1, l, md, pos) + getval (2*x+2, md, r, pos);
}

int mx[maxn*3];

void setit (int x, int l, int r, int pos, int val)
{
	if (r <= pos || pos < l) return;

	mx[x] = val;

	if (r-l == 1) return;

	int md = (l+r)/2;
	setit (2*x+1, l, md, pos, val);
	setit (2*x+2, md, r, pos, val);
}

int getmax (int x, int l, int r, int L, int R)
{
	if (r <= L || R <= l) return 0;
	if (L <= l && r <= R) return mx[x];

	int md = (l+r)/2;
	return max (getmax (2*x+1, l, md, L, R), getmax (2*x+2, md, r, L, R));
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n-1)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		adj[x].pb (y);
		adj[y].pb (x);
	}

	dfs (0, -1);

	int q;
	cin >> q;
	fer (z, 1, q+1)
	{
		int type, v;
		cin >> type >> v;
		v--;

		if (type == 1)
			change (0, 0, n, st[v], ed[v], z);
		if (type == 2)
			setit (0, 0, n, st[v], z);
		if (type == 3)
			cout << (getval (0, 0, n, st[v]) <= getmax (0, 0, n, st[v], ed[v]) ? 0 : 1) << endl;
	}

	{ int _; cin >> _; return 0; }
}
