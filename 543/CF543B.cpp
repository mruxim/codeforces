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

const int inf = 1 << 25;
const int maxn = 3000 + 100;

int n, m;
vector<int> adj[maxn];
int dis[maxn][maxn];
int q[maxn], h, t;

void bfs(int st, int d[maxn]) {
	rep(i, n) d[i] = inf;
	h = t = 0;

	d[st] = 0;
	q[t++] = st;

	while(h < t) {
		int u = q[h++];
		for(int v: adj[u]) if(d[v] == inf)
			d[v] = d[u] + 1, q[t++] = v;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, m) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	int s1, t1, l1;
	int s2, t2, l2;
	cin >> s1 >> t1 >> l1; s1--, t1--;
	cin >> s2 >> t2 >> l2; s2--, t2--;

	rep(i, n) bfs(i, dis[i]);

	int ans = m+1;
	if(dis[s1][t1] <= l1 && dis[s2][t2] <= l2) {
		smin(ans, dis[s1][t1] + dis[s2][t2]);
		rep(i, n) rep(j, n) {
			int a = min(dis[s1][i] + dis[i][j] + dis[j][t1],
						dis[s1][j] + dis[j][i] + dis[i][t1]);
			int b = dis[s2][i] + dis[i][j] + dis[j][t2];
			if(a <= l1 && b <= l2)
				smin(ans, a + b - dis[i][j]);
		}
	}

	cout << m - ans << endl;

	return 0;
}

