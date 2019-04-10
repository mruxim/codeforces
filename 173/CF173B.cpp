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

const int MAXn = 1000 + 100;

int n, m;
char a[MAXn][MAXn];
int q[2*MAXn], h, t;
int d[2*MAXn];

int main()
{
	cin >> n >> m;
	rep (i, n) cin >> a[i];

	memset (d, -1, sizeof d);

	q[t++] = 0;
	d[0] = 0;

	while (h < t)
	{
		int x = q[h++];
		if (x < n)
			rep (i, m) if (a[x][i] == '#' && d[n+i] == -1)
				d[n+i] = d[x] + 1, q[t++] = n+i;
		if (x >= n)
			rep (i, n) if (a[i][x-n] == '#' && d[i] == -1)
				d[i] = d[x] + 1, q[t++] = i;
	}
	cout << d[n-1] << endl;
	{ int _; cin >> _; }
}
