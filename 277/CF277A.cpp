// .... .... .... !

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

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define X first
#define Y second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

int n, m;
bool g[111][111], h[111][111];
bool mark[111];

void dfs (int x)
{
	if (mark[x]) return;
	mark[x] = 1;
	rep (i, n) if (g[x][i]) dfs (i);
}

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m;
	int s = 0;
	rep (i, n)
	{
		int k;
		cin >> k;
		s += k;
		int x;
		while (k--)
			cin >> x, x--, h[i][x] = 1;
	}
	rep (i, m)
		rep (j, n) rep (k, n)
			if (h[j][i] && h[k][i])
				g[k][j] = g[j][k] = 1;
	int comp = 0;
	rep (i, n)
		if (!mark[i])
			dfs (i), comp++;

	if (s == 0)
		cout << n << endl;
	else
	cout << comp-1 << endl;

	{ int _; cin >> _; return 0; }
}
