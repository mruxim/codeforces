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

const int maxn = 100000 + 100;

int n;
int a[maxn];

int main()
{
	ios::sync_with_stdio (false);

	cin >> n;
	if (n&1)
	{
		int k = n-1, p = 0;
		while (k >= 0) a[p++] = k, k -= 2;
		k = n-2;
		while (k >= 0) a[p++] = k, k -= 2;
		rep (i, n) cout << i << ' '; cout << endl;
		rep (i, n) cout << a[i] << ' '; cout << endl;
		rep (i, n) cout << (i+a[i])%n << ' '; cout << endl;
	}
	else
		cout << -1 << endl;

	{ int _; cin >> _; return 0; }
}
