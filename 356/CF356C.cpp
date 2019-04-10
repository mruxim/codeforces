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
int a[maxn];
int cnt[10];
int sum;

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n)
	{
		cin >> a[i];
		sum += a[i];
	}

	if (sum < 3 || sum == 5) cout << -1 << endl;
	else
	{
		sort (a, a+n);
		reverse (a, a+n);
		while (a[n-1] == 0) n--;

		int ans = 999999999;

		int cur = 0;
		int lack = 0;
		rep (i, n)
		{
			cur += a[i];
			lack += max(0, 3 - a[i]);
			if (!((i+1) * 3 <= sum && sum <= (i+1) * 4)) continue;

			ans = min (ans, sum - cur + max(0, lack - (sum - cur)));
		}
		cout << ans << endl;
	}

	{ int _; cin >> _; return 0; }
}
