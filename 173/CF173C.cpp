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

const int MAXn = 500 + 10;

int n, m;
int a[MAXn][MAXn];
int r[MAXn][MAXn], c[MAXn][MAXn];
int f[MAXn][MAXn];
int ans = -(1<<30);

int main()
{
	ios::sync_with_stdio (false);
	cin >> n >> m;
	rep (i, n) rep (j, m) cin >> a[i][j];

	rep (i, n) rep (j, m) r[i][j+1] = r[i][j] + a[i][j], c[i+1][j] = c[i][j] + a[i][j];

#define R(x,y,z) (r[x][z] - r[x][y])
#define C(x,y,z) (c[z][x] - c[y][x])

	rep (i, n-2) rep (j, m-2)
		f[i][j] = a[i][j];
	for (int k = 5; k <= min (n, m); k += 4)
		rep (i, n-k+1) rep (j, m-k+1)
		{
			f[i][j] = f[i+2][j+2] + R(i,j,j+k) + C(j+k-1,i+1,i+k) + R(i+k-1,j,j+k-1) + C(j,i+2,i+k-1) + a[i+2][j+1];
			cmx (ans, f[i][j]);
		}
	rep (i, n-2) rep (j, m-2)
	{
		f[i][j] = a[i][j] + a[i][j+1] + a[i][j+2] + a[i+1][j+2] + a[i+2][j+2] + a[i+2][j+1] + a[i+2][j];
		cmx (ans, f[i][j]);
	}

	for (int k = 7; k <= min (n, m); k += 4)
		rep (i, n-k+1) rep (j, m-k+1)
		{
			f[i][j] = f[i+2][j+2] + R(i,j,j+k) + C(j+k-1,i+1,i+k) + R(i+k-1,j,j+k-1) + C(j,i+2,i+k-1) + a[i+2][j+1];
			cmx (ans, f[i][j]);
		}

	cout << ans << endl;
	{ int _; cin >> _; }
}
