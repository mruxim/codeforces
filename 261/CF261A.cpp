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

int m, n;
int q[maxn], a[maxn];

int main()
{
	ios::sync_with_stdio (false);

	cin >> m;
	rep (i, m) cin >> q[i];
	sort (q, q+m);

	cin >> n;
	rep (i, n) cin >> a[i];
	sort (a, a+n);
	reverse (a, a+n);
	
	int ans = 0;
	rep (i, n)
		if (i % (q[0] + 2) < q[0])
			ans += a[i];

	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
