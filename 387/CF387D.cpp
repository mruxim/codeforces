
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

const int maxn = 500 + 10;

int n, m;
vector<int> adj[maxn];
int graph[maxn][maxn];
int match[maxn];
int vis[maxn];

int dfs (int x)
{
	if (x == -1) return 1;
	for (int y: adj[x])
	{
		if (vis[y]) continue;
		vis[y] = 1;
		if (dfs (match[y]))
		{
			match[y] = x;
			return 1;
		}
	}
	return 0;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, m) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].pb (v);
		graph[u][v]++;
	}

	int ans = 1<<29;
	rep (center, n)
	{
		int cur = 1 - graph[center][center];
		int ms = 0;
		memset (match, -1, sizeof match);
		rep (i, n) if (i != center)
		{
			cur += 2 - graph[center][i] - graph[i][center];
			for (int j: adj[i]) cur += (j != center);
			memset (vis, 0, sizeof vis);
			vis[center] = 1;
			ms += dfs (i);
		}
		smin (ans, cur - ms + (n - 1 - ms));
	}
	cout << ans << endl;

	{ return 0; }
}

