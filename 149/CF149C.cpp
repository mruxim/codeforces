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

const int maxn = 200000 + 100;

int n;
pii a[maxn];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> a[i].X, a[i].Y = i;

	sort (a, a+n);
	reverse (a, a+n);

	int diff = 0;
	vector<int> t1, t2;

	for (int i = 0; i+1 < n; i += 2)
	{
		if (diff > 0) t1.pb (a[i+1].Y), t2.pb (a[i].Y), diff += a[i+1].X - a[i].X;
		else t1.pb (a[i].Y), t2.pb (a[i+1].Y), diff += a[i].X - a[i+1].X;
	}

	if (n%2)
	{
		if (diff > 0) t2.pb (a[n-1].Y);
		else t1.pb (a[n-1].Y);
	}

	cout << sz(t1) << endl;
	rep (i, sz(t1)) cout << t1[i]+1 << ' ';
	cout << endl;
	cout << sz(t2) << endl;
	rep (i, sz(t2)) cout << t2[i]+1 << ' ';
	cout << endl;

	{ int _; cin >> _; return 0; }
}
