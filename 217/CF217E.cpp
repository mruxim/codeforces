// .... .... .... !

#include <iostream>
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
#define sz(x) (int((x).size()))
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxk = 3*1000000 + 100;
const int maxn = 5000 + 10;

int s[maxk];
int l[maxn], r[maxn];
int _prev[maxk], _next[maxk], *prev = _prev + 5, *next = _next + 5;
char f[maxk];

void solve (int n, int k)
{
	if (n == 0)
	{
		rep (i, k) f[k] = s[k], prev[i] = i-1, next[i] = i+1;
		prev[0] = next[k-1] = -1;
		return;
	}

	int L = l[n-1], R = r[n-1], len = R - L;

	if (R >= k) { solve (n-1, k); return; }
	if (R + len < k)
	{
		solve (n-1, k - len);
		// find L-th element, then R-th, then copy
	}
}

int main()
{
	int k, n;

	cin >> s;
	cin >> k >> n;
	rep (i, n) cin >> l[i] >> r[i], l[i]--;

	solve (n, k);

	{ int _; cin >> _; }
	return 0;
}
