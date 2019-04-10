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

const int maxn = 200000 + 100;
const int maxd = 10;

int n;
int a[maxn];
vector<int> adj[maxn];
int d[maxn][maxd];
int ans[maxn];

void dfs(int u, int par = -1, int t = 1) {
	d[u][t] = d[u][0];
	rep(i, t) d[u][i] = __gcd(d[u][i], a[u]);
	bool found = false;
	rep(i, t) if(d[u][i] == d[u][t]) found = true;
	if(!found) t++;
	ans[u] = *max_element(d[u], d[u] + t);

	for(int v: adj[u]) if(v != par) {
		copy(d[u], d[u] + t, d[v]);
		dfs(v, u, t);
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> a[i];
	rep(i, n-1) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].pb(v), adj[v].pb(u);
	}

	dfs(0);

	rep(i, n) cout << (i ? " " : "") << ans[i];
	cout << endl;

	return 0;
}

