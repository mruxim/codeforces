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

int rb, rs, rc;
int nb, ns, nc;
int pb, ps, pc;
ll money;

bool check (ll k)
{
	ll cost = 0;
	cost += max (rb*k-nb, 0LL) * pb;
	cost += max (rs*k-ns, 0LL) * ps;
	cost += max (rc*k-nc, 0LL) * pc;
	return cost <= money;
}

int main()
{
	ios_base::sync_with_stdio (false);

	string burger;
	cin >> burger;
	rb = count (all(burger), 'B');
	rs = count (all(burger), 'S');
	rc = count (all(burger), 'C');
	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> money;

	ll lo = 0, hi = 1e13;
	while (hi - lo > 1)
	{
		ll md = (lo+hi) / 2;
		if (check (md)) lo = md;
		else hi = md;
	}
	cout << lo << endl;
	{ return 0; }
}

