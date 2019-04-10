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

const int maxn = 400 + 10;
const int maxa = 30000 + 100;

bool p[maxa];

int n;
int a[maxn];

template<class FlowT>
struct MaxFlow {
	static const int maxn = 1000; // change
	static const int maxm = 100000; // change
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
};
MaxFlow<int> graph;

bool mark[maxn];

vector<int> o[maxn];
vector<int> v[maxn];
int k;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	p[0] = p[1] = true;
	rep(i, maxa) if(!p[i])
		for(int j = i+i; j < maxa; j += i) p[j] = true;

	cin >> n;
	rep(i, n) cin >> a[i];

	graph.init(n + 2);
	rep(i, n) rep(j, n) if(a[i] % 2 == 0 && !p[a[i] + a[j]])
		graph.add_edge(i, j, 1);

	rep(i, n) if(a[i] % 2 == 0) graph.add_edge(n, i, 2);
	rep(i, n) if(a[i] % 2 == 1) graph.add_edge(i, n+1, 2);

	int ff = graph.getflow(n, n+1);
	if(ff != n) {
		cout << "Impossible" << endl;
		return 0;
	}

	rep(i, n) if(a[i] % 2 == 0) {
		for(int e = graph.hed[i]; e != -1; e = graph.prv[e])
			if(graph.cap[e] == 0)
				o[i].pb(graph.to[e]), o[graph.to[e]].pb(i);
	}

	memset(mark, false, sizeof mark);
	rep(i, n) if(!mark[i]) {
		while(!mark[i]) {
			mark[i] = true;
			v[k].pb(i);
			assert(sz(o[i]) == 2);
			for(int j: o[i])
				if(!mark[j]) {
					i = j;
					break;
				}
		}
		k++;
	}
	
	cout << k << endl;
	rep(i, k) {
		cout << sz(v[i]);
		for(int x: v[i]) cout << ' ' << x+1;
		cout << endl;
	}

	return 0;
}

