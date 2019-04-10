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

const ll inf = 1LL << 60;
const int maxn = 200000 + 100;

int n, k;
pii p[maxn];

ll solve (int goal) {
	vector<int> e1, e2;
	rep (i, n)
		if (p[i].X == goal || p[i].X == goal-1) e2.pb (p[i].Y);
		else e1.pb (p[i].Y);
	int better = 0; rep (i, n) if (p[i].X > goal) better++;

	sort (all(e1));
	sort (all(e2));

	int t1 = 0, t2 = 0;
	ll ret = 0;
	
	for (; t2 < sz(e2) - (k - better); t2++) ret += e2[t2];

	while (t1 + t2 < goal) {
		if (t1 == sz(e1) && t2 == sz(e2)) return inf;
		if (t1 == sz(e1)) ret += e2[t2++];
		else if (t2 == sz(e2)) ret += e1[t1++];
		else if (e1[t1] < e2[t2]) ret += e1[t1++];
		else ret += e2[t2++];
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n >> k; k--;
	rep (i, n) cin >> p[i].X >> p[i].Y;

	if (k == n) { cout << 0 << endl; return 0; }

	sort (p, p+n, [](pii p1, pii p2){ return pii(-p1.X, p1.Y) < pii(-p2.X, p2.Y); });

	int goal = p[k].X;

	ll ans = min (solve (goal), min (solve (goal+1), solve (goal+2)));

	if (ans == inf) cout << -1 << endl;
	else cout << ans << endl;

	{ return 0; }
}

