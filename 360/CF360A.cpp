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

const int maxn = 5000 + 100;
const int maxm = 5000 + 100;

int n, m;
int t[maxm], l[maxm], r[maxm], d[maxm];
ll a[maxn], b[maxn];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, m) cin >> t[i] >> l[i] >> r[i] >> d[i], l[i]--;

	rep (i, n) a[i] = 1LL<<60;

	rof (i, m, 0)
	{
		if (t[i] == 2) fer (j, l[i], r[i]) a[j] = min (a[j], (ll)d[i]);
		else fer (j, l[i], r[i]) a[j] -= d[i];
	}

	copy (a, a+n, b);

	bool ok = true;

	rep (i, m)
	{
		if (t[i] == 2)
		{
			ll mx = -(1LL<<60);
			fer (j, l[i], r[i]) mx = max (mx, (ll)b[j]);
			if (mx != d[i]) { ok = false; break; }
		}
		else
			fer (j, l[i], r[i]) b[j] += d[i];
	}

	if (ok)
	{
		cout << "YES" << endl;
		rep (i, n) cout << min (a[i], (ll)1e9) << ' ';
		cout << endl;
	}
	else
		cout << "NO" << endl;

	{ int _; cin >> _; return 0; }
}
