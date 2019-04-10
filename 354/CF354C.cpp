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

const int maxn = 3*100000 + 1000;
const int maxa = 1000000 + 1000;

int n, k;
int a[maxn];
int e[2*maxa], s[2*maxa];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> k;
	rep (i, n) cin >> a[i], e[a[i]] = 1;

	fer (i, 1, maxa) s[i] = s[i-1] + e[i];

	int ans = 1;
	fer (i, 2, maxa)
	{
		if (s[i-1] > 0) break;
		if (i-1 <= k)
		{
			ans = i;
			continue;
		}
		bool ok = true;
		for (int j = i; j < maxa; j += i)
			if (s[min (j+i-1, maxa-1)] - s[min (j+k, maxa-1)] > 0)
			{
				ok = false;
				break;
			}
		if (ok) ans = i;
	}

	cout << ans << endl;	

	{ int _; cin >> _; return 0; }
}
