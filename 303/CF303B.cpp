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
#define mp make_pair
#define all(X) (X).begin(),(X).end()

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

int n, m, x, y, a, b;

int gcd (int p, int q) { return p ? gcd (q%p, p) : q; }

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m >> x >> y >> a >> b;

	int gab = gcd (a, b); a /= gab, b /= gab;

	int k = min (n/a, m/b);
	a *= k, b *= k;

	int x2 = x + a/2, y2 = y + b/2;

	x2 -= max (0, x2-n);
	y2 -= max (0, y2-m);
	x2 += max (0, a-x2);
	y2 += max (0, b-y2);

	cout << x2-a << ' ' << y2-b << ' ' << x2 << ' ' << y2 << endl;

	{ int _; cin >> _; return 0; }
}
