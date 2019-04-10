// .... .... .....!
// P..... C.....!

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

int n, d;
bitset<55*10000> b (1);

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> d;
	rep (i, n) { int x; cin >> x; b |= b << x; }

	int cur = 0, dis = -1;
	for (int old = -1; old != cur; dis++)
		for (int i = old = cur, ed = cur+d; i <= ed; i++)
			if (b.test (i)) cur = i;

	cout << cur << ' ' << dis << endl;

	{ int _; cin >> _; return 0; }
}
