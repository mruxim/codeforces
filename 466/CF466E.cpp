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

const int maxn = 100000 + 100;
const int maxm = 100000 + 100;

int n, m;
int par[maxn];
int qt[maxm], qx[maxm], qy[maxm], qi[maxm], toi[maxm], cnt;
vector<int> child[maxn];
int st[maxn], ed[maxn], dep[maxn], now;
int fen[maxn];

void dfs(int u, int depth = 0) {
	st[u] = now++;
	dep[u] = depth;
	for(int v: child[u]) dfs(v, depth+1);
	ed[u] = now;
}

void add(int x, int val) {
	for(x++; x < maxn; x += x & -x)
		fen[x] += val;
}

int get(int x) {
	int r = 0;
	for(x++; x; x -= x & -x)
		r += fen[x];
	return r;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	memset(par, -1, sizeof par);

	cin >> n >> m;
	rep(i, m) {
		cin >> qt[i];
		if(qt[i] == 1) {
			cin >> qx[i] >> qy[i];
			qx[i]--, qy[i]--;
			par[qx[i]] = qy[i];
			child[qy[i]].pb(qx[i]);
		}
		if(qt[i] == 2) cin >> qx[i], qx[i]--, toi[cnt++] = i;
		if(qt[i] == 3) cin >> qx[i] >> qi[i], qx[i]--, qi[i] = toi[qi[i]-1];
	}

	rep(i, n) if(par[i] == -1) dfs(i);

	rep(i, m) {
		if(qt[i] == 1) {
			add(st[qx[i]], 1);
			add(ed[qx[i]], -1);
		}
		if(qt[i] == 3) {
			int u = qx[qi[i]];
			if(st[qx[i]] <= st[u] && st[u] < ed[qx[i]] && get(st[u]) - get(st[qx[i]]) == dep[u] - dep[qx[i]])
				cout << "YES" << endl;
			else
				cout << "NO" << endl;
		}
	}

	return 0;
}

