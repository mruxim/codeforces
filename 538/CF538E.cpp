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
#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 200000 + 100;

int n;
vector<int> adj[maxn];
int sub[maxn];
int r[maxn], s[maxn];

void dfs(int u, int par = -1, int depth = 0) {
	sub[u] = 0;

	int sumr = 0;
	int sums = 0;
	int ms = 1<<28;

	for(int v: adj[u]) if(v != par) {
		dfs(v, u, depth + 1);
		sub[u] += sub[v];
		sumr += r[v] + 1;
		sums += s[v];
		smin(ms, sub[v] - s[v]);
	}

	if(sub[u] == 0) {
		sub[u] = 1;
		r[u] = s[u] = 0;
		return;
	}

	if(depth % 2 == 1) {
		r[u] = sumr - 1;
		s[u] = sub[u] - ms;
	}
	else {
		r[u] = 1<<28;
		for(int v: adj[u]) if(v != par) smin(r[u], r[v]);
		s[u] = sums;
	}
}


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n-1) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(0);

	cout << sub[0] - r[0] << ' ' << sub[0] - s[0] << endl;

	return 0;
}

