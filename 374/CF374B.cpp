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

	string s;
	cin >> s;
	int n = sz(s);
	int cur = 0;
	ll ans = 1;
	rep (i, n)
	{
		if (i+1 < n && (s[i]-'0') + (s[i+1]-'0') == 9) { cur++; }
		else ans *= ((cur % 2 == 0) ? cur/2 + 1 : 1), cur = 0;
	}
	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
