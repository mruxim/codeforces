// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

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

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 3000 + 100;

int n;
int a[maxn], b[maxn], c[maxn];
int p[maxn], rp[maxn];
pdd f[maxn];

pdd is(int i, int j) {
	if(a[i]) {
		double y = (c[j] - a[j] / (double)a[i] * c[i]) / (b[j] - a[j] / (double)a[i] * b[i]);
		double x = (c[i] - b[i] * y) / a[i];
		return {x, y};
	} else {
		double x = (c[j] - b[j] / (double)b[i] * c[i]) / (a[j] - b[j] / (double)b[i] * a[i]);
		double y = (c[i] - a[i] * x) / b[i];
		return {x, y};
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> a[i] >> b[i] >> c[i];

	iota(p, p+n, 0);
	sort(p, p+n, [](int i, int j) { return b[i]==0 ? 1 : b[j]==0 ? 0 : -a[i]/(double)b[i] < -a[j]/(double)b[j]; } );
//	sort(p, p+n, [](int i, int j) { return b[i]==0 ? 1 : b[j]==0 ? 0 : -a[i]*b[j] < -a[j]*b[i]; } );

	double ans = 0;
	rep(i, n) {
		fer(jj, 1, n) {
			int j = (jj + i) % n;
			f[jj-1] = is(p[i], p[j]);
		}

		double sumx = 0, sumy = 0;
		int sumc = 0;
		rep(j, n-1) {
			ans += (n-2-2*sumc) * f[j].X * f[j].Y;
			ans -= f[j].X * sumy;
			ans += f[j].Y * sumx;

			sumc++;
			sumx += f[j].X;
			sumy += f[j].Y;
		}
	}
	ans /= 2;
	ans /= n * (ll)(n-1) * (n-2) / 6;

	cout.setf(ios::fixed);
	cout.precision(8);
	cout << ans << endl;

	return 0;
}

