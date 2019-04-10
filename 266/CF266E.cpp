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

const int mod = 1000000007;
const int maxn = 100000 + 1000;

int n, m;
int pw[6][maxn], ml[6][maxn];
int cng[4*maxn];
int sum[6][4*maxn];

void set_val (int x, int l, int r, int v)
{
	cng[x] = v;
	rep (b, 6) sum[b][x] = v * (ll)ml[b][r-l] % mod;
}

void assign (int x, int l, int r, int p, int q, int v)
{
	if (q <= l || r <= p) return;
	if (p <= l && r <= q)
	{
		set_val (x, l, r, v);
		cerr << " !! " << x << ' ' << l << ' ' << r << ' ' << sum[1][x] << " v = " << v << ' ' << ml[1][r-l] << endl;
		return;
	}

	int md = (l + r) / 2;
	if (cng[x] != -1)
	{
		set_val (2*x+1, l, md, cng[x]);
		set_val (2*x+2, md, r, cng[x]);
		cng[x] = -1;
	}

	assign (2*x+1, l, md, p, q, v);
	assign (2*x+2, md, r, p, q, v);

	rep (b, 6) sum[b][x] = (sum[b][2*x+1] + sum[b][2*x+2] * (ll)pw[b][md - l]) % mod;

	cerr << " !! " << x << ' ' << l << ' ' << r << ' ' << sum[1][x] << " v = " << v << endl;
}

int query (int x, int l, int r, int p, int q, int b)
{
	if (q <= l || r <= p) return 0;
	if (p <= l && r <= q)
	{
		cerr << " ## " << x << ' ' << sum[b][x] << ' ' << l-p << endl;
		return sum[b][x] * (ll)pw[b][l-p] % mod;
	}
	int md = (l + r) / 2;
	return (query (2*x+1, l, md, p, q, b) + query (2*x+1, md, r, p, q, b)) % mod;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;

	rep (b, 6)
	{
		pw[b][0] = 1;
		ml[b][0] = 0;
		fer (i, 1, maxn)
			pw[b][i] = pw[b][i-1] * (ll)b % mod,
			ml[b][i] = ml[b][i-1] + pw[b][i-1];
	}

	memset (cng, -1, sizeof cng);

	rep (i, n)
	{
		int x; cin >> x;
		assign (0, 0, n, i, i+1, x);
	}

	rep (i, m)
	{
		char ch;
		int l, r, x;
		cin >> ch >> l >> r >> x;
		l--;
		if (ch == '?') cout << query (0, 0, n, l, r, x) << endl;
		else assign (0, 0, n, l, r, x);
	}

	{ int _; cin >> _; return 0; }
}
