// .... .... .... !

#include <iostream>
#include <iomanip>
#include <fstream>

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

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

int n;
int a[111111];
int e[1111111];
int c[111111];

int main()
{
	ios::sync_with_stdio (false);
	cin >> n;
	e[0] = 1;
	rep (i, n) cin >> a[i], b[i+1] = a[i] ^ b[i], e[b[i+1]]++;
	sort (b, b+n+1);
	ll ans = 0;
//	rep (i, n+1)
//		ans += n+1 - (upper_bound (c, c + n+1, b[i]) - lower_bound (c, c + n+1, b[i]));
//	cout << ans << endl;
	{ int _; cin >> _; }
	return 0;
}
