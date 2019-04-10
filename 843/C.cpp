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

int n;
vector<int> adj[maxn];
int sub_size[maxn];
bool is_centroid[maxn];
vector<int> vx, vy, vz;

void find_centroid(int u, int par = -1) {
	int max_sub = 0;
	sub_size[u] = 1;
	for(int v: adj[u]) if(v != par) {
		find_centroid(v, u);
		sub_size[u] += sub_size[v];
		smax(max_sub, sub_size[v]);
	}
	smax(max_sub, n - sub_size[u]);
	if(max_sub <= n / 2) is_centroid[u] = true;
}

int parent[maxn];
vector<int> stash;
void dfs(int u, int par, int depth = 0) {
	if(depth > 1) stash.pb(u);
	parent[u] = par;
	for(int v: adj[u]) if(v != par) dfs(v, u, depth + 1);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n-1) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].pb(v), adj[v].pb(u);
	}

	find_centroid(0);

	rep(c, n) if(is_centroid[c])
		for(int x: adj[c]) if(!is_centroid[x]) {
			stash.clear();
			dfs(x, c);
			int cur = x;
			for(int v: stash) {
				vx.pb(c), vy.pb(cur), vz.pb(v);
				cur = v;
				vx.pb(v), vy.pb(parent[v]), vz.pb(x);
			}
			if(cur != x) vx.pb(c), vy.pb(cur), vz.pb(x);
		}

	cout << sz(vx) << endl;
	rep(i, sz(vx)) cout << vx[i] + 1 << ' ' << vy[i] + 1 << ' ' << vz[i] + 1 << endl;

	return 0;
}

