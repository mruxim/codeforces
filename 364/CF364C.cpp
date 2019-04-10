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

const int maxn = 5000 + 100;

int n;
int cnt[555];
vector<int> P({2,3,5,7,11,13});
vector<int> a;

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	a.pb (1);

	for (int p: P)
	{
		for (int i = 0, t = sz(a); i < t; i++)
		{
			int cur = a[i] * p;
			while (cur <= 2*n*n) a.pb (cur), cur = cur * p;
		}
		if (sz(a) >= n) break;
	}
	int bad = sz(a) - n;
	for (int p: P)
	{
		rep (i, sz(a)) if (a[i] % p == 0) cnt[p]++;
		if (cnt[p] == 0) break;
		rep (i, sz(a))
		{
			if (cnt[p] == (n+1)/2) break;
			if (!bad) break;
			if (a[i] != 1 && a[i] == -1) continue;
			int cur = a[i];
			while (cur % p == 0) cur /= p;
			if (cur == 1) a[i] = -1, bad--, cnt[p]--;
		}

		if (!bad) break;
	}
	for (int p : P) for (int q: P) if (p < q)
	{
		if (min (cnt[p], cnt[q]) == 0) break;
		rep (i, sz(a))
		{
			if (min (cnt[p], cnt[q]) == (n+1)/2) break;
			if (!bad) break;
			if (a[i] != 1 && a[i] == -1) continue;
			int cur = a[i];
			while (cur % p == 0) cur /= p;
			while (cur % q == 0) cur /= q;
			if (cur == 1) a[i] = -1, bad--, cnt[p]--, cnt[q]--;
		}

		if (!bad) break;
	}
	for (int p: P) for (int q: P) if (p < q) for (int r: P) if (q < r)
	{
		if (min (cnt[p], min (cnt[q], cnt[r])) == 0) break;
		rep (i, sz(a))
		{
			if (min (cnt[p], min (cnt[q], cnt[r])) == (n+1)/2) break;
			if (!bad) break;
			if (a[i] != 1 && a[i] == -1) continue;
			int cur = a[i];
			while (cur % p == 0) cur /= p;
			while (cur % q == 0) cur /= q;
			while (cur % r == 0) cur /= r;
			if (cur == 1) a[i] = -1, bad--, cnt[p]--, cnt[q]--, cnt[r]--;
		}

		if (!bad) break;
	}

	rep (i, sz(a)) if (a[i] != -1) cout << a[i] << ' '; cout << endl;

	{ int _; cin >> _; return 0; }
}
