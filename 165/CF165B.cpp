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

ll n, k;

ll f (ll x)
{
	ll r = 0;
	while (x) r += x, x /= k;
	return r;
}

int main()
{
	cin >> n >> k;
	ll lo = 0, hi = 1LL << 35;
	while (hi - lo > 1)
		if (f ((lo+hi)/2) >= n)	hi = (lo+hi)/2;
		else					lo = (lo+hi)/2;
	cout << hi << endl;
	{ int _; cin >> _; }
}
