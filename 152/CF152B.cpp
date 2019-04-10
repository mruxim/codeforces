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

int n, m;
int x, y;
int k;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	cin >> x >> y;
	cin >> k;

	ll ans = 0;

	rep(i, k) {
		int dx, dy;
		cin >> dx >> dy;

		int moves = 1e9 + 10;
		if(dx > 0) smin(moves, (n - x) / dx);
		if(dy > 0) smin(moves, (m - y) / dy);
		if(dx < 0) smin(moves, (x - 1) / -dx);
		if(dy < 0) smin(moves, (y - 1) / -dy);
		ans += moves;
		x += moves * dx;
		y += moves * dy;
	}

	cout << ans << endl;

	{ return 0; }
}

