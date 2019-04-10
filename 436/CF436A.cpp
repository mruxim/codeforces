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

int n, x;
vector<pii> v[2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> x;
	rep(i, n) {
		int t, h, m;
		cin >> t >> h >> m;
		v[t].pb({h, m});
	}

	rep(i, 2) sort(all(v[i]));

	int ans = 0;
	int ox = x;

	rep(st, 2) {
		vector<bool> mark[2];
		rep(z, 2) mark[z].resize(sz(v[z])), fill(all(mark[z]), false);
		int tmp = 0;
		x = ox;
		rep(i, n) {
			int c = (st + i) % 2;
			int id = -1;
			rep(j, sz(v[c])) if(v[c][j].X <= x && mark[c][j] == false && (id == -1 || v[c][j].Y > v[c][id].Y))
				id = j;
			if(id == -1) break;
			mark[c][id] = true;
			x += v[c][id].Y;
			tmp++;
		}
		smax(ans, tmp);
	}
	cout << ans << endl;

	{ return 0; }
}

