// .... .... .... !

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
#define mp make_pair
#define all(X) (X).begin(),(X).end()

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100 + 10;

int n, d;
int a[maxn];
int sx, sy, x[maxn], y[maxn];
int id[maxn];
int dp[maxn];

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> d; n--;
	rep (i, n-1) cin >> a[i];
	cin >> sx >> sy;
	rep (i, n) cin >> x[i] >> y[i], x[i] -= sx, y[i] -= sy;

	if (x[n-1] < 0) rep (i, n) x[i] *= -1;
	if (y[n-1] < 0) rep (i, n) y[i] *= -1;

	rep (i, n) id[i] = i;
	sort (id, id+n-1, [](const int &a, const int &b) { return (x[a] < x[b]) || (x[a] == x[b] && y[a] < y[b]); });

	rep (i, n)
	{
		rep (j, i)
			if (0 <= x[id[j]] && x[id[j]] <= x[id[i]] && 0 <= y[id[j]] && y[id[j]] <= y[id[i]])
				dp[i] = max (dp[i], dp[j]);
		dp[i] += a[id[i]];
	}

	cout << (x[n-1] + y[n-1]) * d - dp[n-1] << endl;

	{ int _; cin >> _; return 0; }
}
