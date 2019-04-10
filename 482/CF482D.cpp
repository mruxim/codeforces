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
vector<int> ch[maxn];
int dp[maxn][2];

inline void addto(int &x, int y) {
	x += y;
	if(x >= mod) x -= mod;
}

void dfs(int u) {
	int same[2] = {1, 0}, alt[2] = {1, 0};

	for(int v: ch[u]) {
		dfs(v);
		
		int s0 = same[0], s1 = same[1];
		addto(same[0], s1 * (ll)dp[v][0] % mod);
		addto(same[1], s0 * (ll)dp[v][0] % mod);
		
		int a0 = alt[0], a1 = alt[1];
		addto(alt[0], a1 * (ll)dp[v][1] % mod);
		addto(alt[1], a0 * (ll)dp[v][1] % mod);
	}

	pii p = {0, 1};
	pii q = {0, 1};

	rep(i, sz(ch[u])) {
		int v = ch[u][i];
		int d0 = p.X, d1 = p.Y;
		addto(p.X, d0 * (ll)dp[v][0] % mod);
		addto(p.X, d1 * (ll)dp[v][1] % mod);
		addto(p.Y, d1 * (ll)dp[v][0] % mod);
		addto(p.Y, d0 * (ll)dp[v][1] % mod);
	}
	
	rof(i, sz(ch[u]), 0) {
		int v = ch[u][i];
		int d0 = q.X, d1 = q.Y;
		addto(q.X, d0 * (ll)dp[v][0] % mod);
		addto(q.X, d1 * (ll)dp[v][1] % mod);
		addto(q.Y, d1 * (ll)dp[v][0] % mod);
		addto(q.Y, d0 * (ll)dp[v][1] % mod);
	}

	dp[u][0] = (p.X + (ll)q.X - alt[1] + mod) % mod;
	dp[u][1] = (p.Y + (ll)q.Y - same[0] - same[1] + mod + mod) % mod;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	fer(i, 1, n) {
		int p;
		cin >> p, p--;
		ch[p].pb(i);
	}

	dfs(0);

	cout << (dp[0][0] + dp[0][1]) % mod << endl;

	return 0;
}

