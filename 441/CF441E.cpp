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

double p;
double m[222][222][256];

double go(int k, int f, int x) {
	if(m[k][f][x] == m[k][f][x]) return m[k][f][x];
	double &ret = m[k][f][x];
	if(k == 0) {
		if(x == 0) return ret = f;
		return ret = __builtin_ctz(x);
	}

	if(x == 0) ret = p * go(k-1, f+1, x) + (1-p) * go(k-1, 8, x+1);
	else ret = p * go(k-1, x<=128 ? 8 : f+1, (x<<1) & 255) +
				(1-p) * go(k-1, f, (x+1) & 255);

	return ret;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	memset(m, -1, sizeof m);

	int x, k, pp;
	cin >> x >> k >> pp;
	p = pp / 100.0;

	cout.setf(ios::fixed);
	cout.precision(9);
	int y = x ^ (x & 255);
	cout << go(k, x == y ? __builtin_ctz(x) : __builtin_ctz(y+256), x & 255) << endl;

	{ return 0; }
}

