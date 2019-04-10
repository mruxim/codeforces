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
#define M first
#define V second.first
#define ID second.second

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef pair <int, pii> tri;

////////////////////////////////////////////////

const int MAXn = 100 * 1000 + 100;

int n, k, h;
tri a[MAXn];
double p[MAXn];
int r[MAXn];

bool check (double t)
{
	int f = k;
	rof (i, n, 0)
	{
		if (p[i] * f <= t) r[--f] = i;
		if (f == 0) break;
	}
	return f == 0;
}

int main()
{
	cin >> n >> k >> h;
	rep (i, n) cin >> a[i].M;
	rep (i, n) cin >> a[i].V;
	rep (i, n) a[i].ID = i+1;

	sort (a, a + n);
	rep (i, n) p[i] = 1.0 / a[i].V;

	double lo = 0, hi = 10e20;
	rep (z, 200)
	{
		double md = (lo + hi) / 2.;
		if (check (md))
			hi = md;
		else
			lo = md;
	}
	check (hi);

//	cout << hi * h << endl;
	rep (i, k) cout << a[r[i]].ID << ' ';
	cout << endl;

	{ int _; cin >> _; }
}
