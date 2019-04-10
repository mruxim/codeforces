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

const ll inf = 1LL<<20;

const int maxn = 22 + 2;

int n, m, males, females;
int N;
char s[maxn][maxn];
ll dis[maxn*maxn][maxn*maxn];
vector<int> e;
vector<pii> p, q;

pii read() {
	int r, c, t;
	cin >> r >> c >> t; r--, c--;
	return {r * m + c, t};
}


template<class FlowT>
struct MaxFlow {
	static const int maxn = 10000; // change
	static const int maxm = 2000000; // change
	static const FlowT FlowEPS = FlowT(1e-7); // change
	static const FlowT FlowINF = FlowT(1<<29); // change

	int n, m;
	int to[2*maxm], prv[2*maxm], hed[maxn];
	FlowT cap[2*maxm];
	int dis[maxn], pos[maxn];

	void init(int _n) { n = _n, m = 0; memset (hed, -1, n * sizeof hed[0]); }

	inline void add_edge(int x, int y, FlowT c) { // unidir! change to bidir. if needed!
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
MaxFlow<int> g;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> males >> females;
	if(abs(males - females) != 1) { cout << -1 << endl; return 0; }
	int N = n*m;
	rep(i, n) cin >> s[i];

	rep(i, N) rep(j, N) dis[i][j] = inf;
	rep(i, N) dis[i][i] = 0;
	rep(i, n) rep(j, m) if(s[i][j] == '.')
		rep(ii, n) rep(jj, m) if(s[ii][jj] == '.')
			if(abs(i-ii) + abs(j-jj) == 1)
				dis[i*m+j][ii*m+jj] = 1;
	rep(k, N) if(s[k/m][k%m] == '.')
		rep(i, N) rep(j, N)
			smin(dis[i][j], dis[i][k] + dis[k][j]);

	(males < females ? p : q).pb(read());
	rep(i, males) p.pb(read());
	rep(i, females) q.pb(read());
	smax(males, females);
	smax(females, males);

	ll lo = -1, hi = (1LL << 30) * maxn * maxn;
	int add = 2*N;
	int tot = 2 + add + males + females;
	int src = tot-2;
	int snk = tot-1;
	while(hi - lo > 1) {
		ll md = (lo + hi) / 2;
		g.init(tot);
		rep(i, males) g.add_edge(src, add+i, 1);
		rep(i, females) g.add_edge(add+males+i, snk, 1);
		rep(i, N) if(s[i/m][i%m] == '.') {
			g.add_edge(2*i+0, 2*i+1, 1);
			rep(j, males) if(dis[p[j].X][i] != inf && dis[p[j].X][i] * p[j].Y <= md)
				g.add_edge(add+j, 2*i+0, 1);
			rep(j, females) if(dis[q[j].X][i] != inf && dis[q[j].X][i] * q[j].Y <= md)
				g.add_edge(2*i+1, add+males+j, 1);
		}
		if(g.getflow(src, snk) == males)
			hi = md;
		else
			lo = md;
	}

	cout << (hi < (1LL << 30) * maxn * maxn ? hi : -1) << endl;

	return 0;
}

