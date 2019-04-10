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

int n, q;
int a[maxn], b[maxn], w[maxn];
vector<int> adj[maxn];

int sub[maxn];
double prob[maxn];

int dfs(int u, int par = -1, int pid = -1) {
	sub[u] = 1;
	for(int id: adj[u]) {
		int v = a[id] + b[id] - u;
		if(v != par) sub[u] += dfs(v, u, id);
	}
	if(pid != -1)
		prob[pid] = sub[u] * (ll)(sub[u]-1) / 2 * (n-sub[u]) + sub[u] * (ll)(n-sub[u]) * (n-sub[u]-1) / 2;
	return sub[u];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n-1) {
		cin >> a[i] >> b[i] >> w[i];
		a[i]--, b[i]--;
		adj[a[i]].pb(i);
		adj[b[i]].pb(i);
	}

	dfs(0);

	rep(i, n-1) prob[i] /= n * (ll)(n-1) * (n-2) / 6;

	double ans = 0;
	rep(i, n-1) ans += w[i] * prob[i];

	cout.setf(ios::fixed);
	cout.precision(8);

	cin >> q;
	rep(i, q) {
		int id, r;
		cin >> id >> r; id--;
		ans -= prob[id] * (w[id] - r);
		w[id] = r;
		cout << 2*ans << endl;
	}

	return 0;
}

