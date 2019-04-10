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

const int maxn = 100000 + 100;

int n;
ll k;
int a[maxn];
int res, resv;

int main()
{
	ios::sync_with_stdio (false);
	cin >> n >> k;
	rep (i, n) cin >> a[i];
	sort (a, a + n);
	res = 1, resv = a[0];

	int p = 0;
	ll sum = 0;
	fer (i, 1, n)
	{
		sum += (i - p) * (ll)(a[i] - a[i-1]);
		while (sum > k)
		{
			sum -= a[i] - a[p];
			p++;
		}
		if (i - p + 1 > res)
			res = i - p + 1, resv = a[i];
	}
	cout << res << ' ' << resv << endl;
	
	{ int _; cin >> _; }
	return 0;
}
