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

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n, m;
int l[maxn], r[maxn], t[maxn];
int c[2*maxn], k;
vector <pair <int, int>> e;
multiset<int> mt;

int p;
pii wall[2*maxn];
multiset <pii> ss;

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, m)
	{
		cin >> l[i] >> r[i] >> t[i];
		c[k++] = l[i];
		e.pb (mkp (l[i], i));
		c[k++] = r[i];
		e.pb (mkp (r[i], i));
//		cerr << i << " ^^ " << endl;
	}
//	rep (i, sz(e)) cerr << "<" << e[i].X << ' ' << e[i].Y << ">\n";

	sort (c, c+k);
	k = unique (c, c+k) - c;

	int pos = 0;
	sort (all (e));
	rep (i, sz(e))
	{
//		cerr << "<" << e[i].X << ' ' << e[i].Y;
		if (e[i].X == l[e[i].Y]) mt.insert (t[e[i].Y]);
		else mt.erase (mt.find (t[e[i].Y]));
//		cerr << ">\n";
		if (i+1 < sz(e) && e[i+1].X > e[i].X && !mt.empty())
		{
			while (c[pos] < e[i].X) pos++;
//			cerr << "$$ " << c[pos] << ' ' << c[pos+1] << ' ' << *mt.begin() << endl;
			wall[p].Y = c[pos+1] - c[pos];
			wall[p].X = *mt.begin() - c[pos];
//			cerr << "@@ " << c[pos] << ' ' << c[pos+1] << ' ' << *mt.begin() << endl;
			p++;
		}
	}

	sort (wall, wall+p, [](const pii &A, const pii &B) { return A.X-A.Y < B.X-B.Y; } );
//	rep (i, p) cerr << "## " << wall[i].X << ' ' << wall[i].Y << endl;
	pos = 0;

	ll sumend = 0;
	ll sumap = 0;

	rep (zz, n)
	{
		int tim;
		cin >> tim;

		while (pos < p && wall[pos].X - tim <= wall[pos].Y)
		{
			ss.insert (wall[pos]);
			sumend += wall[pos].Y;
			sumap += wall[pos].X;
			pos++;
//			cerr << "%% " << pos << endl;
		}

		while (sz(ss) && ss.begin()->X - tim <= 0)
		{
//			cerr << "!! " << endl;
			sumap -= ss.begin()->X;
			ss.erase (ss.begin());
		}

		cout << sumend - sumap + tim * (ll)sz(ss) << endl;
	}


	{ int _; cin >> _; return 0; }
}
