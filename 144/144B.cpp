// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fer(i, x, n) for (int i = (x), _n = (n); i <= _n; i++)
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

inline int sqr (int x) { return x*x; }

////////////////////////////////////////////////

const int MAXn = 1000+9;

int x1, y1, x2, y2;
int n;
int x[MAXn], y[MAXn], r[MAXn];

int main()
{
	cin >> x1 >> y1 >> x2 >> y2;
	cin >> n;
	rep (i, n) cin >> x[i] >> y[i] >> r[i], r[i] *= r[i];
	if (x1 > x2) swap (x1, x2);
	if (y1 > y2) swap (y1, y2);

	int s = 0;
	fer (i, x1, x2)
	{
		rep (j, n) if (sqr (x[j]-i) + sqr (y[j]-y1) <= r[j]) { s++; break; }
		rep (j, n) if (sqr (x[j]-i) + sqr (y[j]-y2) <= r[j]) { s++; break; }
	}
	fer (i, y1+1, y2-1)
	{
		rep (j, n) if (sqr (x[j]-x1) + sqr (y[j]-i) <= r[j]) { s++; break; }
		rep (j, n) if (sqr (x[j]-x2) + sqr (y[j]-i) <= r[j]) { s++; break; }
	}
	cout << 2*(x2-x1+y2-y1)-s << endl;
	{ int _; cin >> _; }
}
