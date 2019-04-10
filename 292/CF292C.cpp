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

int k;
int d[11];
int mark[11], cmark;
vector<int> goods;
vector<pair<pii,pii>> ans;

void go (int x, int y, int w, int z)
{
	char s[100];
	int len = sprintf (s, "%d%d%d%d", x, y, w, z);
	rep (i, len/2) if (s[i] != s[len-1-i]) return;
	cmark += 7;
	rep (i, len) mark[s[i]-'0'] = cmark;
	rep (i, k) if (mark[d[i]] != cmark) return;

	ans.pb (mkp(pii(x,y),pii(w,z)));
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> k;
	rep (i, k) cin >> d[i];
	sort (d, d+k);

	rep (i, 256)
	{
		bool ok = 1;
		int x = i;
		do {
			ok &= binary_search (d, d+k, x%10),
			x /= 10;
		} while (x);

		if (ok) goods.pb (i);
	}

	for (int x: goods) for (int y: goods)
	{
		vector<int> v;
		if (y == 0) v.pb (0); for (int yy = y; yy; yy /= 10) v.pb (yy%10);
		if (x == 0) v.pb (0); for (int xx = x; xx; xx /= 10) v.pb (xx%10);
		reverse (all(v));
		fer (i, 1, sz(v)) fer (j, i+1, sz(v)+1)
		{
			int z = 0, w = 0;
			rof (p, j, i) z = z*10 + v[p];
			rof (p, i, 0) w = w*10 + v[p];
			if (z >= 256 || w >= 256) continue;
			if ((z == 0 && j-i > 1) || (w == 0 && i > 1)) continue;
			go (x, y, z, w);
		}
	}

	for (int x: goods) for (int y: goods)
	{
		vector<int> v;
		if (y == 0) v.pb (0); for (int yy = y; yy; yy /= 10) v.pb (yy%10);
		if (x == 0) v.pb (0); for (int xx = x; xx; xx /= 10) v.pb (xx%10);
		reverse (all(v));
		fer (i, 1, sz(v)) fer (j, i+1, sz(v))
		{
			int z = 0, w = 0;
			rof (p, j, i) z = z*10 + v[p];
			rof (p, sz(v), j) w = w*10 + v[p];
//			cerr << x << ' ' << y << ' ' << << endl;
			if (z >= 256 || w >= 256) continue;
			if ((z == 0 && j-i > 1) || (w == 0 && sz(v)-j > 1)) continue;
			go (w, z, x, y);
		}
	}

	sort (all(ans));
	ans.erase (unique(all(ans)), ans.end());

	cout << sz(ans) << endl;
	rep (i, sz(ans)) cout << ans[i].X.X << '.' << ans[i].X.Y << '.' << ans[i].Y.X << '.' << ans[i].Y.Y << endl;

	{ int _; cin >> _; return 0; }
}

