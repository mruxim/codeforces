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
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 300000 + 100;
const int maxs = 1000000 + 100;

int n, m;
pii a[maxn];
vector<int> q[maxn];
vector<int> p[maxs];
int ind[maxn];
int f[maxs];
int ans[maxn];

void add (int x) { for (x++; x <= maxs; x += x & -x) f[x]++; }
int get (int x) { int r = 0; for (x++; x; x -= x & -x) r += f[x]; return r; }

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, n) cin >> a[i].X >> a[i].Y;
	sort (a, a+n);
	rep (i, m)
	{
		int tmp;
		cin >> tmp;
		q[i].resize (tmp+2);
		q[i][0] = 0, p[0].pb (i);
		fer (j, 1, tmp+1)
			cin >> q[i][j], p[q[i][j]].pb (i);
		q[i].back() = maxs - 1;
		ind[i] = sz(q[i]) - 1;
	}

	int ap = n;
	rof (i, maxs-2, 0)
	{
		while (ap > 0 && a[ap-1].X > i) ap--, add (a[ap].Y);
		rep (j, sz(p[i]))
		{
			int v = p[i][j];
			ans[v] += get (q[v][ind[v]] - 1);
			ind[v]--;
		}
	}

	rep (i, m) cout << n - ans[i] << endl;

	{ int _; cin >> _; return 0; }
}
