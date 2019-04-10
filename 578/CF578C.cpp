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
#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 200000 + 100;

int n;
int a[maxn], s[maxn];

double f(double x) {
	double mn = 0, mx = 0;
	rep(i, n+1)
		smin(mn, s[i] - i * x),
		smax(mx, s[i] - i * x);
	return mx - mn;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> a[i];

	rep(i, n) s[i+1] = s[i] + a[i];

	double lo = -1e5, hi = 1e5;
	rep(z, 100) {
		double m1 = (2 * lo + hi) / 3;
		double m2 = (lo + 2 * hi) / 3;
		if(f(m1) < f(m2))
			hi = m2;
		else
			lo = m1;
	}

	cout.setf(ios::fixed);
	cout.precision(9);
	cout << f(lo) << endl;


	return 0;
}

