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

const int mod = 1000000000+7;

const int maxn = 100000 + 100;

int n;
vector<int> child[maxn];
int col[maxn];
int dp0[maxn], dp1[maxn];

void dfs(int u) {
	int c0 = 1;
	int c1 = 0;
	vector<int> L, R;
	L.pb(1);
	for(int v: child[u]) {
		dfs(v);
		c0 = c0 * (ll)(dp0[v] + dp1[v]) % mod;
		L.pb(dp0[v] + dp1[v]);
		R.pb(dp0[v] + dp1[v]);
	}
	R.pb(1);

	fer(i, 1, sz(L)) L[i] = L[i-1] * (ll)L[i] % mod;
	rof(i, sz(R)-1, 0) R[i] = R[i+1] * (ll)R[i] % mod;

	rep(i, sz(child[u]))
		c1 = (c1 + dp1[child[u][i]] * (ll)L[i] % mod * R[i+1]) % mod;

	dp0[u] = c0, dp1[u] = c1;
	if(col[u]) dp1[u] = dp0[u], dp0[u] = 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	fer(i, 1, n) {
		int p; cin >> p;
		child[p].pb(i);
	}
	rep(i, n) cin >> col[i];

	dfs(0);

	cout << dp1[0] << endl;

	return 0;
}

