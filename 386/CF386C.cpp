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

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 3*100000 + 100;

int n;
string s; int a[maxn];
vector<int> pos[33];
int id[33];
int f[33];
ll ans[33];

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> s; n = sz(s);
	rep (i, n) a[i] = s[i]-'a', pos[a[i]].pb (i);
	rep (i, 26) pos[i].pb (n);

	rep (i, n)
	{
		rep (j, 26) f[j] = pos[j][id[j]]; f[26] = n;
		sort (f, f+27);

		fer (j, 1, 27) ans[j] += f[j] - f[j-1];

		id[a[i]]++;
	}

	int c = 1; while (ans[c]) c++;
	cout << c-1 << endl;
	fer (i, 1, c) cout << ans[i] << endl;

	{ return 0; }
}

