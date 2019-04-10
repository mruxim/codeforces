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

const short maxn = 5000 + 5;
const int mod = 1000000000 + 7;

int n;
short x[maxn], y[maxn];
short d[maxn][maxn];
short md;
char col[maxn];

void dfs (int x)
{
	rep (i, n) if (d[x][i] > md)
	{
		if (col[x] == col[i]) throw 0;
		if (col[i]) continue;
		col[i] = 3 - col[x];
		dfs (i);
	}
}

int cnt ()
{
	memset (col, 0, sizeof col);
	int r = 1;
	rep (i, n) if (col[i] == 0)
	{
		col[i] = 1;
		try { dfs (i); } catch (...) { return 0; }
		(r += r) >= mod ? r -= mod : 0;
	}
	return r;
}

int main()
{
	ios::sync_with_stdio (false);
	cin >> n;
	rep (i, n) cin >> x[i] >> y[i];
	rep (i, n) fer (j, i+1, n) d[i][j] = d[j][i] = abs (x[i]-x[j]) + abs (y[i]-y[j]);
	short lo = -1, hi = 10000;
	while (lo+1 < hi)
	{
		md = (lo + hi) / 2;
		if (cnt() != 0)	hi = md;
		else		lo = md;
	}
	md = hi;
	cout << hi << endl << cnt () << endl;
	{ int _; cin >> _; }
}
