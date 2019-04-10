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
#define A second.first

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n, m, s;
int c[maxn];
pii bug[maxn];
pair<int,pii> stu[maxn];
int ans[maxn], perm[maxn];

bool check(int d)
{
	fill (ans, ans+m, -1);
	set<pii> s;
	int pos = n;
	int cost = 0;
	rof (i, m, 0)
	{
		while (pos && stu[pos-1].X >= bug[i].X)
		{
			pos--;
			s.insert (pii (stu[pos].Y.X, stu[pos].Y.Y));
		}
		if (ans[i] == -1)
		{
			if (s.empty()) return false;
			int cur = s.begin()->Y;
			cost += c[cur];
			if (cost > ::s) return false;
			s.erase (s.begin());
			int rem = d;
			int j = i;
			while (j >= 0 && rem) ans[j] = cur, j--, rem--;
		}
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m >> s;
	rep (i, m) cin >> bug[i].X, bug[i].Y = i;
	rep (i, n) cin >> stu[i].X;
	rep (i, n) cin >> stu[i].Y.X, stu[i].Y.Y = i, c[i] = stu[i].Y.X;

	sort (bug, bug+m);
	sort (stu, stu+n);

	int lo = 0, hi = m;
	while (hi-lo > 1)
	{
		int md = (lo+hi) / 2;
		if (check(md))
			hi = md;
		else
			lo = md;
	}

	if (check (hi))
	{
		rep (i, m) perm[bug[i].Y] = i;
		cout << "YES" << endl;
		rep (i, m) cout << ans[perm[i]]+1 << ' ';
		cout << endl;
	}
	else
		cout << "NO" << endl;

	{ int _; cin >> _; return 0; }
}
