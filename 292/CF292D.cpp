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

const int maxn = 500 + 10;
const int maxm = 10000 + 10;

int n, m, k;
int x[maxm], y[maxm];
vector<int> L, R;

int p[maxn];

int root (int x) { return p[x] < 0 ? x : p[x] = root (p[x]); }
int merge (int x, int y)
{
	x = root (x), y = root (y);
	if (x == y) return 0;
	if (p[x] < p[y]) swap (x, y);
	p[y] += p[x], p[x] = y;
	return 1;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, m) cin >> x[i] >> y[i], x[i]--, y[i]--;

	memset (p, -1, sizeof p);
	rep (i, m) if (merge (x[i], y[i])) L.pb (i);

	memset (p, -1, sizeof p);
	rof (i, m, 0) if (merge (x[i], y[i])) R.pb (i);

	cin >> k;
	rep (z, k)
	{
		int l, r;
		cin >> l >> r; l--;

		memset (p, -1, sizeof p);
		int ans = n;

		for (int i: L)
		{
			if (i >= l) break;
			ans -= merge (x[i], y[i]);
		}

		for (int i: R)
		{
			if (i < r) break;
			ans -= merge (x[i], y[i]);
		}

		cout << ans << endl;
	}

	{ int _; cin >> _; return 0; }
}

