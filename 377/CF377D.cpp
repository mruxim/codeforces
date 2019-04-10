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

#define X first.first
#define Y first.second
#define Z second.first
#define ID second.second

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100*1000 + 100;
const int RANGE = 3*100*1000 + 100;

int n;
pair <pii, pii> LVR[maxn], VLR[maxn];
int add_val[4*RANGE], max_val[4*RANGE];

void add_range (int x, int nl, int nr, int ql, int qr, int val)
{
	if (nr <= ql || qr <= nl) return;
	if (ql <= nl && nr <= qr)
	{
		add_val[x] += val;
		max_val[x] += val;
		return;
	}
	add_val[2*x+1] += add_val[x], max_val[2*x+1] += add_val[x];
	add_val[2*x+2] += add_val[x], max_val[2*x+2] += add_val[x];
	add_val[x] = 0;

	int nm = (nl+nr) / 2;
	add_range (2*x+1, nl, nm, ql, qr, val);
	add_range (2*x+2, nm, nr, ql, qr, val);

	max_val[x] = max (max_val[2*x+1], max_val[2*x+2]);
}

int main()
{
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n)
	{
		cin >> LVR[i].X >> LVR[i].Y >> LVR[i].Z; LVR[i].Z++;
		LVR[i].ID = i; VLR[i] = LVR[i]; swap (VLR[i].X, VLR[i].Y);
	}
	
	sort (LVR, LVR+n);
	sort (VLR, VLR+n);

	int pos = 0;
	int ans = 0, ind = 0;
	rep (i, n)
	{
		while (pos<n && LVR[pos].X <= VLR[i].X)
			add_range (0, 0, RANGE, LVR[pos].Y, LVR[pos].Z, 1), pos++;
		if (max_val[0] >= ans) ans = max_val[0], ind = i;
		add_range (0, 0, RANGE, VLR[i].X, VLR[i].Z, -1);
	}

	cout << ans << endl;
	vector <int> LS, RS;
	fer (i, ind, n) if (VLR[i].Y <= VLR[ind].X && VLR[i].X < VLR[ind].Z)
		LS.pb (VLR[i].X), RS.pb (VLR[i].Z);

	sort (all(LS)), sort (all(RS));

	int max_cur = -1, max_i = -1, cur = 0; pos = 0;
	rep (i, sz(LS))
	{
		while (pos<sz(RS) && RS[pos] <= LS[i]) cur--, pos++;
		cur++;
		if (max_cur < cur) max_cur = cur, max_i = i;
	}

	fer (i, ind, n) if (VLR[i].Y <= VLR[ind].X && VLR[i].X < VLR[ind].Z && VLR[i].X <= LS[max_i] && LS[max_i] < VLR[i].Z)
		cout << VLR[i].ID+1 << ' ';
	cout << endl;

	{ int _; cin >> _; return 0; }
}

