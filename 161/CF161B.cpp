// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fer(i, x, n) for (int i = (x), _n = (n); i < _n; i++)
#define rof(i, n, x) for (int i = (n), _x = (x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define cmx(a, b) (a = max(a,b))
#define cmn(a, b) (a = min(a,b))
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

////////////////////////////////////////////////

const int MAXn = 1000 + 100;

int n, k;
int pr[MAXn];
vector <pii> s, p;
vi cart[MAXn];

int main()
{
	cin >> n >> k;
	rep (i, n)
	{
		int sp;
		cin >> pr[i] >> sp;
		if (sp == 1)	s.pb (mp (pr[i], i+1));
		else			p.pb (mp (pr[i], i+1));
	}
	sort (all (s));
	sort (all (p));
	reverse (all (s));
	reverse (all (p));

	rep (i, sz(s)) cart[min(i,k-1)].pb (s[i].Y);
	rep (i, sz(p)) cart[min (sz(s)+i, k-1)].pb (p[i].Y);

	ll r = 0;
	rep (i, sz (s)) r += s[i].X;
	rep (i, sz (p)) r += p[i].X;
	r *= 2;

	rep (i, k)
	{
		if (i >= sz(s)) continue;
		ll lp = 1LL<<50;
		rep (j, sz(cart[i]))
			cmn (lp, (ll)pr[cart[i][j]-1]);
		r -= lp;
	}
	cout << r/2 << (r%2 ? ".5" : ".0") << endl;
	rep (i, k)
	{
		cout << sz (cart[i]) << ' ';
		rep (j, sz (cart[i]))
			cout << cart[i][j] << ' ';
		cout << endl;
	}
	{ int _; cin >> _; }
}
