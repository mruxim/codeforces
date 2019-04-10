// .... .... .... !

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
#define mp make_pair
#define all(X) (X).begin(),(X).end()

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

int n, k;

int main()
{
	ios::sync_with_stdio (false);

	cin >> n >> k;
	rep (i, k)
	{
		fer (j, 1, n+1)
		{
			if (n-j <= (1 << i)) cout << n << ' ';
			else if (n-j >= (1 << (i+1))) cout << j << ' ';
			else cout << n - (n-j - (1 << i)) << ' ';
		}
		cout << endl;
	}
	{ int _; cin >> _; return 0; }
}
