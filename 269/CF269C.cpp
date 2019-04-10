// .... .... .... !

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define X first
#define Y second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 2 * 100000 + 200;

int n, m;
int x[maxn], y[maxn], c[maxn];
vector <pii> adj[maxn];
int sum[maxn];
int q[maxn], h, t;
int pos[maxn], cp;

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, m)
	{
		cin >> x[i] >> y[i] >> c[i];
		x[i]--, y[i]--;
		adj[x[i]].pb (pii (y[i], c[i]));
		adj[y[i]].pb (pii (x[i], c[i]));
		sum[x[i]] += c[i];
		sum[y[i]] += c[i];
	}

	rep (i, n) sort (adj[i].begin(), adj[i].end());
	rep (i, n-1) sum[i] /= 2;

	memset (pos, -1, sizeof pos);

	q[t++] = 0;
	pos[0] = 0;
	while (h < t)
	{
		int v = q[h++];
//		pos[v] = h-1;
		for (auto u : adj[v])
			if (pos[u.X] == -1)
			{
				sum[u.X] -= u.Y;
				if (sum[u.X] == 0)
					q[t++] = u.X, pos[u.X] = t-1;
			}
	}
	pos[n-1] = n-1;

//	rep (i, n) cerr << 1+q[i] << ' '; cerr << endl;

	rep (i, m)
		cout << (pos[x[i]] > pos[y[i]]) << endl;

	{ int _; cin >> _; }
	return 0;
}
