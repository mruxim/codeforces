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

const int maxn = 1000000 + 100;

int n;
int a[2*maxn];

int main()
{
	ios::sync_with_stdio (false);

	cin >> n;
	rep (i, n) a[i] = i;

	int s = 0;
	fer (k, 2, n+1)
	{
		int m = n / k * k;
		if (n % k) a[s+n] = a[s+m];
		while (m) a[s+m] = a[s+m-k], m -= k;
		s++;
	}
	rep (i, n) cout << a[s+i]+1 << ' ';
	cout << endl;

	{ int _; cin >> _; return 0; }
}
