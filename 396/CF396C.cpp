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

const int maxn = 300000 + 100;
const int mod = 1000000000+7;

int n, q;
int par[maxn];
vector<int> child[maxn];
int st[maxn], ed[maxn], dep[maxn], now;
int f1[maxn], f2[maxn];

void dfs(int u, int depth = 0) {
	st[u] = now++;
	dep[u] = depth;
	for(int v: child[u]) dfs(v, depth + 1);
	ed[u] = now;
}

inline void fix(int &val) { if(val >= mod) val -= mod; else if(val < 0) val += mod; }

inline void add(int *f, int pos, int val) {
	for(; pos; pos -= pos & -pos) f[pos] += val, fix(f[pos]);
}

inline int get(int *f, int pos) {
	int ret = 0;
	for (pos++; pos < maxn; pos += pos & -pos) ret += f[pos], fix(ret);
	return ret;
}

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n;
	fer(i, 1, n) cin >> par[i], par[i]--, child[par[i]].pb(i);
	
	dfs(0);

	cin >> q;
	while (q-- > 0) {
		int type; cin >> type;
		if (type == 1) {
			int v, x, k; cin >> v >> x >> k; v--;
			add(f1, ed[v], (x + k * (ll)dep[v]) % mod);
			add(f1, st[v], -(x + k * (ll)dep[v]) % mod);
			add(f2, ed[v], k);
			add(f2, st[v], -k);
		} else {
			int v; cin >> v; v--;
			cout << (get(f1, st[v]) - get(f2, st[v]) * (ll)dep[v] % mod + mod) % mod << endl;
		}
	}

	{ return 0; }
}

