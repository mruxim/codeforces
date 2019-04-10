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

int n, l, r, ql, qr;
int w[maxn];

int solve ()
{
	int p = 0, q = n-1;
	int cur = 0;
	int ret = 1<<30;
	int sum = 0;

	rep (i, n) sum += w[i];

	rep (i, n)
	{
		if (i % 2 == 0)
		{
			cur += w[p] * l;
			sum -= w[p];
			p++;
			ret = min (ret, cur + (q-p+1) * ql + sum * l);
		}
		else
		{
			cur += w[q] * r;
			sum -= w[q];
			q--;
			ret = min (ret, cur + (q-p+1) * qr + sum * r);
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> l >> r >> ql >> qr;
	rep (i, n) cin >> w[i];

	int ans = solve ();

	reverse (w, w+n);
	swap (l, r);
	swap (ql, qr);

	ans = min (ans, solve());

	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
