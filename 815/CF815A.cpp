// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?
// ....... .. .... .. ...., ....... ..!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, i##__n = (int)(n); i < i##__n; ++i)
#define fer(i, a, b) for (int i = (int)(a), i##__b = (int)(b); i < i##__b; ++i)
#define rof(i, b, a) for (int i = (int)(b), i##__a = (int)(a); i-- > i##__a; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100 + 10;

int n, m;
int g[maxn][maxn];
vector<pii> ans;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) rep(j, m) cin >> g[i][j];

	int mn = 999;
	rep(i, n) rep(j, m) smin(mn, g[i][j]);

	if(n < m)	rep(x, mn) rep(i, n) ans.pb(pii(0, i));
	else		rep(x, mn) rep(j, m) ans.pb(pii(1, j));

	rep(i, n) rep(j, m) g[i][j] -= mn;

	rep(i, n) {
		mn = 999;
		rep(j, m) smin(mn, g[i][j]);
		rep(x, mn) ans.pb(pii(0, i));
		rep(j, m) g[i][j] -= mn;
	}

	rep(j, m) {
		mn = 999;
		rep(i, n) smin(mn, g[i][j]);
		rep(x, mn) ans.pb(pii(1, j));
		rep(i, n) g[i][j] -= mn;
	}

	bool ok = true;
	rep(i, n) rep(j, m) if(g[i][j]) ok = false;

	if(ok) {
		cout << sz(ans) << endl;
		for(pii p: ans) cout << (p.X ? "col" : "row") << ' ' << p.Y + 1 << endl;
	}
	else
		cout << -1 << endl;

	return 0;
}

