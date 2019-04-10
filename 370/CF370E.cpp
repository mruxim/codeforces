// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

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

const int maxn = 200000 + 100;

int n;
int a[maxn], b[maxn];

inline bool ok (int sp, int t)
{
	return 2*t <= sp && sp <= 5*t;
}

void go (int cur)
{
	
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> a[i];
	copy (a, a+n, b);

	a[0] = a[1] = 1;
	int prv = 1, pos = 0;
	fer (i, 1, n) if (a[i] != 0)
	{
		if (prv > a[i])
		{
			cout << -1 << endl;
			goto hell;
		}
		if (prv == a[i])
		{
			if (i - pos + 1 > 5)
			{
				cout << -1 << endl;
				goto hell;
			}
			fer (j, pos+1, i) a[j] = prv;
		}
		prv = a[i];
		pos = i;
	}

	a[n-1] = max (a[n-1], a[n-2]);
	a[n-2] = a[n-1];

	l[1] = r[1] = 0;
	prv = 1;

	rep (i, n) if (a[i] != 0 && a[i] != prv)
	{
		int cur = a[i];
		r[cur] = i;
		int j;
		for (j = i; j < n && a[j] == cur; j++) l[cur] = j-5+1;

		int st = r[prv];
		while (a[st] == prv) st++;
		st = max (st, l[prv] + 2);
		int ed = st;
		while (ed <= r[prv] + 5 && a[ed] == 0) ed++;
		ed--;

		st = max (st, l[cur] - 5 * (cur - prv - 1));
		ed = min (ed, r[cur] - 2 * (cur - prv - 1));
		if (st > ed) { cout << -1 << endl; goto hell; }

		from[cur] = st;
		prv = cur;
	}

	go (prv);

hell:;
	{ int _; cin >> _; return 0; }
}
