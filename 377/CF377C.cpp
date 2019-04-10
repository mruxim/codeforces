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

const int inf = 1<<30;
const int maxn = 20 + 2;

int n, m, p;
int s[111];

char act[maxn];
int team[maxn];

bool calc[1<<20];
int mem[1<<20];

int go (int turn, int mask)
{
	if (turn == m) return 0;
	int &ret = mem[mask];
	if (calc[mask]) return ret;

	calc[mask] = true;
	ret = 0;
	if (act[turn] == 'p')
	{
		int id = 0;
		rep (i, n) if (!(mask >> i & 1)) { id = i; break; }
		mask ^= 1 << id;
		ret = (team[turn] == 1 ? 1 : -1) * s[id];
		ret += go (turn+1, mask);
		return ret;
	}
	else
	{
		ret = (team[turn] == 1 ? -1e9 : 1e9);
		rep (i, n) if (!(mask >> i & 1))
		{
			int tmp = go (turn+1, mask ^ (1 << i));
			if (team[turn] == 1)
				smax (ret, tmp);
			else
				smin (ret, tmp);
		}
	}
	return ret;
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> s[i];
	sort (s, s+n, greater<int>());

	cin >> m;
	rep (i, m) cin >> act[i] >> team[i], p += (act[i] == 'p' ? 1 : 0);
	smin (n, m);

	cout << go (0, 0) << endl;

	{ int _; cin >> _; return 0; }
}
