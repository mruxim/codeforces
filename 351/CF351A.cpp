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

int main()
{
	ios_base::sync_with_stdio (false);

	int n;
	cin >> n;

	double sum = 0, x;
	int cnt = 0;
	rep (i, 2*n) cin >> x, sum += fmod (x, 1), cnt += fmod (x, 1) < 1e-5;
	sum = -sum;
	rep (i, n-cnt) sum = sum+1;
	double ans = abs (sum);
	fer (i, max (n-cnt, 0), n)
		sum = sum+1, ans = min (ans, abs (sum));

	cout << fixed << setprecision (3) << ans << endl;

	{ int _; cin >> _; return 0; }
}
