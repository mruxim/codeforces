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

template<class FlowT>
struct MaxFlow {
	static const int maxn = 1000; // change
	static const int maxm = 20000; // change
	static const FlowT FlowEPS = FlowT(1e-7); // change
	static const FlowT FlowINF = FlowT(1<<29); // change

	int n, m;
	int to[2*maxm], prv[2*maxm], hed[maxn];
	FlowT cap[2*maxm];
	int dis[maxn], pos[maxn];

	void init(int _n) { n = _n, m = 0; memset (hed, -1, n * sizeof hed[0]); }

	inline void add_edge(int x, int y, FlowT c) {
		to[m] = y, cap[m] = c, prv[m] = hed[x], hed[x] = m++;
		to[m] = x, cap[m] = 0, prv[m] = hed[y], hed[y] = m++;
	}

	bool bfs(int source, int sink) {
		static int que[maxn], head, tail;
		memset(dis, -1, n * sizeof dis[0]); head = tail = 0;
		dis[source] = 0; que[tail++] = source;
		while(head < tail) {
			int u = que[head++];
			for(int e = hed[u]; e != -1; e = prv[e])
				if(cap[e] > FlowEPS && dis[to[e]] == -1)
					dis[to[e]] = dis[u]+1, que[tail++] = to[e];
			if(dis[sink] != -1) break;
		}
		return dis[sink] != -1;
	}

	FlowT dfs(int u, int sink, FlowT add = FlowINF) {
		if(u == sink) return add;
		FlowT res = 0;
		for(int &e = pos[u]; e != -1; e = prv[e])
			if(cap[e] > FlowEPS && dis[to[e]] == dis[u]+1) {
				FlowT cur = dfs(to[e], sink, min(add, cap[e]));
				cap[e] -= cur, cap[e^1] += cur, add -= cur, res += cur;
				if(add <= FlowEPS/2) break;
			}
		return res;
	}

	FlowT getflow(int source, int sink) {
		FlowT flow = 0;
		while(bfs(source, sink)) {
			memcpy(pos, hed, n * sizeof hed[0]);
			flow += dfs(source, sink);
		}
		return flow;
	}

	void cut(int u, bool clr = 1) { // u = source --> pos[setA] = 1, pos[setB] = 0;
		if(clr) memset(pos, 0, n * sizeof pos[0]);
		if(pos[u]) return; pos[u] = 1;
		for(int e = hed[u]; e != -1; e = prv[e])
			if(cap[e] > FlowEPS) cut(to[e], 0);
	}
};
MaxFlow<int> graph;

const int inf = 1<<20;
const int maxn = 100 + 100;
const int maxm = 100 + 100;

int n, m;
int a[maxn];
int uu[maxm], vv[maxm];
set<int> s;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) cin >> a[i];
	rep(i, m) {
		cin >> uu[i] >> vv[i]; uu[i]--, vv[i]--;
		if(uu[i] % 2) swap(uu[i], vv[i]);
	}

	rep(i, n) {
		int x = a[i];
		for(int v = 2; v*v <= x; v++)
			if(x % v == 0) {
				s.insert(v);
				while(x % v == 0) x /= v;
			}
		if(x > 1) s.insert(x);
	}

	int ans = 0;

	for(int x: s) {
		graph.init(n+2);
		int src = n, snk = n+1;
		rep(i, m) graph.add_edge(uu[i], vv[i], inf);
		rep(i, n) {
			int c = 0;
			int v = a[i];
			while(v % x == 0) v /= x, c++;
			if(i % 2) graph.add_edge(i, snk, c);
			else graph.add_edge(src, i, c);
		}
		ans += graph.getflow(src, snk);
	}

	cout << ans << endl;

	return 0;
}

