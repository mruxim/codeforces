// .... .... .....!
// P..... C.....!

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

typedef long long ll;
typedef pair <int, int> pii;

#define rank asdfhadf

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n;
vector<int> adj[maxn];
int rank[maxn];
bool mark[maxn];

int dfs (int x, int par = -1)
{
	if (rank[x]) return 0;
	mark[x] = false;
	int ret = 1;
	for (int y : adj[x]) if (y != par) ret += dfs (y, x);
	return ret;
}

int center (int x, int csize)
{
	mark[x] = true;
	int sum = 1;
	int mx = 0;
	for (int y : adj[x]) if (!mark[y] && !rank[y])
	{
		int tmp = center (y, csize);
		if (tmp <= 0) return tmp;
		sum += tmp;
		mx = max (mx, tmp);
	}
	if (max (mx, csize-sum) <= csize/2) return -x;
	return sum;
}

void solve (int x, int currank)
{
	int csize = dfs (x);
	int v = -center (x, csize);
	rank[v] = currank;
	for (int y : adj[v]) if (!rank[y])
		solve (y, currank+1);
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n-1)
	{
		int x, y;
		cin >> x >> y;
		x--, y--;
		adj[x].pb (y);
		adj[y].pb (x);
	}

	solve (0, 1);

	rep (i, n) cout << (char)(rank[i] - 1 + 'A') << ' ';

	{ int _; cin >> _; return 0; }
}
