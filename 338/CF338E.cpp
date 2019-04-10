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

const int maxn = 150 * 1000 + 100;

int n, m, h;
int b[maxn], a[maxn];
int min_val[4*maxn], to_add[4*maxn];

void add(int x, int xl, int xr, int ql, int qr, int qv)
{
	if (qr <= xl || xr <= ql) return;
	if (ql <= xl && xr <= qr) {
		min_val[x] += qv;
		to_add[x] += qv;
		return;
	}

	int xm = (xl+xr) / 2;

	min_val[2*x+1] += to_add[x];
	to_add[2*x+1] += to_add[x];
	min_val[2*x+2] += to_add[x];
	to_add[2*x+2] += to_add[x];

	to_add[x] = 0;

	add (2*x+1, xl, xm, ql, qr, qv);
	add (2*x+2, xm, xr, ql, qr, qv);

	min_val[x] = min(min_val[2*x+1], min_val[2*x+2]);
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> m >> n >> h;

	rep (i, n) cin >> b[i], b[i] = h - b[i];
	sort (b, b+n);
	
	rep (i, m) cin >> a[i], a[i] = upper_bound (b, b+n, a[i]) - b;

	rep (i, n) add (0, 0, n, 0, i+1, -1);

	int ans = 0;
	rep (i, m)
	{
		add (0, 0, n, 0, a[i], 1);
		if (i >= n) add (0, 0, n, 0, a[i-n], -1);
		if (min_val[0] >= 0) ans++;
	}

	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
