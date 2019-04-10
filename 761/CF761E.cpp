// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

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

const int maxn = 30 + 5;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

int n;
vector<int> adj[maxn];
pii p[maxn];

void build(int u, int par, int x, int y, int dir, int dis = 1 << 29) {
	p[u] = pii(x, y);
	dir ^= 2;
	for(int v: adj[u]) if(v != par) {
		dir = (dir + 1) & 3;
		build(v, u, x + dis * dx[dir], y + dis * dy[dir], dir, dis / 2);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n-1) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	int maxdeg = 0;
	rep(i, n) smax(maxdeg, sz(adj[i]));

	if(maxdeg > 4) {
		cout << "NO" << endl;
		return 0;
	}

	cout << "YES" << endl;

	build(0, -1, 0, 0, 0);

	rep(i, n) cout << p[i].X << ' ' << p[i].Y << endl;

	return 0;
}

