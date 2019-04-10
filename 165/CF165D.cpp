// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fer(i, x, n) for (int i = (x), _n = (n); i < _n; i++)
#define rof(i, n, x) for (int i = (n), _x = (x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define cmx(a, b) (a = max(a,b))
#define cmn(a, b) (a = min(a,b))
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

////////////////////////////////////////////////

const int MAXn = 100 * 1000 + 100;

int n, m;
pii e[MAXn];
vi adj[MAXn];
int deg[MAXn], root;
bool mark[MAXn];
int brd;
int beard[MAXn], depth[MAXn];
vi fen[MAXn];

int dfs (int x, int dep = 1)
{
	mark[x] = true;
	int ret = 1;
	beard[x] = brd, depth[x] = dep;
	fch (it, adj[x]) if (!mark[*it])
		ret += dfs (*it, dep + 1);
	return ret;
}

void up (int id, int ind, int val)
{
	vi &F = fen[id];
	for (; ind < sz(F); ind += ind & -ind)
		F[ind] += val;
}

int get (int id, int ind)
{
	vi &F = fen[id];
	int ret = 0;
	for (; ind; ind -= ind & -ind)
		ret += F[ind];
	return ret;
}

int main()
{
	cin >> n;
	rep (i, n-1)
	{
		cin >> e[i].X >> e[i].Y;
		e[i].X--, e[i].Y--;
		deg[e[i].X]++, deg[e[i].Y]++;
		adj[e[i].X].pb (e[i].Y);
		adj[e[i].Y].pb (e[i].X);
	}

	rep (i, n)
		if (deg[i] > deg[root])
			root = i;
	mark[root] = 1;
	fch (it, adj[root]) if (!mark[*it])
	{
		int tmp = dfs (*it);
		fen[brd].resize (tmp + 2);
		brd++;
	}
	cin >> m;
	while (m--)
	{
		int type;
		cin >> type;
		if (type == 1 || type == 2)
		{
			int ind;
			cin >> ind;
			ind--;
			int x = e[ind].X, y = e[ind].Y;
			if (depth[x] > depth[y]) swap (x, y);
			up (beard[y], depth[y], type == 1 ? -1 : 1);
		}
		if (type == 3)
		{
			int x, y;
			cin >> x >> y;
			x--, y--;
			if (depth[x] > depth[y]) swap (x, y);
			if (x == root) beard[x] = beard[y];
			if (beard[x] == beard[y])
			{
				if (get (beard[y], depth[y]) - get (beard[x], depth[x]) == 0)
					cout << depth[y] - depth[x] << endl;
				else
					cout << -1 << endl;
			}
			else
			{
				if (get (beard[y], depth[y]) + get (beard[x], depth[x]) == 0)
					cout << depth[y] + depth[x] << endl;
				else
					cout << -1 << endl;
			}
		}
	}
	{ int _; cin >> _; }
}
