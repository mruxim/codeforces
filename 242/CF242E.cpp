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

constexpr int SL (int n) { return n > 1 ? SL ((n+1) / 2) * 2 : 1; }

const int maxn = SL (100 * 1000);

int n, on, m;
int change[2*maxn];
int sum[2*maxn][22];

void update (int v)
{
	if (v < 1 || v >= n) return;
	int sz = n / SL(v+1);
	rep (i, 22)
		sum[v][i] = ((change[2*v] >> i & 1) ? sz-sum[2*v][i] : sum[2*v][i]) + ((change[2*v+1] >> i & 1) ? sz-sum[2*v+1][i] : sum[2*v+1][i]);
}

void doxor (int l, int r, int x)
{
	for (l += n, r += n; l; l /= 2, r /= 2)
	{
		#define twopower(p) ((p&(p-1))==0)
		if (!twopower (r)) update (r);
		if (!twopower (l)) update (l-1);
		if (l < r)
		{
			if (l & 1) change[l++] ^= x,
			if (r & 1) change[--r] ^= x,
		}
	}
}

ll getsum (int l, int r)
{
	for (l += n, r += n; l; l /= 2, r /= 2)
	{
		#define twopower(p) ((p&(p-1))==0)
		if (!twopower (r)) update (r);
		if (!twopower (l)) update (l-1);
		if (l < r)
		{
			if (l & 1) change[l++] ^= x,
			if (r & 1) change[--r] ^= x,
		}
	}
}

int main()
{
	ios::sync_with_stdio (false);

	cin >> n; on = n; n = SL(n);
	rep (i, on)
	{
		int x;
		cin >> x;
		doxor (i, i, x);
	}

	cin >> m;
	rep (z, m)
	{
		int t;
		cin >> t;
		if (t == 1)
		{
			int l, r;
			cin >> l >> r; l--;
			cout << getsum (l, r) << endl;
		}
		else
		{
			int l, r, x;
			cin >> l >> r >> x; l--;
			doxor (l, r, x);
		}
	}


	{ int _; cin >> _; }
	return 0;
}
