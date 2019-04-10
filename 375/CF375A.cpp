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

template<class T> inline void smin(T &X,T Y){if(Y<X)X=Y;}
template<class T> inline void smax(T &X,T Y){if(X<Y)X=Y;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

int n;
string s;
int p[10];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> s;
	n = sz(s);

	rep (i, n) p[s[i]-'0'] = i;
	string t = "1689", ot = t;
	rep (i, 4) swap (s[p[ot[i]-'0']], s[i]);
	rof (i, n, 0) p[s[i]-'0'] = i;

	do {
		rep (i, 4) s[p[ot[i]-'0']] = t[i];
		cerr << s << endl;
		int r = 0;
		rep (i, n) r = (r*10 + s[i]-'0') % 7;
		if (r == 0)
		{
			cout << s << endl;
			goto hell;
		}
	} while (next_permutation (all(t)));

	cout << 0 << endl;

	hell:; { int _; cin >> _; return 0; }
}
