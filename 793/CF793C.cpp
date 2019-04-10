// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

#define y0 y000
#define y1 y111

////////////////////////////////////////////////////////////////////////////////

const double eps = 1e-9;

const int maxn = 100000 + 100;

int n;
int x0, y0, x1, y1;
int rx[maxn], ry[maxn], vx[maxn], vy[maxn];

double dis(double x, double y) {
	if(x0 + eps <= x && x + eps <= x1 && y0 + eps <= y && y + eps <= y1) return 0;
	double xdis = min(abs(x0 - x), abs(x1 - x));
	double ydis = min(abs(y0 - y), abs(y1 - y));
	return max(xdis, ydis);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	cin >> x0 >> y0 >> x1 >> y1;
	rep(i, n) cin >> rx[i] >> ry[i] >> vx[i] >> vy[i];

	double mn = -1e10, mx = 1e10;

	rep(i, n) {
		double lo = 0, hi = 1e7;
		double ds = 1e10;
		rep(z, 70) {
			double md1 = (lo + lo + hi) / 3;
			double px1 = rx[i] + vx[i] * md1;
			double py1 = ry[i] + vy[i] * md1;
			double md2 = (lo + hi + hi) / 3;
			double px2 = rx[i] + vx[i] * md2;
			double py2 = ry[i] + vy[i] * md2;
			double d1 = dis(px1, py1);
			double d2 = dis(px2, py2);
			if(d1 - eps < d2) hi = md2;
			else lo = md1;
			smin(ds, d1);
		}
		if(ds > eps) { cout << -1 << endl; return 0; }
		smax(mn, lo);
		lo = 0, hi = 1e7;
		rep(z, 70) {
			double md1 = (lo + lo + hi) / 3;
			double px1 = rx[i] + vx[i] * md1;
			double py1 = ry[i] + vy[i] * md1;
			double md2 = (lo + hi + hi) / 3;
			double px2 = rx[i] + vx[i] * md2;
			double py2 = ry[i] + vy[i] * md2;
			double d1 = dis(px1, py1);
			double d2 = dis(px2, py2);
			if(d1 + eps < d2) hi = md2;
			else lo = md1;
		}
		smin(mx, hi);
	}

	cout.setf(ios::fixed);
	cout.precision(8);
	if(mn < mx) cout << mn << endl;
	else cout << -1 << endl;

	return 0;
}

