// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n, m;
pdd g[maxn], p[maxn];
pdd q;

inline double dist2(pdd p1, pdd p2) {
	return (p1.X-p2.X) * (p1.X-p2.X) + (p1.Y-p2.Y) * (p1.Y-p2.Y);
}

inline double cross(pdd p0, pdd p1, pdd p2) {
	return (p1.X-p0.X) * (p2.Y-p0.Y) - (p1.Y-p0.Y) * (p2.X-p0.X);
}

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep(i, n) cin >> g[i].X >> g[i].Y, q.X += g[i].X, q.Y += g[i].Y;
	q.X /= n, q.Y /= n;

	cin >> m;
	rep(i, m) cin >> p[i].X >> p[i].Y;
	p[m] = p[0];

	double add = 1e10;

	rep(i, m) {
		smin(add, dist2(q, p[i]));
		double A = dist2(q, p[i]), B = dist2(q, p[i+1]);
		if(dist2(p[i], p[i+1]) + min(A, B) > max(A, B))
			smin(add, abs(cross(p[i+1], p[i], q) / dist2(p[i], p[i+1])));
	}

	bool in = true;
	rep(i, m) if(cross(q, p[i], p[i+1]) > 0) in = false;
	if (in) add = 0;

	add *= add * n;
	rep(i, n) add += dist2(q, g[i]);

	cout.setf(ios::fixed);
	cout.precision(8);
	cout << add << endl;

	{ return 0; }
}

