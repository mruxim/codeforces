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

int len, n;

inline ll c2(int k) { return 1LL * k * (k-1) / 2; }
inline ll c3(int k) { return 1LL * k * (k-1) / 2 * (k-2) / 3; }

int maxdiff = -1;
ll ans = 0;

void update(ll cnt, int diff) {
	if(diff < maxdiff) return;
	if(diff > maxdiff) maxdiff = diff, ans = 0;
	ans += cnt;
}

void solve(vector<pii> a, vector<pii> b) {
	int pos = 0;
	int L = 0, R = 0;
	for(pii cur: b) R += cur.Y;

	for(pii cur: a) {
		while(pos < sz(b) && b[pos].X < cur.X) L += b[pos].Y, R -= b[pos].Y, pos++;

		if(pos < sz(b) && pos > 0) {
			update(cur.Y * (ll)L * (ll)R, len);
			if(b[pos].X == cur.X) update(cur.Y * (ll)(c2(R) - c2(R - b[pos].Y)), len);
		} else if(pos > 0) {
			update(cur.Y * (ll)(c2(L) - c2(L - b[pos-1].Y)), len - (cur.X - b[pos-1].X));
		} else {
			update(cur.Y * (ll)(c2(R) - c2(R - b[pos].Y)), len - (b[pos].X - cur.X));
		}
	}
}

vector<int> v[2];
vector<pii> p[2];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> len >> n;
	rep(i, n) {
		int s, f; cin >> s >> f;
		v[s].pb(f);
	}
	rep(s, 2) {
		sort(all(v[s]));
		rep(i, sz(v[s]))
			if(i == 0 || v[s][i] != v[s][i-1])
				p[s].pb({v[s][i], 1});
			else
				p[s].back().second++;
	}
	if(sz(p[0]) == 0) p[0].swap(p[1]);

	if(sz(p[1]) == 0) {
		if(sz(p[0]) == 1) cout << c3(n) << endl;
		else cout << c3(n) - c3(n - p[0].front().Y) - c3(n - p[0].back().Y) + c3(n - p[0].front().Y - p[0].back().Y);
		return 0;
	}

	solve(p[0], p[1]);
	solve(p[1], p[0]);

	cout << ans << endl;

	{ return 0; }
}

