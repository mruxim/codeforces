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

int n, k, l, r, sall, sk;
int a[1111];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n >> k >> l >> r >> sall >> sk;

	rep (i, n) a[i] = l;
	int tall = n*l, tk = k*l;

	int p = 0;
	while (tall < sall || tk < sk)
	{
		if (p >= k && sk - tk == sall - tall) { p = 0; continue; }
		a[p]++;
		tall++;
		if (p < k) tk++;
		p++;
		if (p == n) p = 0;
	}

	rep (i, n) cout << a[i] << ' ';
	cout << endl;

	{ int _; cin >> _; return 0; }
}
