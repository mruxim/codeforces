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
#include <bitset>

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
vector<int> dv[maxn];
int mx[maxn];

int main()
{
	ios_base::sync_with_stdio (false);

	for (int i = 2; i < maxn; i++)
		for (int j = i; j < maxn; j += i)
			dv[j].pb (i);

	cin >> n;
	rep (i, n) cin >> a[i];

	int ans = 0;

	rof (i, n, 0)
	{
		int best = 0;
		for (int k: dv[a[i]]) best = max (best, mx[k]);
		best++;
		for (int k: dv[a[i]]) mx[k] = max (mx[k], best);
		ans = max (ans, best);
	}

	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
