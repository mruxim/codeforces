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
const int maxn = 100000 + 10;

int n, e;
vector <int> adj[maxn];
char vis[maxn];
int now;
int index[maxn], lowlink[maxn];
int comp[maxn], comps;
stack <int> st;
bool active[maxn];

void Tarjan_DFS (int u)
{
	vis[u] = 1;
	index[u] = lowlink[u] = now++;
	st.push (u);
	active[u] = true;
	for (int i = 0; i < (int)adj[u].size(); i++)
	{
		int v = adj[u][i];
		if (vis[v] == 0)
		{
			Tarjan_DFS (v);
			lowlink[u] = min (lowlink[u], lowlink[v]);
		}
		else if (active[v])
			lowlink[u] = min (lowlink[u], index[v]);
	}
	if (index[u] == lowlink[u])
	{
		while (st.top() != u)
		{
			comp[st.top()] = comps;
			active[st.top()] = false;
			st.pop();
		}
		comp[u] = comps;
		active[u] = false;
		st.pop();
		comps++;
	}
	vis[u] = 2;
}

void Tarjan ()
{
	for (int i = 0; i < n; i++)
		if (vis[i] == 0)
			Tarjan_DFS (i);
}

int cost[maxn];
int minc[maxn], cnt[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> cost[i];
	cin >> e;
	rep(i, e) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].pb(v);
	}

	Tarjan();

	rep(i, comps) minc[i] = 2e9;

	rep(i, n) {
		if(cost[i] > minc[comp[i]]) continue;
		if(cost[i] < minc[comp[i]]) cnt[comp[i]] = 0;
		minc[comp[i]] = cost[i];
		cnt[comp[i]]++;
	}

	ll ans = accumulate(minc, minc+comps, 0LL);
	ll ways = 1;
	rep(i, comps) ways = ways * cnt[i] % 1000000007;

	cout << ans << ' ' << ways << endl;

	{ return 0; }
}

