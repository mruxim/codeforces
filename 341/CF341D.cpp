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

const int maxn = 1 << 11;

int n, m;
ll Xor[maxn][maxn];
ll flg[maxn][maxn];

inline void doit (int x, int y, int &xl, int &xr, int &yl, int &yr, ll &v)
{
	Xor[x][y] ^= ((xr-xl)*(yr-yl) % 2) * v;
	flg[x][y] ^= v;
}

void change (int x, int y, int xl, int xr, int yl, int yr, int &p, int &q, int &pp, int &qq, ll &v)
{
	if (p <= xl && xr <= pp && q <= yl && yr <= qq)
	{
		doit (x, y, xl, xr, yl, yr, v);
		return;
	}

	if (xr <= p || yr <= q || pp <= xl || qq <= yl) return;

	int xm = (xl+xr) / 2;
	int ym = (yl+yr) / 2;

	doit (2*x+1, 2*y+1, xl, xm, yl, ym, flg[x][y]);
	doit (2*x+2, 2*y+1, xm, xr, yl, ym, flg[x][y]);
	doit (2*x+2, 2*y+2, xm, xr, ym, yr, flg[x][y]);
	doit (2*x+1, 2*y+2, xl, xm, ym, yr, flg[x][y]);
	flg[x][y] = 0;

	change (2*x+1, 2*y+1, xl, xm, yl, ym, p, q, pp, qq, v);
	change (2*x+2, 2*y+1, xm, xr, yl, ym, p, q, pp, qq, v);
	change (2*x+2, 2*y+2, xm, xr, ym, yr, p, q, pp, qq, v);
	change (2*x+1, 2*y+2, xl, xm, ym, yr, p, q, pp, qq, v);

	Xor[x][y] = Xor[2*x+1][2*y+1] ^ Xor[2*x+1][2*y+2] ^ Xor[2*x+2][2*y+1] ^ Xor[2*x+2][2*y+2];
}

ll query (int x, int y, int xl, int xr, int yl, int yr, int &p, int &q, int &pp, int &qq)
{
	if (p <= xl && xr <= pp && q <= yl && yr <= qq)
		return Xor[x][y];

	if (xr <= p || yr <= q || pp <= xl || qq <= yl) return 0;

	int xm = (xl+xr) / 2;
	int ym = (yl+yr) / 2;

	doit (2*x+1, 2*y+1, xl, xm, yl, ym, flg[x][y]);
	doit (2*x+2, 2*y+1, xm, xr, yl, ym, flg[x][y]);
	doit (2*x+2, 2*y+2, xm, xr, ym, yr, flg[x][y]);
	doit (2*x+1, 2*y+2, xl, xm, ym, yr, flg[x][y]);
	flg[x][y] = 0;
	Xor[x][y] = Xor[2*x+1][2*y+1] ^ Xor[2*x+1][2*y+2] ^ Xor[2*x+2][2*y+1] ^ Xor[2*x+2][2*y+2];

	ll ans = 0;

	ans ^= query (2*x+1, 2*y+1, xl, xm, yl, ym, p, q, pp, qq);
	ans ^= query (2*x+2, 2*y+1, xm, xr, yl, ym, p, q, pp, qq);
	ans ^= query (2*x+2, 2*y+2, xm, xr, ym, yr, p, q, pp, qq);
	ans ^= query (2*x+1, 2*y+2, xl, xm, ym, yr, p, q, pp, qq);

	return ans;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	while (m--)
	{
		int qt, x1, y1, x2, y2;
		ll v;
		cin >> qt >> x1 >> y1 >> x2 >> y2;
		x1--, y1--;
		if (qt == 2)
		{
			cin >> v;
			change (0, 0, 0, n, 0, n, x1, y1, x2, y2, v);
		}
		else
			cout << query (0, 0, 0, n, 0, n, x1, y1, x2, y2) << endl;
	}

	{ int _; cin >> _; return 0; }
}
