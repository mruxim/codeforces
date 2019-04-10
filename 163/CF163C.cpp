// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

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

const int MAXn = 1000000 + 1000;

int n;
double l, v1, v2;
double a[4*MAXn];
double d;
double r[MAXn];

int main()
{
	cin >> n >> l >> v1 >> v2;
	rep (i, n) cin >> a[i];
	sort (a, a+n);
	fer (i, 1, n) a[i] -= a[0]; a[0] = 0;

	d = (double)n * v1 / (v1 + v2);
	rep (i, n) a[i+n] = a[i] + 2*l;
	printf ("%.10lf\n", (double)d);

	int p = 0, q = 0;
	double cs = 0;
	for (p = 0; a[p] < d; p++);
	rep (z, 2*n)
	{
		if (a[p] - d - cs > a[q] - cs)
			r[p-q] += (a[q] - cs) / (2*l), cs = a[q], q++;
		else
			r[p-q] += (a[p] - d - cs) / (2*l), cs = a[q] - d, p++;
	}
/*	rep (i, n)
	{
		cerr << i << endl;
		while (1) {
			long double x = a[i] - cs, y = a[p] - d - cs;
printf ("%d %.10lf %.10lf\n", p, x, y); if (p > 10) break;
			r[p-i] += min (x, y) / (2*l);
			cs += min (x, y);
			if (x < y) { break; }
			p++;
		}
	}
*/
	rep (i, n+1)
		printf ("%.10lf\n", r[i]);

	{ int _; cin >> _; }
}
