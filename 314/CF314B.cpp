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

int b, d;
string a, c;
int n, m, tot;
int f[maxn][maxn];
ll p[maxn], q[maxn];
ll P[maxn], Q[maxn];
bool possible = true;
int ans = 0;
ll h = 0;

int main()
{
	ios::sync_with_stdio (false);

	cin >> b >> d;
	cin >> a;
	cin >> c;

	n = sz(a), m = sz(c);
	tot = n * b;
	memset (f, -1, sizeof f);
	rep (j, m)
	{
		bool ok = false;
		rep (i, n) if (a[i] == c[j])
		{
			int k = i+1;
			int lim = n+2;
			while (--lim && a[k%n] != c[(j+1)%m]) k++;
			f[i][j] = k;
			if (lim != 0) ok = true;
		}
		possible &= ok;
	}

	if (!possible) { cout << 0 << endl; goto end; }

	rep (i, n) if (a[i] == c[0])
	{
		int k = i;
		rep (j, m) p[i] = k, k += f[k%n][j] - k%n;
		q[i] = k;
	}
	rep (i, n) if (a[i] == c[0])
	{
		ll k = i;
		rep (j, 5000) P[i] = k + p[k%n] - k%n, k += q[k%n] - k%n;
		Q[i] = k;
	}

	while (a[h] != c[0]) h++;

	while (P[h%n] + h - h%n < tot)
	{
		ans += 5000;
		h = Q[h%n] + h - h%n;
	}
	while (p[h%n] + h - h%n < tot)
	{
		ans += 1;
		h = q[h%n] + h - h%n;
	}

	cout << ans / d << endl;

	end: ; { int _; cin >> _; return 0; }
}
