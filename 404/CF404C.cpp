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

int n, k;
pii d[maxn];
int deg[maxn];
vector<pii> ans;

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n >> k;
	rep(i, n) cin >> d[i].X, d[i].Y = i;

	sort(d, d+n);

	if(d[0].X != 0 || d[1].X < 1) { cout << -1 << endl; return 0; }

	int pos = 0;
	fer(i, 1, n) {
		while(pos < i && (deg[d[pos].Y] == k || d[pos].X != d[i].X - 1)) pos++;
		if(d[pos].X != d[i].X - 1) { cout << -1 << endl; return 0; }
		deg[d[pos].Y]++, deg[d[i].Y]++;
		ans.pb({d[pos].Y, d[i].Y});
	}

	cout << sz(ans) << endl;
	for(pii e: ans) cout << e.X + 1 << ' ' << e.Y + 1 << endl;

	{ return 0; }
}

