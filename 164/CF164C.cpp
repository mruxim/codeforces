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

typedef int FT;
typedef int CT;
struct MinCostFlow {
	static const int maxn = 2000+100; // ..
	static const int maxm = 5000+100;
	static const FT FlowEPS = FT(1e-7);
	static const FT FlowINF = FT(1<<29);
	static const CT CostINF = CT(1<<29); 

	int n, m;
	int to[2*maxm], prv[2*maxm], head[maxn], par[maxn];
	FT cap[2*maxm];
	CT cost[2*maxm], dis[maxn], pot[maxn];
	priority_queue<pair<CT,int>> pq;
	bool mark[maxn];

	void init (int _n) { n = _n, m = 0; rep (i, n) head[i] = -1, pot[i] = 0; }

	inline int add_edge (int u, int v, FT c, CT t) { // ..
		to[m] = v, cap[m] = c, cost[m] =  t, prv[m] = head[u], head[u] = m++;
		to[m] = u, cap[m] = 0, cost[m] = -t, prv[m] = head[v], head[v] = m++;
		return m-2;
	}

	pair<FT, CT> pushflow (int source, int sink) {
		rep (i, n) mark[i] = false, dis[i] = CostINF;
		dis[source] = 0, par[source] = -1; pq.push ({0, source});

		while (!pq.empty()) {
			int u = pq.top().Y; pq.pop();
			if (mark[u]) continue; mark[u] = true;
			for (int e = head[u]; e != -1; e = prv[e]) if (cap[e] > FlowEPS && !mark[to[e]]) {
				CT ndis = dis[u] + cost[e] + pot[u] - pot[to[e]];
				if (ndis < dis[to[e]])
					dis[to[e]] = ndis, par[to[e]] = e, pq.push ({-ndis, to[e]});
			}
		}

		pair<FT, CT> ret = {0, 0};
		if (!mark[sink]) return ret;

		rep (i, n) pot[i] += dis[i];
		ret.X = FlowINF;
		for (int e = par[sink]; e != -1; e = par[to[e^1]]) ret.X = min (ret.X, cap[e]);
		for (int e = par[sink]; e != -1; e = par[to[e^1]])
			cap[e] -= ret.X, cap[e^1] += ret.X, ret.Y += cost[e] * ret.X;
		return ret;
	}

	pair<FT, CT> getflow (int source, int sink) {

		for (bool cont = true; !(cont = !cont); ) {
			rep (u, n) for (int e = head[u]; e != -1; e = prv[e]) if (cap[e] > FlowEPS)
				if (pot[u] + cost[e] < pot[to[e]])
					pot[to[e]] = pot[u] + cost[e], cont = true;
		}

		pair<FT, CT> ret;
		for (pair<FT, CT> tmp; (tmp = pushflow (source, sink)).X; )
			ret.X += tmp.X, ret.Y += tmp.Y;
		return ret;
	}

	void cut (int u, bool clr = 1) { // u = source --> par[setA] = 1, par[setB] = 0;
		if (clr) memset (par, 0, n * sizeof par[0]);
		if (par[u]) return; par[u] = 1;
		for (int e = head[u]; e != -1; e = prv[e])
			if (cap[e] > FlowEPS) cut (to[e], 0);
	}
};
MinCostFlow graph;

const int maxn = 1000 + 100;

int n, k;
int s[maxn], t[maxn], c[maxn];
int eid[maxn];
int bank[2*maxn], bs;

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n >> k;
	rep (i, n) cin >> s[i] >> t[i] >> c[i], t[i] += s[i], bank[bs++] = s[i], bank[bs++] = t[i];
	sort(bank, bank+bs); bs = unique(bank, bank+bs) - bank;
	rep (i, n)
		s[i] = lower_bound(bank, bank+bs, s[i]) - bank,
		t[i] = lower_bound(bank, bank+bs, t[i]) - bank;
	int src = bs, snk = bs-1;

	graph.init (bs+1);

	graph.add_edge (src, 0, k, 0);
	rep (i, bs-1) graph.add_edge (i, i+1, k+3463, 0);
	rep (i, n) eid[i] = graph.add_edge (s[i], t[i], 1, -c[i]);
	
	graph.getflow (src, snk);

	rep (i, n) cout << 1-graph.cap[eid[i]] << ' '; cout << endl;
	
	{ return 0; }
}

