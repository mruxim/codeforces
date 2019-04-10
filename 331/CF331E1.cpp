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
#define rall(X) (X).rbegin(),(X).rend()

#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 50 + 5;

int n, m;
bool g1[maxn][maxn], g2[maxn][maxn];
vector<int> v1[maxn][maxn], v2[maxn][maxn];

bool go (int x, vector<int> &cur, bool g[maxn][maxn], vector<int> v[maxn][maxn])
{
	int pos = 0;
	while (pos < sz(cur) && sz(cur) < 2*n)
	{
		int y = cur[pos++];
		if (!g[x][y]) return false;
		copy (all (v[x][y]), back_inserter (cur));
		x = y;
	}
	return pos == sz(cur);
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, m)
	{
		int x, y, k;
		cin >> x >> y >> k; x--, y--;
		g1[x][y] = g2[y][x] = true;
		while (k--) v1[x][y].pb(0), cin >> v1[x][y].back(), v1[x][y].back()--;
		v2[y][x] = v1[x][y]; reverse (all (v2[y][x]));
	}

	rep (i, n) rep (j, n) if (g1[i][j])
	{
		rep (k, sz(v1[i][j])-1) if (v1[i][j][k] == i && v1[i][j][k+1] == j)
		{
			vector<int> prv, nxt;
			rof (p, k, 0) prv.pb (v1[i][j][p]);
			fer (p, k+2, sz(v1[i][j])) nxt.pb (v1[i][j][p]);
			bool ok1 = go (j, nxt, g1, v1);
			bool ok2 = go (i, prv, g2, v2);
			if (!ok1 || !ok2 || sz(prv) + 2 + sz(nxt) > 2*n) continue;

			cout << sz(prv) + 2 + sz(nxt) << endl;
			rof (p, sz(prv), 0) cout << 1+prv[p] << ' ';
			cout << 1+i << ' ' << 1+j;
			rep (p, sz(nxt)) cout << ' ' << 1+nxt[p];
			cout << endl;
			{ int _; cin >> _; return 0; }
		}
	}
	cout << 0 << endl;	

	{ int _; cin >> _; return 0; }
}
