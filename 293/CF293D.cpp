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
#include <numeric>

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

double calc (vector<int> &v)
{
	int n = sz(v);
	long double ret = 0.0;
	long double a = 0;
	long double b = 0;
	long double c = 0;

	c = v[0];
	fer (i, 1, n)
	{
		b += 2 * c - v[i-1];
		a += b;
		ret += v[i]*(long double)a;
		c += v[i];
	}
/*	{//bruteforce
		ll tt = 0;
		rep (i, n) rep (j, n) tt += (i-j)*(ll)(i-j)*v[i]*v[j];
		cerr << tt / (c*(double)(c-1)) << " ==?== " << 2*ret / (c*(double)(c-1)) << endl;
	}*/
	return 2*ret / (c*(long double)(c-1));
}

double solve (vector <pii> p)
{
	rotate (p.begin(), min_element (all(p)), p.end());
	p.pb(p[0]);
	int maxind = max_element (all(p)) - p.begin(), cur = 0;
	int minx = p[0].X, maxx = p[maxind].X;
	vector <int> v (maxx - minx + 1);

//	rep (i, sz(p)) cerr << " (" << p[i].X << ',' << p[i].Y << ") -"; cerr << endl;
	for (int x = minx, i = 0; x <= maxx; x++, i++)
	{
		if (p[cur+1].X > p[cur].X && x == p[cur+1].X) cur++;
		if (x == p[cur].X) v[i] = -p[cur].Y;
		else
		{
			int ydiff = (p[cur+1].Y - p[cur].Y) * (ll)(x - p[cur].X) / (p[cur+1].X - p[cur].X);
			if ((p[cur+1].X - p[cur].X) * (ll)ydiff < (p[cur+1].Y - p[cur].Y) * (ll)(x - p[cur].X))	
				ydiff++;
			v[i] = -(p[cur].Y + ydiff);
		}
	}
//	cerr << "--> "; rep (i, sz(v)) cerr << v[i] << ' '; cerr << endl;

	cur = maxind;
	for (int x = maxx, i = maxx - minx; x >= minx; x--, i--)
	{
		if (p[cur+1].X < p[cur].X && x == p[cur+1].X) cur++;
		if (x == p[cur].X) v[i] += p[cur].Y + 1;
		else
		{
			int ydiff = (p[cur+1].Y - p[cur].Y) * (ll)(p[cur].X - x) / (p[cur].X - p[cur+1].X);
			if ((p[cur].X - p[cur+1].X) * (ll)ydiff > (p[cur+1].Y - p[cur].Y) * (ll)(p[cur].X - x))	
				ydiff--;
			v[i] += p[cur].Y + ydiff + 1;
		}
	}
//	cerr << "++> "; rep (i, sz(v)) cerr << v[i] << ' '; cerr << endl;

	return calc (v);
}

inline ll cross (pii p, pii q1, pii q2) { return (q1.X-p.X) * (ll)(q2.Y-p.Y) - (q1.Y-p.Y) * (ll)(q2.X-p.X); }

int main()
{
	ios::sync_with_stdio (false);

	int n;
	bool cc = false;
	cin >> n;
	vector<pii> p(n);
	rep (i, n)
	{
		cin >> p[i].X >> p[i].Y;
		if (i >= 2)
			if (cross (p[i-2], p[i-1], p[i]) < 0)
				cc = true;
	}
	if (cc) reverse (all(p));

	double ans1 = solve (p);
	rep (i, n) swap (p[i].X, p[i].Y);
	reverse (all(p));
	double ans2 = solve(p);

	cout << fixed << setprecision (9) << (ans1 + ans2) / 2 << endl;

	{ int _; cin >> _; return 0; }
}
