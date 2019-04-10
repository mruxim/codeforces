// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?
// ....... .. .... .. ...., ....... ..!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, i##__n = (int)(n); i < i##__n; ++i)
#define fer(i, a, b) for (int i = (int)(a), i##__b = (int)(b); i < i##__b; ++i)
#define rof(i, b, a) for (int i = (int)(b), i##__a = (int)(a); i-- > i##__a; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n, m;
vector<pii> adj[maxn];
bool mark[maxn];
int pxor[maxn];
vector<int> base;

void dfs(int u, int cur = 0) {
	mark[u] = true;
	pxor[u] = cur;
	for(pii vw: adj[u]) if(!mark[vw.X]) dfs(vw.X, cur ^ vw.Y);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, m) {
		int u, v, w; cin >> u >> v >> w; u--, v--;
		adj[u].pb({v, w}), adj[v].pb({u, w});
	}

	dfs(0);

	rep(u, n) for(pii vw: adj[u]) if(u <= vw.X) {
		int x = pxor[u] ^ pxor[vw.X] ^ vw.Y;
		for(int  p: base) if((x ^ p) < x) x ^= p;
		if(x == 0) continue;
		for(int &p: base) if((p ^ x) < p) p ^= x;
		base.pb(x);
	}

	int ans = pxor[0] ^ pxor[n-1];
	for(int p: base) if((ans ^ p) < ans) ans ^= p;

	cout << ans << endl;

	return 0;
}

