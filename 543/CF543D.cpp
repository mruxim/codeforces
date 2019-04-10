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

const int mod = 1000000000 + 7;
const int maxn = 200000 + 100;

int n;
int par[maxn];
vector<int> child[maxn];
vector<int> LL[maxn], RR[maxn];
int dw[maxn], up[maxn];

void dfs(int u) {
	dw[u] = 1;
	for(int v: child[u]) {
		dfs(v);
		dw[u] = dw[u] * (ll)(dw[v] + 1) % mod;
	}
}

void dfs2(int u, int cnt = 1) {
	up[u] = cnt;
	int k = sz(child[u]);
	if(k == 0) return;

	vector<int> L(k), R(k);

	L[0] = 1;
	fer(i, 1, k) L[i] = L[i-1] * (ll)(dw[child[u][i-1]] + 1) % mod;
	R[k-1] = 1;
	rof(i, k-1, 0) R[i] = R[i+1] * (ll)(dw[child[u][i+1]] + 1) % mod;

	rep(i, k)
		dfs2(child[u][i], (L[i] * (ll)R[i] % mod * cnt + 1) % mod);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	fer(i, 1, n) {
		cin >> par[i]; par[i]--;
		child[par[i]].pb(i);
	}

	dfs(0);
	dfs2(0);
	
	rep(i, n)
		cout << dw[i] * (ll)up[i] % mod << ' ';
	cout << endl;

	return 0;
}

