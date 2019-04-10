// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <bitset>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define pb push_back
#define mkp make_pair
#define all(X) (X).begin(),(X).end()

#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 5000 + 100;
const int maxm = 100 + 10;

int n, m;
int c[maxm];
int p[maxn];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> m;
	rep (i, n)
	{
		int x;
		cin >> x; x--;
		c[x]++;
	}

	int prv = -1, fst = -1;

	rep (i, n)
	{
		int cur = -1;
		rep (j, m) if (j != prv && c[j] > 0 && (cur == -1 || (c[j] > c[cur] || (c[j] == c[cur] && j == fst)))) cur = j;
		if (cur == -1) cur = prv;
		c[cur]--;
		p[i] = cur;
		prv = cur;
		if (i == 0) fst = cur;
	}

	int ans = 0;

	rep (i, n) if (p[i] != p[(i+1)%n]) ans++;

	cout << ans  << endl;
	rep (i, n) cout << p[i]+1 << ' ' << p[(i+1)%n]+1 << endl;

	{ int _; cin >> _; return 0; }
}
