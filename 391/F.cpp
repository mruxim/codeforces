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

////////////////////////////////////////////////////////////////////////////////

#define double long double

const double eps = 1e-7;
const int maxn = 100000 + 100;

int n, k;
double p[maxn];

pair<double, int> solve (double add) {
	static pair<double, int> a[maxn], b[maxn];

	b[0] = {-1e30, 0};
	a[0] = {0, 0};

	fer (i, 1, n+1) {
		a[i] = a[i-1], b[i] = b[i-1];
		if (b[i-1].X + p[i-1] > a[i].X + eps)
			a[i] = {b[i-1].X + p[i-1], b[i-1].Y};
		else if (b[i-1].X + p[i-1] > a[i].X - eps)
			smin (a[i].Y, b[i-1].Y);
	
		if (a[i-1].X - p[i-1] + add > b[i].X + eps)
			b[i] = {a[i-1].X - p[i-1] + add, a[i-1].Y + 1};
		else if (a[i-1].X - p[i-1] + add > b[i].X - eps)
			smin (b[i].Y, a[i-1].Y + 1);
	}

	return a[n];
}

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n >> k;
	rep (i, n) cin >> p[i];

	double lo = -1e20, hi = 1e20;

	ll ans = 0;
	rep (i, 200) {
		double md1 = (2*lo + hi) / 3;
		double md2 = (lo + 2*hi) / 3;
		auto tmp1 = solve (md1);
		auto tmp2 = solve (md2);

		cerr.setf (ios::fixed);
	//	cerr << md << ' ' << tmp.second << ' ' << (tmp.first - md * tmp.second + 0.5) << endl;
		if (tmp.second > k) hi = md;
		else {
			smax (ans, (ll)(tmp.first - md * tmp.second + 0.5));
			lo = md;
		}
	}

	cout << ans << endl;

	{ return 0; }
}

