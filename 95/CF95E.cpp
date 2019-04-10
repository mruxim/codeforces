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

const int maxn = 100000 + 100;

int n, m;
vector<int> adj[maxn];
bool mark[maxn];
vector<pii> v;
int dp[maxn], odp[maxn];
int s[maxn];
bool lucky[maxn];

int dfs(int u) {
	if(mark[u]) return 0;
	mark[u] = true;
	int res = 1;
	for(int v: adj[u]) res += dfs(v);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, m) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	rep(i, n) if(!mark[i]) v.pb({dfs(i), 1});

	sort(all(v));
	int k = 0;
	rep(i, sz(v))
		if(i == 0 || v[i].X != v[k-1].X)
			v[k++] = v[i];
		else
			v[k-1].Y++;
	v.resize(k);

	memset(dp, 50, sizeof dp);
	dp[0] = 0;

	for(pii p: v) {
		memcpy(odp, dp, sizeof dp);
		rep(r, p.X) {
			int h, t;
			h = t = 0;
			for(int i = r, df = 0; i <= n; i += p.X, df++) {
				odp[i] -= df;
				while(h < t && odp[s[t-1]] > odp[i]) t--;
				s[t++] = i;
				while(s[h] < i - p.X * p.Y) h++;
				dp[i] = odp[s[h]] + df;
			}
		}
	}

	int ans = 1 << 28;
	lucky[0] = true;
	rep(i, n+1) if(lucky[i]) {
		if(i) smin(ans, dp[i]);
		if(i * 10 + 4 <= n) lucky[i * 10 + 4] = true;
		if(i * 10 + 7 <= n) lucky[i * 10 + 7] = true;
	}

	if(ans <= n)
		cout << ans - 1 << endl;
	else
		cout << -1 << endl;

	return 0;
}

