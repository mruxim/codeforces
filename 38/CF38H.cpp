
// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <bitset>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define pb push_back
#define mkp make_pair
#define all(X) (X).begin(),(X).end()

#define X first
#define Y second

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int inf = (1<<30)-1;
const int maxn = 50 + 5;

int n, m;
int dis[maxn][maxn];
int g1, g2, s1, s2;
vector<int> v[maxn];
ll dp[maxn][maxn], odp[maxn][maxn];

ll calc (int maxg, int minb)
{
	memset (dp, 0, sizeof dp);
	dp[0][0] = 1;
	rep (i, n) {
		memcpy (odp, dp, sizeof dp);
		memset (dp, 0, sizeof dp);
		rep (g, n) rep (b, n-g) {
			ll &cur = dp[g][b] = 0;
			if (v[i].front() == maxg) { if (g) cur += odp[g-1][b]; continue; }
			if (v[i].back()  == minb) { if (b) cur += odp[g][b-1]; continue; }
			if (g && v[i].front() <= maxg) cur += odp[g-1][b];
			if (b && v[i].back()  >= minb) cur += odp[g][b-1];
			if (v[i].back()>maxg && *upper_bound(all(v[i]), maxg) < minb) cur += odp[g][b];
		}
	}
	ll ret = 0;
	fer (g, g1, g2+1) fer (b, n-g-s2, n-g-s1+1) ret += dp[g][b];

	return ret;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, n) rep (j, n) dis[i][j] = (i==j ? 0 : inf);

	rep (i, m) {
		int u, v, w; cin >> u >> v >> w; u--, v--;
		smin (dis[u][v], w); smin (dis[v][u], w);
	}
	cin >> g1 >> g2 >> s1 >> s2;
	rep (k, n) rep (i, n) rep (j, n) smin (dis[i][j], dis[i][k]+dis[k][j]);
	rep (i, n) {
		rep (j, n) if (i != j) v[i].pb (dis[i][j] * n + i);
		sort (all(v[i]));
	}

	ll ans = 0;
	rep (i, n) rep (j, n) if (i != j && v[i].front() < v[j].back())
		ans += calc (v[i].front(), v[j].back());

	cout << ans << endl;

	{ return 0; }
}

