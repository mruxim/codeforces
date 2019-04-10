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

const int maxn = 18+1;

int n;
double a[maxn][maxn];
double p[1<<maxn];
double ans[maxn];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) rep (j, n) cin >> a[i][j];

	p[0] = 1;
	fer (mask, 1, 1<<maxn)
	{
		rep (i, n) if (mask >> i & 1)
		{
			int tmask = mask ^ (1 << i);
			int cnt = 1;
			rep (j, n) if (!(mask >> j & 1)) cnt++;
			double prob = 1.0 / (cnt * (cnt-1) / 2);
			rep (j, n) if (!(mask >> j & 1))
				p[mask] += p[tmask] * prob * a[j][i];
		}
	}

	cout << fixed << setprecision (8);
	rep (i, n) cout << p[(1<<n)-1-(1<<i)] << ' ';
	cout << endl;

	{ int _; cin >> _; return 0; }
}
