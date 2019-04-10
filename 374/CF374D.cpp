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

const int maxn = 1000000 + 100;

int n, m;
int a[maxn];
int f[maxn];
int w[maxn], p;

int add (int x, int v) { for (x++; x < maxn; x += x&-x) f[x] += v; }
int get (int x) { int r = 0; for (x++; x; x -= x&-x) r += f[x]; return r; }

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, m) cin >> a[i], a[i] -= i;

	int tot = 0;
	rep (z, n)
	{
		int x;
		cin >> x;
		if (x == 0 || x == 1)
		{
			w[p] = x, add (p, 1), tot++, p++;
			continue;
		}

		int lo = -1, hi;
		rep (i, m)
		{
			if (a[i] > tot) break;
			hi = p;
			while (hi-lo > 1)
			{
				int md = (lo+hi) / 2;
				if (get (md) >= a[i]) hi = md;
				else lo = md;
			}
			add (hi, -1); tot--;
			lo = hi;
		}
	}

	int cur = 0;
	vector<int> ans;
	rep (i, p) if (get (i) > cur)
		cur++, ans.pb (w[i]);

	if (sz(ans) == 0)
		cout << "Poor stack!" << endl;
	else
	{
		rep (i, sz(ans)) cout << ans[i];
		cout << endl;
	}

	{ int _; cin >> _; return 0; }
}
