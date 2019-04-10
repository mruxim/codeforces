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

const int maxn = 7000 + 100;
const int maxs = 2000000;

int n, m;
vector<pair<pii,int>> q[maxn];
int g[maxs];
int xmark[maxs], xcur = 4;

int main()
{
	ios_base::sync_with_stdio (false);

	g[0] = 0;
	fer (i, 1, maxs) g[i] = g[i/2]+1;

	cin >> n >> m;

	rep (z, m)
	{
		int tp; cin >> tp;

		if (tp == 1)
		{
			int lvl, L, R, x;
			cin >> lvl >> L >> R >> x;
			lvl--, L--;
			q[lvl].pb (mkp (pii (L, R), x));
		}
		else
		{
			int lvl, L, R;
			cin >> lvl >> L;
			lvl--, L--, R = L+1;

			int ans = 0;
			xcur += 7;

			while (lvl < n)
			{
				for (auto qry: q[lvl]) if (!(R <= qry.first.X || qry.first.Y <= L))
				{
					if (xmark[qry.Y] != xcur) ans++;
					xmark[qry.Y] = xcur;
				}
				L += g[L], R += g[R];
				lvl++;
			}

			cout << ans << endl;
		}
		
	}

	{ return 0; }
}

