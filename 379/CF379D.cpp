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
typedef pair<ll, ll> pll;

////////////////////////////////////////////////////////////////////////////////

ll inf = (ll)1e15;
const int maxk = 50 + 5;

int k, n, m;
ll tar;

ll AB[maxk], BA[maxk], BB[maxk];
pll T[maxk];

bool check (int i, int j, int bb, int ba, int ab)
{
	ll tot = 0;
	tot += T[k].X * i + T[k].Y * j;
	tot += bb * BB[k] + ba * BA[k] + ab * AB[k];
	return tot == tar;
}

int main()
{
	ios_base::sync_with_stdio (false);

	AB[1] = BA[1] = BB[1] = 0;
	AB[2] = BA[2] = BB[1] = 0;
	AB[3] = 1, BA[3] = BB[3] = 0;

	fer (i, 4, maxk)
	{
		AB[i] = AB[i-1] + AB[i-2];
		smin (AB[i], inf);
		BA[i] = BA[i-1] + BA[i-2] + (i % 2 == 0 ? 1 : 0);
		smin (BA[i], inf);
		BB[i] = BB[i-1] + BB[i-2] + (i % 2 == 1 ? 1 : 0);
		smin (BB[i], inf);
	}

	T[1] = pll (1, 0);
	T[2] = pll (0, 1);
	fer (i, 3, maxk)
	{
		T[i] = pll (T[i-1].X + T[i-2].X, T[i-1].Y + T[i-2].Y);
		smin (T[i].X, inf);
		smin (T[i].Y, inf);
	}

	cin >> k >> tar >> n >> m;

	int ri = -1, rj = -1, rbb = -1, rba = -1, rab = -1;

	fer (i, 0, n/2+1) fer (j, 0, m/2+1)
	{
		int bbl = (2*j <= m-2);
		int bal = (2*j <= m-1 && 2*i <= n-1);
		int abl = (2*j <= m-1 && 2*i <= n-1);
		fer (bb, 0, bbl+1) fer (ba, 0, bal+1) fer (ab, 0, abl+1) if (!(ab&&ba&&!bb) && (2*i+ab+ba<=n))
			if (check (i, j, bb, ba, ab))
			{
				ri = i, rj = j, rbb = bb, rba = ba, rab = ab;
				goto out;
			}
	}

out:;
	if (ri == -1) cout << "Happy new year!" << endl;
	else
	{
		string A = "", B = "";
		if (rba) A += "C";
		rep (z, ri) A += "AC";
		while (sz(A) + rab < n) A += "X";
		if (rab) A += "A";

		if (rbb || rab) B += "C";
		rep (z, rj) B += "AC";
		while (sz(B) + (rbb | rba) < m) B += "Y";
		if (rbb || rba) B += "A";

		cout << A << endl;
		cout << B << endl;
	}

	{ int _; cin >> _; return 0; }
}

