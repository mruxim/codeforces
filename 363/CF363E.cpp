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

const int maxn = 500 + 50;

int n, m, r;
int a[maxn][maxn];
int v[maxn][maxn];
int d[maxn];
int f[maxn];

bool ok (int x, int y)
{
	if (x*x+y*y > 4*r*r) return true;
	int p = r, q = 3000;
	rep (i, x+1)
	{
		while (p > -1000 && i*i + p*p > r*r) p--;
		if (x-i <= r)
		{
			q = min (q, y);
			while ((y-q)*(y-q) + (x-i)*(x-i) <= r*r) q--;
			q++;
		}
		if (p >= q) return false;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m >> r;
	rep (i, n) rep (j, m) cin >> a[i][j];

	int dis = 2*r+1;
	rep (i, n)
	{
		while (dis && ok(i, dis-1)) dis--;
		d[i] = dis;
	}

	rep (i, r+1)
	{
		f[i] = 0;
		while (f[i]*f[i] + i*i <= r*r) f[i]++;
		f[i]--;
	}

	memset (v, -50, sizeof v);

	fer (i, r, n-r)
	{
		fer (j, r, m-r)
		{
			v[i][j] = 0;
			if (j == r)
			{
				fer (di, -r, r+1) fer (dj, -r, r+1) if (di*di + dj*dj <= r*r)
					v[i][j] += a[i+di][j+dj];
			}
			else
			{
				v[i][j] = v[i][j-1];
				fer (di, -r, r+1)
					v[i][j] -= a[i+di][j-1-f[abs(di)]],
					v[i][j] += a[i+di][j+f[abs(di)]];
			}
		}
	}

	int ans = 0;
	ll cnt = 0;

	fer (i, r, n-r)
	{
		int mx = -999999999;
		ll ct = 0;
		rof (j, m-r, r)
		{
			fer (k, r, n-r)
			{
				int pos = d[abs(k-i)];
				if (pos == 0 && k > i) pos++;
				if (pos+j < m-r)
				{
					if (v[k][pos+j] == mx) ct++;
					else if (v[k][pos+j] > mx)
						mx = v[k][pos+j], ct = 1;
				}
			}
			if (v[i][j] + mx > ans) ans = v[i][j] + mx, cnt = ct;
			else if (v[i][j] + mx == ans) cnt += ct;
		}
	}

	cout << ans << ' ' << cnt << endl;

	{ int _; cin >> _; return 0; }
}
