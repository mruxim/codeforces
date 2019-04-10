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

const int maxn = 100000 + 100;

int n, m;
int deg[maxn];
vector<int> adj[maxn];
bool mark[maxn];

int dfs (int u)
{
	if (mark[u]) return 0;
	mark[u] = 1;
	int ret = 1;
	for (int v: adj[u]) ret += dfs (v);
	return ret;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, m)
	{
		int u, v;
		cin >> u >> v; u--, v--;
		adj[u].pb (v);
		adj[v].pb (u);
		deg[u]++, deg[v]++;
	}

	int r = dfs (0);
	int d1 = count (deg, deg+n, 1);
	int d2 = count (deg, deg+n, 2);
	int dn = count (deg, deg+n, n-1);

	if (r == n && d1 == 2 && d2 == n-2 && m == n-1)
		cout << "bus topology" << endl;
	else if (r == n && d2 == n && m == n)
		cout << "ring topology" << endl;
	else if (r == n && dn == 1 && m == n-1)
		cout << "star topology" << endl;
	else
		cout << "unknown topology" << endl;

	{ int _; cin >> _; return 0; }
}

