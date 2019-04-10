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

const int MAXn = 50000 + 555;

int n, k;
int ans;
vi a[MAXn];
bool mark[MAXn];
int c[MAXn][500+5];

void dfs (int x)
{
	mark[x] = 1;
	c[x][0] = 1;
	fch (it, a[x])
	{
		int y = *it;
		if (mark[y]) continue;
		dfs (y);
		rep (i, k) ans += c[y][k-i-1] * c[x][i];
		rep (i, k) c[x][i+1] += c[y][i];
	}
}

int main()
{
	cin >> n >> k;
	rep (i, n-1)
	{
		int x, y;
		cin >> x >> y; x--, y--;
		a[x].pb(y), a[y].pb(x);
	}
	if (k == 1) { cout << n-1 << endl; return 0; }

	dfs (0);

	cout << ans << endl;
	{ int _; cin >> _; }
}
