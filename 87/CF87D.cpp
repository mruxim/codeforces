// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int((x).size()))
#define cmx(a, b) (a = max(a,b))
#define cmn(a, b) (a = min(a,b))
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n;
struct edge {
	int X, Y, W, ID;
	ll bt;
	const bool operator < (const edge &rhs) const { return W < rhs.W; }
} e[maxn];
int par[maxn];

vi adj[maxn];
int sub[maxn];
ll bty[maxn];

int root(int x) { return par[x] < 0 ? x : par[x] = root(par[x]); }
void merge(int x, int y) { x = root(x), y = root(y); if(par[x] > par[y]) swap(x, y); par[x] += par[y], par[y] = x; }

int dfs(int v) {
	sub[v] = par[v];
	for(auto u: adj[v]) if(!sub[u])
		sub[v] += dfs(u);
	return sub[v];
}

void dfs2(int v, int tot) {
	sub[v] = -sub[v];
	bty[v] = sub[v] * (ll)(tot - sub[v]);
	for(auto u: adj[v]) if(sub[u] < 0)
		dfs2(u, tot);
}

int main() {
	cin >> n;
	rep(i, n-1) cin >> e[i].X >> e[i].Y >> e[i].W, e[i].X--, e[i].Y--, e[i].ID = i, e[i].bt = 0;
	sort(e, e+n-1);
	memset(par, -1, sizeof par);
	rep(i, n-1)
	{
		if(i && e[i].W == e[i-1].W) continue;
		for(int j = i; j < n && e[j].W == e[i].W; j++)
			{ int x = root(e[j].X), y = root(e[j].Y); adj[x].pb(y), adj[y].pb(x); }
		for(int j = i; j < n && e[j].W == e[i].W; j++)
			{ int x = root(e[j].X); if(!sub[x]) dfs(x); }
		for(int j = i; j < n && e[j].W == e[i].W; j++)
			{ int x = root(e[j].X); if(sub[x] < 0) dfs2(x, -sub[x]); }
		for(int j = i; j < n && e[j].W == e[i].W; j++) {
			int x = root(e[j].X), y = root(e[j].Y);
			if(sub[x] < sub[y])
				e[j].bt = bty[x];
			else
				e[j].bt = bty[y];
		}
		for(int j = i; j < n && e[j].W == e[i].W; j++) {
			int x = root(e[j].X), y = root(e[j].Y);
			bty[x] = bty[y] = 0;
			sub[x] = sub[y] = 0;
			adj[x].clear(), adj[y].clear();
			merge(x, y);
		}
	}

	sort(e, e+n-1, [](const edge &aa, const edge &bb) { return aa.ID < bb.ID; } );
	ll most = 0;
	int cnt = 0;
	rep(i, n-1)
		if(e[i].bt > most)
			most = e[i].bt, cnt = 1;
		else if(e[i].bt == most)
			cnt++;
//	rep(i, n-1) cerr << " ^^ " << e[i].bt << endl;
	cout << 2*most << ' ' << cnt << endl;
	rep(i, n-1)
		if(e[i].bt == most)
			cout << i+1 << ' ';
	cout << endl;
	return 0;
}
