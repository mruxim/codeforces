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

const int maxn = 3000 + 100;

int n, v;
int d[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> v;
	rep(i, n) {
		int a, b; cin >> a >> b;
		d[a] += b;
	}

	int ans = 0;
	fer(i, 1, maxn) {
		int t = v;
		int r = min(d[i-1], t);
		ans += r; t -= r;
		r = min(d[i], t);
		ans += r, d[i] -= r;
	}

	cout << ans << endl;

	{ return 0; }
}

