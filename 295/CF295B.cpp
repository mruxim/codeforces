// .... .... .... !

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

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define X first
#define Y second
#define pb push_back

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 500 + 50;

int n;
int a[maxn][maxn];
int x[maxn];
int d[maxn][maxn];
bool mark[maxn];
ll ans[maxn];

int main()
{
	ios::sync_with_stdio (false);

	cin >> n;
	rep (i, n) rep (j, n) cin >> d[i][j];
	rep (i, n) cin >> x[i], x[i]--; reverse (x, x+n);

	rep (kk, n)
	{
		ll s = 0;
		int k = x[kk];
		mark[k] = 1;
		rep (i, n) rep (j, n) if (i != j)
		{
			d[i][j] = min (d[i][j], d[i][k] + d[k][j]);
			if (mark[i] && mark[j])
				s += d[i][j];
		}
		ans[kk] = s;
	}

	rep (i, n) cout << ans[n-1-i] << ' '; cout << endl;

	{ int _; cin >> _; return 0; }
}
