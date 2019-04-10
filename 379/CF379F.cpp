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

const int maxn = 1000*1000 + 1000;
const int maxp = 22;

int n, q;
int d[maxn];
int p[22][maxn];
int x, y, dia;

void setpar (int v, int par)
{
	d[v] = d[par]+1;
	p[0][v] = par;
	fer (i, 1, maxp)
		p[i][v] = p[i-1][p[i-1][v]];
}

int dis (int u, int v)
{
	int ret = 0;
	if (d[u] > d[v]) swap (u, v);
	rof (i, maxp, 0)
		if (d[u] <= d[p[i][v]])
			v = p[i][v], ret += 1<<i;
	if (u == v) return ret;
	rof (i, maxp, 0)
		if (p[i][u] != p[i][v])
			u = p[i][u], v = p[i][v], ret += 2<<i;
	return ret + 2;
}

int main()
{
	ios_base::sync_with_stdio (false);

	d[0] = 0;
	setpar (0, 0);
	setpar (1, 0);
	setpar (2, 0);
	setpar (3, 0);
	x = 1, y = 2;
	dia = 2;
	n = 4;

	cin >> q;
	while (q--)
	{
		int v;
		cin >> v; v--;

		setpar (n, v); n++;
		setpar (n, v); n++;

		int dx = dis (n-1, x);
		int dy = dis (n-1, y);
		if (dx > dia)
			y = n-1, dia = dx;
		if (dy > dia)
			x = n-1, dia = dy;
		cout << dia << endl;
	}

	{ int _; cin >> _; return 0; }
}

