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

int main()
{
	ios_base::sync_with_stdio (false);

	int n, m, i, j, a, b;
	cin >> n >> m >> i >> j >> a >> b;
	if ((i+a > n && i-a < 1) || (j+b > m && j-b < 1))
	{
		if ((i==1||i==n) && (j==1||j==m))
			cout << 0 << endl;
		else
			cout << "Poor Inna and pony!" << endl;
		return 0;
	}
	int ans = 1<<29;
	if ((i-1) % a == 0)
	{
		if ((j-1) % b == 0 && (i-1) / a % 2 == (j-1) / b % 2)
			ans = min (ans, max ((i-1) / a, (j-1) / b));
		if ((m-j) % b == 0 && (i-1) / a % 2 == (m-j) / b % 2)
			ans = min (ans, max ((i-1) / a, (m-j) / b));			
	}
	if ((n-i) % a == 0)
	{
		if ((j-1) % b == 0 && (n-i) / a % 2 == (j-1) / b % 2)
			ans = min (ans, max ((n-i) / a, (j-1) / b));
		if ((m-j) % b == 0 && (n-i) / a % 2 == (m-j) / b % 2)
			ans = min (ans, max ((n-i) / a, (m-j) / b));			
	}
	if (ans < (1<<29))
		cout << ans << endl;
	else
		cout << "Poor Inna and pony!" << endl;

	{ int _; cin >> _; return 0; }
}
