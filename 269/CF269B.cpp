// .... .... .... !

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

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

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 5000 + 100;

int n, m;
pair <double, int> p[maxn];
int dp[maxn];

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, n) cin >> p[i].Y >> p[i].X;
	sort (p, p+n);

	rep (i, n)
	{
		dp[i] = 1;
		rep (j, i)
			if (p[j].Y <= p[i].Y)
				dp[i] = max (dp[i], dp[j] + 1);
	}

	cout << n - *max_element (dp, dp + n) << endl;

	{ int _; cin >> _; }
	return 0;
}
