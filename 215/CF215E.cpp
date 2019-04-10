// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int((x).size()))
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

inline ll make (int pattern, int length, int quantity)
{
	return pattern * (((1LL << (length * quantity)) - 1) / ((1LL << length) - 1));
}

int count (int length, int quantity, ll limit)
{
	int lo = 1 << (length - 1), hi = lo * 2;
	if (make (lo, length, quantity) > limit)
		return 0;
	if (make (hi - 1, length, quantity) <= limit)
		return 1 << (length - 1);
	ll temp = limit >> (length * (quantity - 1));
	if (make (temp, length, quantity) <= limit)
		temp++;
	return temp - (1 << (length - 1));
}

ll solve (ll L, ll R)
{
	const vector <int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};
	ll ret = 0;
	fer (totalLength, 2, 62)
	{
		vector <int> v;
		rep (i, sz (primes))
			if (totalLength % primes[i] == 0)
				v.push_back (primes[i]);
		fer (i, 1, 1 << sz(v))
		{
			int quantity = 1;
			rep (j, sz(v))
				if (i >> j & 1)
					quantity *= v[j];
			int coef = __builtin_popcount (i) % 2 ? 1 : -1;
			ret += coef * (count (totalLength / quantity, quantity, R) - count (totalLength / quantity, quantity, L - 1));
		}
	}
	return ret;
}

int main()
{
	ll L, R;
	cin >> L >> R;
	cout << solve (L, R) << endl;
	{ int _; cin >> _; }
}
