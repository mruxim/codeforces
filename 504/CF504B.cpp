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

////////////////////////////////////////////////////////////////////////////////

const int maxn = 200000 + 100;

int n;
int a[maxn], b[maxn], c[maxn];
int f[maxn];

inline void add(int x, int v) {
	for(x++; x < maxn; x += x & -x) f[x] += v;
}

inline int get(int x) {
	int r = 0;
	for(; x; x -= x & -x) r += f[x];
	return r;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> c[i];
	rof(i, n, 0) a[i] = get(c[i]), add(c[i], 1);
	memset(f, 0, sizeof f);
	rep(i, n) cin >> c[i];
	rof(i, n, 0) b[i] = get(c[i]), add(c[i], 1);
	memset(f, 0, sizeof f);

	int cr = 0;
	rof(i, n, 0) {
		c[i] = a[i] + b[i] + cr;
		cr = c[i] / (n - i);
		c[i] %= n - i;
	}

	rep(i, n) add(i, 1);
	rep(i, n) {
		int lo = 0, hi = n;
		while(hi - lo > 1) {
			int md = (lo + hi) / 2;
			if(get(md) > c[i])
				hi = md;
			else
				lo = md;
		}
		a[i] = lo;
		add(a[i], -1);
	}

	rep(i, n) cout << a[i] << ' '; cout << endl;

	return 0;
}

