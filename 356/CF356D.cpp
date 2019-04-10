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

const int maxn = 70000 + 100;

int n, s;
pii a[maxn];
int last[maxn];
int child[maxn];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> s;
	rep (i, n) cin >> a[i].X, a[i].Y = i;

	sort (a, a+n);

	if (s < a[n-1].X) { cout << -1 << endl; return 0; }

	memset (last, -1, sizeof last); last[0] = -9;

	ll sum = 0;
	rep (i, n-1) sum += a[i].X;

//	int lp = s;

	rep (i, n-1)
	{
		sum -= a[i].X;
		int zz = (int)max ((ll)a[i].X, s-a[n-1].X - sum);
//		rof (w, min (lp+a[i].X, s-a[n-1].X)+1, zz)
		rof (w, s-a[n-1].X+1, zz)
			if (last[w] == -1 && last[w - a[i].X] != -1)
//				last[w] = i, lp = max (lp, w);
				last[w] = i;
		if (last[s - a[n-1].X] != -1) break;
	}

	if (last[s-a[n-1].X] == -1) { cout << -1 << endl; return 0; }

	memset (child, -1, sizeof child);

	int val = s - a[n-1].X, pos = n-1;
	while (1)
	{
		for ( ; pos-1 > last[val] && pos-1 >= 0; pos--)
			child[a[pos].Y] = a[pos-1].Y;
		pos--;
		if (val == 0) break;
		val -= a[last[val]].X;
	}

	sort (a, a+n, [](pii A, pii B) { return A.Y < B.Y; } );

	rep (i, n)
	{
		if (child[i] == -1)
			cout << a[i].X << ' ' << 0 << endl;
		else
			cout << a[i].X - a[child[i]].X << ' ' << 1 << ' ' << child[i]+1 << endl;
	}

	{ int _; cin >> _; return 0; }
}
