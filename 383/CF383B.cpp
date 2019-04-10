
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

int t, n;
pii p[maxn];
set<pii> s;

void work (pii* a, pii* b)
{
	static set<pii> r;
	r.clear();
	int ed = t;
	while (b-- != a)
	{
		int pos = b->Y + 1;
		auto it = s.lower_bound (pii (pos, -1));
		int st = ed; if (it != s.end()) st = it->X;
		if (it != s.begin())
		{
			it--; if (pos < it->Y) st = pos;
		}
		if (st < ed) r.insert (pii (st, ed));
		ed = pos-1;
	}
	{
		int pos = 0;
		auto it = s.lower_bound (pii (pos, -1));
		int st = ed; if (it != s.end()) st = it->X;
		if (it != s.begin())
		{
			it--; if (pos < it->Y) st = pos;
		}
		if (st < ed) r.insert (pii (st, ed));
		ed = pos-1;
	}
	s = move(r);
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> t >> n;
	rep (i, n) cin >> p[i].X >> p[i].Y, p[i].X--, p[i].Y--;
	sort (p, p+n);

	s.insert (pii (0, 1));
	int row = 0;

	int i = 0;
	while (i < n)
	{
		if (p[i].X > row) work (p, p);
		row = p[i].X + 1;
		int j = i;
		while (j < n && p[j].X == p[i].X) j++;
		work (p+i, p+j);
		i = j;
	}
	if (t-1 >= row) work (p, p);

	if (sz(s) && s.rbegin()->Y == t) cout << 2*t-2 << endl;
	else cout << -1 << endl;

	{ return 0; }
}

