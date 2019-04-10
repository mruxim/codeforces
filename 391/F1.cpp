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

const ll inf = 1LL << 62;
const int maxn = 3000 + 100;

int n, k;
ll p[maxn];
ll a[maxn][maxn];
ll b[maxn][maxn];

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n >> k;
	rep (i, n) cin >> p[i];

	rep (i, maxn) rep (j, maxn) a[i][j] = b[i][j] = -inf;
	a[0][0] = 0;

	fer (i, 1, n+1) fer (j, 0, n+1) {
		a[i][j] = a[i-1][j];
		b[i][j] = b[i-1][j];
		
		smax (b[i][j], a[i-1][j] - p[i-1]);
		if (j) smax (a[i][j], b[i-1][j-1] + p[i-1]);
	}
	cout << *max_element (a[n], a[n] + k+1) << endl;

	{ return 0; }
}

