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
typedef long double ld;
////////////////////////////////////////////////////////////////////////////////

ld mx(ld a, ld b, ld v) {
	ld ans = a * b;
	for(int aa = -1; aa <= 1; aa++)
		for(int bb = -1; bb <= 1; bb++)
			smax(ans, (a + aa*v) * (b + bb*v));
	return ans;
}

ld mn(ld a, ld b, ld v) {
	ld ans = a * b;
	for(int aa = -1; aa <= 1; aa++)
		for(int bb = -1; bb <= 1; bb++)
			smin(ans, (a + aa*v) * (b + bb*v));
	return ans;
}

long double a, b, c, d;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> a >> b >> c >> d;

	if(a * d > b * c) swap(a, b), swap(c, d);

	long double lo = 0, hi = 1e9;
	rep(z, 200) {
		long double md = (lo + hi) / 2;
		long double p = mx(a, d, md);
		long double q = mn(b, c, md);
		if(p >= q) hi = md; else lo = md;
	}

	cout.setf(ios::fixed);
	cout.precision(12);
	cout << lo << endl;

	return 0;
}

