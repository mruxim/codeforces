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

const int maxn = 100000 + 100;

int n;
int a[maxn], b[maxn], c[maxn];
int val[3*maxn], len;
int px[3*maxn], py[3*maxn], pz[3*maxn];

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep(i, n) cin >> a[i], val[len++] = a[i];
	rep(i, n) cin >> b[i], val[len++] = b[i];
	rep(i, n) cin >> c[i], val[len++] = c[i];
	sort(val, val+len); len = unique(val, val+len) - val;

	rep (i, len) px[i] = py[i] = pz[i] = 3*maxn+1;
	rof (i, n, 0) px[lower_bound(val, val+len, a[i]) - val] = i;
	rof (i, n, 0) py[lower_bound(val, val+len, b[i]) - val] = i;
	rof (i, n, 0) pz[lower_bound(val, val+len, c[i]) - val] = i;

	

	{ return 0; }
}

