// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <iomanip>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fer(i, x, n) for (int i = (x), _n = (n); i < _n; i++)
#define rof(i, n, x) for (int i = (n), _x = (x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define cmx(a, b) (a = max(a,b))
#define cmn(a, b) (a = min(a,b))
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

////////////////////////////////////////////////

const int maxN = 20 + 2;

__int128 eee;

int n, nf, ne, ns;
double rf, re, rs;
double df, de;

double a[maxN], b[maxN];
double fd[maxN], ed[maxN];
double dp[maxN][maxN];

double solve (int mask)
{
	int k = 0, p = 0;
	rep (i, n) if ((mask >> i) & 1)
		a[k] = (i>>1) - rs, b[k] = (i>>1) + rs, k++;

	rep (i, n)
	{
		fd[i] = df*2*rf;
		ed[i] = de*2*re;
	}

	rep (i, n) if (!((mask >> i) & 1))
	{
		double x, y;

		x = (i>>1) - rf, y = (i>>1) + rf;
		rep (j, k)
			fd[p] += df * max (0., (min (y, b[j]) - max (x, a[j])));

		x = (i>>1) - re, y = (i>>1) + re;
		rep (j, k)
			ed[p] += de * max (0., (min (y, b[j]) - max (x, a[j])));

		p++;
	}

	double ret = 0.0;

	fer (i, 1, p+1)
		rep (j, i+1)
		{
			if (j <= i-1)
				dp[i][j] = dp[i-1][j] + ed[i-1];
			else
				dp[i][j] = 0;
			if (j)
				cmx (dp[i][j], dp[i-1][j-1] + fd[i-1]);
			if (i == p && j == nf)
				cmx (ret, dp[i][j]);
		}

//	cerr << p << ' ' << mask << ' ' << ret << endl;
	return ret;
}

int main()
{
	cin >> nf >> ne >> ns;
	cin >> rf >> re >> rs;
	cin >> df >> de;

	rf = sqrt (rf*rf - 1);
	re = sqrt (re*re - 1);
	rs = sqrt (rs*rs - 1);

	if (rf < 1.) nf = 0;
	if (re < 1.) ne = 0;
	if (rs < 1.) ns = 0;

	n = nf + ne + ns;


	double ans = 0;

	cout << fixed << setprecision (8);

	rep (i, 1 << n) if (__builtin_popcount (i) == ns)
		cmx (ans, solve (i));

	cout << ans << endl;

	{ int _; cin >> _; }
}
