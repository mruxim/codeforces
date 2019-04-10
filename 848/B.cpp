// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?
// ....... .. .... .. ...., ....... ..!

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
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n, w, h;
map<int, vector<pair<pii, int>>> m;
pii ans[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> w >> h;
	rep(i, n) {
		int g, p, t;
		cin >> g >> p >> t;
		int x, y;
		if(g == 1)
			x = p, y = -t;
		else
			x = -t, y = p;
		m[x + y].pb(make_pair(pii(x, y), i));
	}

	for(auto it: m) {
		vector<pii> v;
		for(auto p: it.second) v.pb(p.X.X <= 0 ? pii(w, p.X.Y) : pii(p.X.X, h));
		sort(all(v), [](pii a, pii b) { return a.X != b.X ? a.X < b.X : a.Y > b.Y; } );
		sort(all(it.second), [](pair<pii, int> a, pair<pii, int> b) { return a.X.X - a.X.Y < b.X.X - b.X.Y; } );

		rep(i, sz(v)) ans[it.second[i].Y] = v[i];
	}

	rep(i, n) cout << ans[i].X << ' ' << ans[i].Y << endl;

	return 0;
}

