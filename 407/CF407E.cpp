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

const int maxn = 200000 + 100;
const int lg = 18 + 1;
typedef int OP(int, int);

int n, k, d;
vector<int> a, dif, nxt;
map<int, int> last;
int rmn[lg][maxn], rmx[lg][maxn], rgc[lg][maxn], rnx[lg][maxn];
int b2[maxn];

int mymin(int x, int y) { return min(x, y); }
int mymax(int x, int y) { return max(x, y); }
int mygcd(int x, int y) { return __gcd(x, y); }

void func(vector<int> v, int r[lg][maxn], OP op) {
	rep(l, lg) rep(i, sz(v)) {
		if(l == 0) r[l][i] = v[i];
		else {
			r[l][i] = r[l-1][i];
			int j = i + (1 << l) / 2;
			if(j < sz(v)) r[l][i] = op(r[l][i], r[l-1][j]);
		}
	}
}

int get(int r[lg][maxn], OP op, int p, int q) {
	int l = b2[q - p];
	return op(r[l][p], r[l][q - (1 << l)]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	b2[1] = 0;
	fer(i, 2, maxn) b2[i] = b2[i/2] + 1;

	cin >> n >> k >> d;

	a.resize(n);
	rep(i, n) cin >> a[i];

	dif.resize(n-1);
	rep(i, n-1) dif[i] = a[i+1] - a[i];

	nxt.resize(n);
	rof(i, n, 0) {
		if(last.find(a[i]) != last.end()) nxt[i] = last[a[i]];
		else nxt[i] = n;
		last[a[i]] = i;
	}

	func(a, rmn, mymin);
	func(a, rmx, mymax);
	func(dif, rgc, mygcd);
	func(nxt, rnx, mymin);

	int ansl = 0, ansr = 0;

	rep(i, n) {
		int j = i+1;
		rof(l, lg, 0) {
			j += 1 << l;
			int mn = get(rmn, mymin, i, j);
			int mx = get(rmx, mymax, i, j);
			int gc = get(rgc, mygcd, i, j-1);
			int nx = get(rnx, mymin, i, j);
			if(!(nx >= j && gc % d == 0 && (mx - mn) / d - (j - i - 1) <= k))
				j -= 1 << l;
		}
		if(j - i > ansr - ansl)
			ansl = i, ansr = j;
	}

	cout << ansl + 1 << ' ' << ansr << endl;

	{ return 0; }
}

