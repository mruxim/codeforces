// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>

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

const int MAXn = 1000 + 100;

int n, k;
int x[MAXn], y[MAXn];
int dist[MAXn][MAXn];
pii p[MAXn];

int gDist (int i, int j)
{
	return (x[i]-x[j]) * (x[i]-x[j]) + (y[i]-y[j]) * (y[i]-y[j]);
}

int main()
{
	cin >> n >> k;
	rep (i, n) cin >> x[i] >> y[i];
	rep (i, n) rep (j, n) dist[i][j] = gDist (i, j);

	rep (i, n)
	{
		p[i].Y = i;
		rep (j, n)
			p[i].X += dist[i][j];
	}
	rep (i, k)
	{
		sort (p + i, p + n);
		reverse (p + i, p + n);
		fer (j, i+1, n)
			p[j].X -= dist[p[j].Y][p[i].Y];
	}

	rep (i, k)
		cout << p[i].Y + 1 << ' ';
	cout << endl;
	{ int _; cin >> _; }
}
