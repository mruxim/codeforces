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

const int maxn = 1000*1000 + 100;
const int maxlg = 20 + 2;

int n;
string str;
int val[maxn];
int min_val[maxlg][maxn];
int bp2[maxn];

int main()
{
	ios_base::sync_with_stdio (false);

	bp2[0] = bp2[1] = 0;
	fer (i, 2, maxn) bp2[i] = bp2[i/2] + 1;

	cin >> str;
	n = sz(str)+1;

	val[0] = 0;
	rep (i, n) val[i+1] = val[i] + (str[i] == '(' ? 1 : -1);
	n++;

	rep (k, maxlg) rep (i, n)
	{
		if (k == 0) { min_val[k][i] = val[i]; continue; }
		min_val[k][i] = min_val[k-1][i];
		if (i + (1<<(k-1)) < n)
			smin (min_val[k][i], min_val[k-1][i+(1<<(k-1))]);
	}

	int q;
	for (cin >> q; q--; )
	{
		int l, r; cin >> l >> r; l--, r++;
		int min_lr = min (min_val[bp2[r-l]][l], min_val[bp2[r-l]][r-(1<<bp2[r-l])]);
		cout << r-l-1-(val[l]-min_lr)-(val[r-1]-min_lr) << endl;
	}

	{ return 0; }
}

