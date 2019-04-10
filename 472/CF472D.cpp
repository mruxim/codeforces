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

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 2000 + 100;

int n;
int d[maxn][maxn];
int mark[maxn];
int dis[maxn], par[maxn];
vector<int> adj[maxn];
bool yes = true;

void dfs(int u, int parent, int dist, int root) {
	if(u != root && d[root][u] == 0) yes = false;
	yes &= (dist == d[root][u] && dist == d[u][root]);
	for(int v: adj[u]) if(v != parent)
		dfs(v, u, dist + d[u][v], root);
}

int main() {
//	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) rep(j, n) scanf(" %d", d[i]+j);

	memset(dis, 70, sizeof dis);
	memset(par, -1, sizeof par);
	dis[0] = 0, par[0] = 0;

	rep(i, n) {
		int u = -1;
		rep(j, n) if(!mark[j] && (u == -1 || dis[j] < dis[u])) u = j;
		
		assert(u != -1);
		mark[u] = 1;
		if(u != 0) adj[u].pb(par[u]), adj[par[u]].pb(u);

		rep(j, n) if(dis[j] > d[u][j]) dis[j] = d[u][j], par[j] = u;
	}

	rep(i, n) dfs(i, -1, 0, i);

	cout << (yes ? "YES" : "NO") << endl;

	return 0;
}

