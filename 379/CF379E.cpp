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
typedef pair <double, double> point;

////////////////////////////////////////////////////////////////////////////////

const double eps = 1e-9;
const int maxn = 300 + 10;

int n, k;
int ys[maxn][maxn];
int perm[maxn];

inline point operator + (point p, point q) { return point (p.X + q.X, p.Y + q.Y); }
inline point operator - (point p, point q) { return point (p.X - q.X, p.Y - q.Y); }
inline point operator * (point p, double m) { return point (p.X * m, p.Y * m); }
inline point operator * (double m, point p) { return point (p.X * m, p.Y * m); }
inline point operator += (point &p, point q) { return p = p + q; }
inline point operator -= (point &p, point q) { return p = p - q; }
inline point operator *= (point &p, double m) { return p = p * m; }
inline double cross (point p, point q) { return p.X * q.Y - p.Y * q.X; } // O -> p -> q
inline double cross (point p, point q1, point q2) { return (q1.X-p.X) * (q2.Y-p.Y) - (q1.Y-p.Y) * (q2.X-p.X); }
point intersection (point a, point b, point c, point d) { return c + cross (c - a, b - a) / cross (b - a, d - c) * (d - c); }

double calc (int xx, int t)
{
	int max_slope = -999999;
	static point st[maxn];
	int len = 0;
	rep (pi, n) if (perm[pi] < t)
	{
		int i = perm[pi];
		int y0 = ys[i][xx], y1 = ys[i][xx+1];
		int slope = y1-y0;
		if (slope <= max_slope) continue;
		max_slope = slope;
		point p0 = point (0, y0), p1 = point (1, y1);
		if (len == 0)
		{
			st[len++] = p0, st[len++] = p1;
			continue;
		}
		if (p1.Y <= st[len-1].Y+eps) continue;
		
		while (1)
		{
			if (len < 2) cerr << " ERROR" << endl;
			point in = intersection (st[len-2], st[len-1], p0, p1);
			if (in.X <= st[len-2].X)
				len--;
			else
			{
				len--;
				st[len++] = in;
				st[len++] = p1;
				break;
			}
		}
	}
	double area = 0;
	rep (i, len-1)
		area += (st[i+1].X - st[i].X) * (st[i].Y + st[i+1].Y);
	return area / 2;
}

double ans[maxn];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> k;
	rep (i, n) rep (j, k+1)
		cin >> ys[i][j];

	rep (xx, k)
	{
		rep (j, n) perm[j] = j;
		sort (perm, perm+n, [xx](int i, int j){ return (ys[i][xx] != ys[j][xx] ? ys[i][xx] > ys[j][xx] : ys[i][xx+1] > ys[j][xx+1]); } );
		double prev = 0;
		fer (i, 1, n+1)
		{
			double tmp = calc (xx, i);
//			cerr << xx << ' ' << i << ' ' << tmp << endl;
			ans[i-1] += tmp - prev;
			prev = tmp;
		}
	}

	cout << fixed << setprecision (7);
	rep (i, n) cout << ans[i] << endl;

	{ int _; cin >> _; return 0; }
}
