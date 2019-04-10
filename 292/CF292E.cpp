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

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;
const int nll = -346247534;

int n, m;
int a[maxn], b[maxn];
int xx[maxn], yy[maxn], kk[maxn];
int val[4*maxn];

void set_val (int x, int xl, int xr, int ql, int qr, int v)
{
	if (qr <= xl || xr <= ql) return;
	if (ql <= xl && xr <= qr) { val[x] = v; return; }

	int xm = (xl+xr) / 2;
	if (val[x] != nll) val[2*x+1] = val[x], val[2*x+2] = val[x], val[x] = nll;

	set_val (2*x+1, xl, xm, ql, qr, v);
	set_val (2*x+2, xm, xr, ql, qr, v);
}

int get_val (int x, int xl, int xr, int q)
{
	if (q < xl || xr <= q) return 0;
	if (xr-xl == 1) return val[x];

	int xm = (xl+xr) / 2;
	if (val[x] != nll) val[2*x+1] = val[x], val[2*x+2] = val[x], val[x] = nll;

	return get_val (2*x+1, xl, xm, q) + get_val (2*x+2, xm, xr, q);
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, n) cin >> a[i];
	rep (i, n) cin >> b[i];

	fill (val, val+4*maxn, nll);

	set_val (0, 0, n, 0, n, -1);

	fer (i, 1, m+1)
	{
		int qt; cin >> qt;
		if (qt == 1)
		{
			cin >> xx[i] >> yy[i] >> kk[i];
			xx[i]--, yy[i]--;
			set_val (0, 0, n, yy[i], yy[i]+kk[i], i);
		}
		else
		{
			int pos; cin >> pos; pos--;
			int up = get_val (0, 0, n, pos);
			if (up == -1)
				cout << b[pos] << endl;
			else
				cout << a[xx[up] + (pos - yy[up])] << endl;
		}
	}

	{ int _; cin >> _; return 0; }
}

