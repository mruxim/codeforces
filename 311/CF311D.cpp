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

const int mod = 95542721;
const int loop = 48;

const int maxn = 100000 + 100;

int n, q;
int a[maxn];

int val[1<<18][loop], pos[1<<18];

inline void add (int &x, int y) { x += y; if (x >= loop) x -= loop; }
inline int fix (int x) { return x >= mod ? x-mod : x; }

void make (int x, int l, int r)
{
	if (r - l == 1)
	{
		val[x][0] = a[l];
		fer (i, 1, loop)
			val[x][i] = (ll)val[x][i-1] * (ll)val[x][i-1] % mod * (ll)val[x][i-1] % mod;
		return;
	}
	int mid = (l + r) / 2;
//	int mid = l; rep (i, 30) if (mid + (1 << i) >= r) { mid += 1 << (i-1); break; }
	make (2*x+1, l, mid);
	make (2*x+2, mid, r);

	rep (i, loop)
		val[x][i] = fix (val[2*x+1][i] + val[2*x+2][i]);
}

void cub (int x, int l, int r, int L, int R)
{
	if (r <= L || R <= l) return;
	if (L <= l && r <= R) { add (pos[x], 1); return; }
	
	add (pos[2*x+1], pos[x]);
	add (pos[2*x+2], pos[x]);
	pos[x] = 0;

	int mid = (l + r) / 2;
//	int mid = l; rep (i, 30) if (mid + (1 << i) >= r) { mid += 1 << (i-1); break; }
	cub (2*x+1, l, mid, L, R);
	cub (2*x+2, mid, r, L, R);

	int lid = pos[2*x+1], rid = pos[2*x+2];
	rep (i, loop)
	{
		val[x][i] = fix (val[2*x+1][lid] + val[2*x+2][rid]);
		lid++, rid++;
		if (lid >= loop) lid -= loop;
		if (rid >= loop) rid -= loop;
	}
}

int get (int x, int l, int r, int L, int R, int rot = 0)
{
	if (r <= L || R <= l) return 0;
	if (L <= l && r <= R) return val[x][(pos[x] + rot) % loop];

	int mid = (l + r) / 2;
//	int mid = l; rep (i, 30) if (mid + (1 << i) >= r) { mid += 1 << (i-1); break; }
	return fix (get (2*x+1, l, mid, L, R, rot + pos[x]) + get (2*x+2, mid, r, L, R, rot + pos[x]));
}

int main()
{
	ios::sync_with_stdio (false);

	cin >> n;
	rep (i, n) { cin >> a[i]; rof (j, 4, 0) if (a[i] >= (mod << j)) a[i] -= mod << j; }

	make (0, 0, n);

	cin >> q;
	while (q--)
	{
		int com;
		int L, R;
		cin >> com >> L >> R; L--;
		if (com == 1)
			cout << get (0, 0, n, L, R) << endl;
		else
			cub (0, 0, n, L, R);
	}

	{ int _; cin >> _; return 0; }
}
