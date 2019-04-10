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

const int maxn = 2000 + 100;

int n, k;
int a[maxn];
int d[maxn];

bool check (ll v)
{
	rep (i, n)
	{
		d[i] = i;
		rof (j, i, 0)
		{
			if (d[i] <= i-j-1) break;
			if (abs(a[i]-a[j]) <= v*(ll)(i-j)) d[i] = min (d[i], d[j] + i-j-1);
		}
	}
	rep (i, n) if ((n-i-1) + d[i] <= k) return true;
	return false;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> k;
	rep (i, n) cin >> a[i];

	int lo = -1, hi = 2e9+5;
	while (hi - lo > 1)
	{
		int md = (lo + (ll)hi) / 2;
		if (check (md)) hi = md;
		else lo = md;
	}
	cout << hi << endl;

	{ int _; cin >> _; return 0; }
}
