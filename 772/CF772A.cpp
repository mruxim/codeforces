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

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 1000;

int n, p;
int a[maxn], b[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> p;
	rep(i, n) cin >> a[i] >> b[i];

	ll suma = accumulate(a, a + n, 0LL);

	if(suma <= p) {
		cout << -1 << endl;
		return 0;
	}

	double lo = 0, hi = 1e12;
	rep(z, 80) {
		double md = (lo + hi) / 2;

		double req = 0;
		rep(i, n) req += max(0.0, a[i] * md - b[i]);
		if(p * md >= req)
			lo = md;
		else
			hi = md;
	}

	cout.setf(ios::fixed);
	cout.precision(6);
	cout << lo << endl;

	return 0;
}

