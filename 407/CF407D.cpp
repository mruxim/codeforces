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

const int maxn = 400 + 10;
cosnt int maxv = maxn * maxn;

int n, m;
int a[maxn][maxn];
int store[maxn*maxn], t;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> a[i][j], store[t++] = a[i][j];

	sort(store, store+t);
	t = unique(store, store+t) - store;
	rep(i, n) rep(j, m) a[i][j] = lower_bound(store, store+t, a[i][j]);

	int ans = 0;

	rep(i, n) {
		memset(f, 50, sizeof f);
		fer(j, i, n) {
			
		}
	}

	cout << ans << endl;

	{ return 0; }
}

