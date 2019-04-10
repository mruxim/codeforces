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

int n, m;
long long a[maxn];
long long s;

int main()
{
	ios::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> a[i];
	cin >> m;
	while (m--)
	{
		int w, h;
		cin >> w >> h;
		w = min (w, n) - 1;
		cout << max (s, a[w]) << endl;
		s = max (s, a[w]) + h;
	}

	{ int _; cin >> _; return 0; }
}
