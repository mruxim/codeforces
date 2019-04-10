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
#define mp make_pair
#define all(X) (X).begin(),(X).end()

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 80 + 10;

int n;
pii r[maxn];
long double dp[maxn][maxn];
long double ans[maxn];

long double prob (pii a, pii b) // grnt : b.X <= a.X < a.Y <= b.Y
{
//	if (a.Y <= b.X) return 1.0;
//	if (b.Y <= a.X) return 0.0;

	return ((b.Y - a.Y) + (a.Y - a.X) / 2.0) / (long double)(b.Y - b.X);
/*
	double ret = 0;
	double prob = 1;
	double al, bl;

	int t;

	al = a.Y - a.X, bl = b.Y - b.X;
	t = max (b.X - a.X, 0); ret += t / al * prob, prob *= 1 - t / al; a.X += t;
	al = a.Y - a.X, bl = b.Y - b.X;
	t = max (b.Y - a.Y, 0); ret += t / bl * prob, prob *= 1 - t / bl; b.Y -= t;

	al = a.Y - a.X, bl = b.Y - b.X;
	t = max (a.X - b.X, 0); prob *= 1 - t / bl; b.X += t;
	al = a.Y - a.X, bl = b.Y - b.X;
	t = max (a.Y - b.Y, 0); prob *= 1 - t / al; a.Y -= t;

	ret += prob / 2;

	return ret;*/
}

vector <int> q;

int main()
{
	ios::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> r[i].X >> r[i].Y, q.pb (r[i].X), q.pb (r[i].Y);

	sort (all(q));
	q.resize (unique (all(q)) - q.begin());

	rep (z, n)
	{
		vector <pii> v;
		rep (i, n) if (z != i) v.pb (r[i]);

		rep (i, n) ans[i] = 0.0;		

		rep (zz, sz(q)-1) if (r[z].X <= q[zz] && q[zz+1] <= r[z].Y)
		{
			pii p = mp (q[zz], q[zz+1]);

			rep (i, n) rep (j, n) dp[i][j] = 0;

			dp[0][0] = p.Y - p.X;
			fer (i, 1, n) rep (j, i+1)
			{
				long double t = prob (p, v[i-1]);
				dp[i][j] = dp[i-1][j] * t + (j ? dp[i-1][j-1] * (1.0 - t) : 0.0);
			}

			rep (i, n) ans[i] += dp[n-1][i];
		}

		rep (i, n) cout << fixed << setprecision (6) << ans[i] / (r[z].Y - r[z].X) << ' ';
		cout << endl;
	}

	{ int _; cin >> _; return 0; }
}
