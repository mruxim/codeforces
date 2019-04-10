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
#define Y second.first
#define Z second.second

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<int, pii> tri;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 70 + 5;

int n;
tri st;
string col[maxn];
int dis[maxn][maxn][maxn];
pii par[maxn][maxn][maxn];
struct cmp {
	bool operator() (tri p, tri q)
	{
		if (dis[p.X][p.Y][p.Z] != dis[q.X][q.Y][q.Z])
			return dis[p.X][p.Y][p.Z] < dis[q.X][q.Y][q.Z];
		return p < q;
	}
};

set <tri, cmp> s;

void fix (tri &p)
{
	if (p.X > p.Y) swap (p.X, p.Y);
	if (p.Y > p.Z) swap (p.Y, p.Z);
	if (p.X > p.Y) swap (p.X, p.Y);
}

void try_move (int x, int y, int z, int d)
{
	rep (i, n) if (i != x && i != y && i != z && col[x][i] == col[y][z])
	{
		tri tmp = mkp(i, pii(y, z)); fix (tmp);
		if (dis[tmp.X][tmp.Y][tmp.Z] <= d) continue;
		s.erase (tmp);
		dis[tmp.X][tmp.Y][tmp.Z] = d;
		par[tmp.X][tmp.Y][tmp.Z] = pii (x, i);
		s.insert (tmp);
	}
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	cin >> st.X >> st.Y >> st.Z;
	st.X--, st.Y--, st.Z--; fix (st);
	rep (i, n) cin >> col[i];

	memset (dis, 50, sizeof dis);
	dis[st.X][st.Y][st.Z] = 0;
	par[st.X][st.Y][st.Z] = pii (-1, -1);
	s.insert (st);

	while (sz(s))
	{
		tri cur = *s.begin(); s.erase (s.begin());
		int cdis = dis[cur.X][cur.Y][cur.Z] + 1;
		try_move (cur.X, cur.Y, cur.Z, cdis);
		try_move (cur.Y, cur.X, cur.Z, cdis);
		try_move (cur.Z, cur.X, cur.Y, cdis);
	}

	tri fin = {0, {1, 2}};
	if (dis[fin.X][fin.Y][fin.Z] > 1e7) cout << -1 << endl;
	else
	{
		cout << dis[fin.X][fin.Y][fin.Z] << endl;
		vector<pii> ans;
		while (fin != st)
		{
			pii p = par[fin.X][fin.Y][fin.Z];
			ans.pb (p);
			if (fin.X == p.Y) fin.X = p.X;
			if (fin.Y == p.Y) fin.Y = p.X;
			if (fin.Z == p.Y) fin.Z = p.X;
			fix (fin);
		}
		reverse (all(ans));
		for (pii p: ans)
			cout << p.X+1 << ' ' << p.second+1 << endl;
	}

	{ return 0; }
}

