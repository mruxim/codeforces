// .... .... .... !

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

int n[2], k;
vector <pair <int, pii> > t[2];
vector <pii> v[2];

int main()
{
	ios::sync_with_stdio (false);

	cin >> n[0] >> n[1] >> k;
	while (k--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		if (x1 > x2) swap (x1, x2);
		if (y1 > y2) swap (y1, y2);
		if (x1 == x2)	t[0].pb (mp (x1, mp (y1, y2)));
		else		t[1].pb (mp (y1, mp (x1, x2)));
	}
	
	int xorall = 0;
	rep (z, 2)
	{
		sort (all (t[z]));
		int last = 0;
		int emp = sz(t[z]) ? (t[z][sz(t[z])-1].X+1 < n[z] ? t[z][sz(t[z])-1].X+1 : 0) : n[z]-1;
		rep (i, sz(t[z]))
		{
			if (i == 0 || t[z][i].X != t[z][i-1].X)
			{
				v[z].pb (mp (t[z][i].X, 0)), last = 0;
				if ((i && t[z][i].X-1 > t[z][i-1].X) || (i == 0 && t[z][i].X > 1))
					emp = t[z][i].X-1;
			}
			v[z].back().Y += max (0, t[z][i].Y.Y - max (t[z][i].Y.X, last)), last = max (last, t[z][i].Y.Y);;
		}
		if (emp != 0) v[z].pb (mp (emp, 0));
		rep (i, sz(v[z]))
			xorall ^= n[1-z] - v[z][i].Y;
		xorall ^= n[1-z] * ((n[z]-1-sz(v[z])) % 2);
	}
	
	cerr << xorall << endl;
	
	if (xorall == 0)
	{
		cout << "SECOND" << endl;
		return 0;
	}
	cout << "FIRST" << endl;

	int maxbit = 1;
	while (xorall / 2 >= maxbit) maxbit <<= 1;

	rep (z, 2) rep (i, sz(v[z])) if ((n[1-z] - v[z][i].Y) & maxbit)
	{
		int target = ((n[1-z] - v[z][i].Y) ^ xorall);
//		cerr << xorall << ' ' << n[1-z] << ' ' << (n[1-z] - v[z][i].Y) << ' ' << target << endl;
		int k1 = lower_bound (all (t[z]), mp (v[z][i].X, mp (0,0))) - t[z].begin();
		int k2 = lower_bound (all (t[z]), mp (v[z][i].X, mp (1<<30,0))) - t[z].begin();
		int last = 0;
		fer (k, k1, k2)
		{
			if (t[z][k].Y.X >= last + target)
				break;
			target -= max (0, t[z][k].Y.X - last);
			last = max (last, t[z][k].Y.Y);
		}
		last += target;
		if (z == 0)	cout << v[z][i].X << ' ' << last << ' ' << v[z][i].X << ' ' << n[1-z] << endl;
		else		cout << last << ' ' << v[z][i].X << ' ' << n[1-z] << ' ' << v[z][i].X << endl;
		z = 1;
		break;
	}

	{ int _; cin >> _; return 0; }
}
