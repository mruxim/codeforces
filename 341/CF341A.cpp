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

int n;
int a[111111];

ll gcd (ll x, ll y)
{
	return !x ? y : gcd (y % x, x);
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> a[i];

	a[n++] = 0;
	sort (a, a+n);

	ll sum = 0, tot = 0, cur = 0;
	rep (i, n) tot += a[i];

	fer (i, 1, n)
	{
	//	cerr << a[i] << ' ' << (a[i] * (ll)i - cur) << ' ' << (tot - cur - a[i] - a[i] * (ll)(n - i - 1)) << endl;
		sum += (a[i] * (ll)i - cur) + (tot - cur - a[i] - a[i] * (ll)(n-i-1));
		cur += a[i];
	}

	ll f = gcd (sum, n-1);

	cout << sum / f << ' ' << (n-1) / f << endl;

	{ int _; cin >> _; return 0; }
}
