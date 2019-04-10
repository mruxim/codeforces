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

const int maxn = 4000 + 100;

int n;
int a;
string S;
int s[maxn];
int c[maxn*maxn], t;

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> a;
	cin >> S;
//	S = string (4000, '1');
	n = sz(S);
	rep (i, n) s[i+1] = S[i] - '0' + s[i];

	rep (i, n) fer (j, i+1, n+1) c[t++] = s[j] - s[i];
	sort (c, c+t);

	ll ans = 0;

	for (int i = 1; i*i <= a; i++)
	{
		if (a % i) continue;
		int p = upper_bound (c, c+t, i) - lower_bound (c, c+t, i);
		int q = upper_bound (c, c+t, a/i) - lower_bound (c, c+t, a/i);
		ans += p * (ll)q * (i != a/i ? 2 : 1);
	}

	if (a == 0)
	{
		int p = t - (upper_bound (c, c+t, 0) - c);
		ans = t*(ll)t - p*(ll)p;
	}

	cout << ans << endl;

	{ int _; cin >> _; return 0; }
}
