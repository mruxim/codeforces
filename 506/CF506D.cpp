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
const int CTV = 333;

int n, m, q;
int par[maxn];
vector<pii> edges[maxn];
int qu[maxn], qv[maxn];
int ans[maxn];
int arr[maxn], cnt;
unordered_map<int, int> add[maxn];

int root(int x) {
	return par[x] < 0 ? x : par[x] = root(par[x]);
}

void merge(int x, int y) {
	x = root(x), y = root(y);
	if(x == y) return;
	if(par[x] < par[y]) swap(x, y);
	par[y] += par[x], par[x] = y;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, m) {
		int u, v, c; cin >> u >> v >> c; u--, v--, c--;
		edges[c].pb({u, v});
	}

	cin >> q;
	rep(i, q) cin >> qu[i] >> qv[i], qu[i]--, qv[i]--;

	memset(par, -1, sizeof par);
	rep(c, m) {
		for(pii e: edges[c]) merge(e.X, e.Y);
		
		if(sz(edges[c]) >= CTV)
			rep(i, q) ans[i] += (root(qu[i]) == root(qv[i]) ? 1 : 0);
		else {
			cnt = 0;
			for(pii e: edges[c]) arr[cnt++] = e.X, arr[cnt++] = e.Y;
			sort(arr, arr+cnt);
			cnt = unique(arr, arr+cnt) - arr;
			rep(j, cnt) rep(i, j) if(root(arr[i]) == root(arr[j]))
				add[arr[i]][arr[j]]++, add[arr[j]][arr[i]]++;
		}

		for(pii e: edges[c]) par[e.X] = par[e.Y] = -1;
	}

	rep(i, q) cout << ans[i] + add[qu[i]][qv[i]] << endl;


	return 0;
}

