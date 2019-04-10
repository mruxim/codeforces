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
const int lgn = 20;

int n, m, q;
vector<int> adj[maxn];
bool mark[maxn];
int uu[maxn], vv[maxn];
int dep[maxn];
vector<int> st;
int comp[maxn];
int cc;

int dfs(int u, int pe = -1, int depth = 0) {
	mark[u] = true;
	dep[u] = depth;
	int low = depth;
	st.pb(u);
	for(int i: adj[u]) if(i != pe) {
		int v = uu[i] + vv[i] - u;
		if(mark[v]) {
			smin(low, dep[v]);
		} else {
			int tmp = dfs(v, i, depth + 1);
			smin(low, tmp);
		}
	}
	if(low == depth) {
		int v = -1;
		do {
			v = st.back();
			st.pop_back();
			comp[v] = cc;
		} while(v != u);
		cc++;
	}

	return low;
}

vector<int> cadj[maxn];
int cpar[maxn][lgn], cdep[maxn];
int up[maxn], dw[maxn];

void dfs2(int cu, int parent, int depth = 0) {
	cpar[cu][0] = parent;
	fer(i, 1, lgn) cpar[cu][i] = cpar[cpar[cu][i-1]][i-1];
	cdep[cu] = depth;
	for(int cv: cadj[cu]) if(cv != parent)
		dfs2(cv, cu, depth + 1);
}

int lca(int u, int v) {
	if(cpar[u][lgn-1] != cpar[v][lgn-1]) return -1;
	if(cdep[u] > cdep[v]) swap(u, v);
	rof(i, lgn, 0) if(cdep[cpar[v][i]] >= cdep[u]) v = cpar[v][i];
	if(u == v) return u;
	rof(i, lgn, 0) if(cpar[u][i] != cpar[v][i])
		u = cpar[u][i], v = cpar[v][i];
	return cpar[u][0];
}

bool yes = true;

void dfs3(int cu) {
	for(int cv: cadj[cu]) if(cv != cpar[cu][0]) {
		dfs3(cv);
		dw[cu] += dw[cv];
		up[cu] += up[cv];
	}
	if(dw[cu] > 0 && up[cu] > 0) yes = false;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> q;
	rep(i, m) {
		cin >> uu[i] >> vv[i]; uu[i]--, vv[i]--;
		adj[uu[i]].pb(i);
		adj[vv[i]].pb(i);
	}

	rep(i, n) if(!mark[i])
		dfs(i);

	rep(i, m) if(comp[uu[i]] != comp[vv[i]]) {
		cadj[comp[uu[i]]].pb(comp[vv[i]]);
		cadj[comp[vv[i]]].pb(comp[uu[i]]);
	}

	rep(i, cc) cpar[i][0] = -1;
	rep(i, cc) if(cpar[i][0] == -1)
		dfs2(i, i);

	while(q--) {
		int u, v; cin >> u >> v; u--, v--;
		if(comp[u] == comp[v]) continue;
		u = comp[u], v = comp[v];
		int t = lca(u, v);
		if(t == -1)
			yes = false;
		else
			up[u]++, up[t]--,
			dw[v]++, dw[t]--;
	}

	rep(i, cc) if(cpar[i][0] == i)
		dfs3(i);

	cout << (yes ? "Yes" : "No") << endl;

	return 0;
}

