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
pii px[maxn], py[maxn], pd[maxn];

inline bool cmpx(const pii &p1, const pii &p2)
	{ return p1.X < p2.X || (p1.X == p2.X && p1.Y < p2.Y); }

inline bool cmpy(const pii &p1, const pii &p2)
	{ return p1.Y < p2.Y || (p1.Y == p2.Y && p1.X < p2.X); }

inline bool cmpd(const pii &p1, const pii &p2)
	{ return p1.X-p1.Y < p2.X-p2.Y || (p1.X-p1.Y == p2.X-p2.Y && p1.X < p2.X); }

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> px[i].X >> px[i].Y;

	copy(px, px+n, py);
	copy(px, px+n, pd);

	sort(px, px+n, cmpx);
	sort(py, py+n, cmpy);
	sort(pd, pd+n, cmpd);

	int ans = 0;

	rep(i, n) {
		int x = px[i].X, y = px[i].Y;
		int ix = i + 1;
		int iy = lower_bound(py, py+n, px[i], cmpy) - py;
		int id = lower_bound(pd, pd+n, px[i], cmpd) - pd;

		while(ix < n && iy < n && id < n) {
			if(px[ix].X != x || py[iy].Y != y || pd[id].X-pd[id].Y != x-y) break;
			cerr << " ## " << ix << ' ' << iy << ' ' << id << endl;
			int minlen = 1e9;
			int maxlen = -1;

			smin(minlen, px[ix].Y - y);
			smin(minlen, py[iy].X - x);
			smin(minlen, pd[id].X - x);
			smax(maxlen, px[ix].Y - y);
			smax(maxlen, py[iy].X - x);
			smax(maxlen, pd[id].X - x);

			if(minlen == maxlen) {
				cout << " !! " << x << ' ' << y << ' ' << minlen << endl;
				ans++, ix++, iy++, id++;
			}
			else {
				if(px[ix].Y - y == minlen) ix++;
				if(py[iy].X - x == minlen) id++;
				if(pd[id].X - x == minlen) id++;
			}
		}
	}

	cout << ans << endl;

	{ return 0; }
}

