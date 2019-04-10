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

inline int sqr (int x) { return x*x; }

////////////////////////////////////////////////////////////////////////////////

typedef long long T;

const int maxn = 3000 + 10;
const int cs = 8*sizeof(T);
const int len = (maxn+cs-1)/cs;
const T one = 1;


int n;
pii p[maxn];
int dis[maxn][maxn];
T b[maxn][len];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> p[i].X >> p[i].Y;

	vector<pii> v; v.reserve (n*(n-1)/2);
	rep (i, n) rep (j, n)
		dis[i][j] = sqr (p[i].X - p[j].X) + sqr (p[i].Y - p[j].Y),
		v.pb (pii (i, j));

	sort (all(v), [](const pii &p1, const pii &p2) { return dis[p1.X][p1.Y] > dis[p2.X][p2.Y]; } );

	int ans = 0;
	for (pii q: v)
	{
		rep (i, len) if (b[q.X][i] & b[q.Y][i]) { ans = dis[q.X][q.Y]; break; }
		if (ans) break;
		b[q.X][q.Y/cs] |= one << (q.Y & (cs-1));
		b[q.Y][q.X/cs] |= one << (q.X & (cs-1));
	}

	cout << fixed << setprecision (12) << sqrt (ans) / 2 << endl;

	{ return 0; }
}

