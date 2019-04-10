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

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> seg;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 2000 + 100;

int n, m;
pii red[maxn], blu[maxn];
vector<seg> ver, hor;
int cnt[maxn][maxn];

void fix (vector<pair <int, pii>> &v)
{
	sort (all (v));
	int ind = 0;
	rep (i, sz(v))
		if (ind && v[i].X == v[ind-1].X && v[i].Y.X <= v[ind-1].Y.Y)
			v[ind-1].Y.Y = v[i].Y.Y;
		else
			v[ind++] = v[i];
	v.resize (ind);
}

inline bool intersect (seg &v, seg &h)
{
	return (h.Y.X <= v.X && v.X <= h.Y.Y) && (v.Y.X <= h.X && h.X <= v.Y.Y);
}

bool check (int time)
{
	ver.clear();
	hor.clear();

	rep (i, n) ver.pb (seg (blu[i].X, pii (blu[i].Y - 2*time, blu[i].Y + 2*time)));
	rep (i, m) hor.pb (seg (red[i].Y, pii (red[i].X - 2*time, red[i].X + 2*time)));

	fix (ver);
	fix (hor);

	int nn = sz(ver);
	int mm = sz(hor);

	rep (i, mm) rep (j, i) cnt[j][i] = 0;

	rep (k, nn)
	{
		vector<int> adj;
		rep (i, mm) if (intersect (ver[k], hor[i]))
		{
			for (int j : adj)
			{
				cnt[j][i]++;
				if (cnt[j][i] == 2)
					return true;
			}
			adj.pb (i);
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, n)
	{
		int x, y; cin >> x >> y;
		blu[i] = pii (x+y, x-y);
	}
	rep (i, m)
	{
		int x, y; cin >> x >> y;
		red[i] = pii (x+y, x-y);
	}

	int lo = 0, hi = 1e7;
	while (hi - lo > 1)
	{
		int md = (lo + hi) / 2;
		if (check (md))
			hi = md;
		else
			lo = md;
	}

	if (hi >= 1e7-1)
		cout << "Poor Sereja!" << endl;
	else
		cout << hi << endl;

	{ int _; cin >> _; return 0; }
}
