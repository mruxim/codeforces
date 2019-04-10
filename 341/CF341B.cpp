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

int n;
int a[maxn];
int dp[maxn];
int last[maxn];


int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> a[i], a[i]--;

	memset (last, -1, sizeof last);

	rep (i, n)
	{
		dp[i] = 1;
		if (last[1] != -1 && a[last[1]] < a[i])
		{
			int lo = 1, hi = n;
			while (hi - lo > 1)
			{
				int md = (lo + hi) / 2;
				if (last[md] != -1 && a[last[md]] < a[i])
					lo = md;
				else
					hi = md;
			}
			dp[i] = lo + 1;
		}
		if (last[dp[i]] == -1 || a[last[dp[i]]] > a[i])
			last[dp[i]] = i;
	}

	cout << *max_element (dp, dp+n) << endl;

	{ int _; cin >> _; return 0; }
}
