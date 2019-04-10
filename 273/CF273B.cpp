// .... .... .... !

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>

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

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n;
pii p[2*maxn];
int m;
long long ans = 1;

int main()
{
	ios::sync_with_stdio (false);

	int x;
	cin >> n;
	rep (i, n) cin >> x, p[i] = pii (x, i);
	rep (i, n) cin >> x, p[i+n] = pii (x, i);
	cin >> m;

	sort (p, p+2*n);

	rep (i, 2*n)
	{
		int j = i+1, c = 0;
		while (j < 2*n && p[j].X == p[i].X) c += ((p[j].Y == p[j-1].Y) ? 1 : 0), j++;
		rep (k, j-i)
			if (k%2 && c)
				ans = ans * ((k+1)/2) % m, c--;
			else
				ans = ans * (k+1) % m;
		i = j-1;
	}

	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
