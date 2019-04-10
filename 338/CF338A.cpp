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

const int mod = 1000000000 + 9;

int n, k, m;
int ans = 0;

int pw (int x, int y)
{
	if (y == 0) return 1;
	int r = pw (x, y/2);
	r = r * (ll)r % mod;
	if (y & 1)
		r = r * (ll) x % mod;
	return r;
}

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m >> k;
	int x = n / k;
	int z = min (m, n % k);
	ans += z;
	n -= z, m -= z;

	if (m == 0) { cout << ans << endl; return 0; }

	int rem = n - m;
	if (rem >= x)
		cout << ans + m << endl;
	else
	{
		int d = x - rem;
		int tmp = pw (2, d);
		tmp = tmp-1;
		tmp *= 2;
		tmp %= mod;
		tmp = tmp * (ll)k % mod;
		m -= d * k;
		ans = ((ans + tmp) % mod + m) % mod;
		cout << ans << endl;
	}

	{ int _; cin >> _; return 0; }
}
