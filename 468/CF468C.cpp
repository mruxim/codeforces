// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

ll calc(ll v) {
	if(v == 0) return 0;
	ll r = 1, p = 1; int c = 0, d = 0, s = 0;
	while(v / r) s += d ? v / r % 10 : 0, d = d ? d : v / r % 10, c += d == 0, r *= 10, p = d ? p : r;
	return calc(v - d * p) + p * d * s + p * d * (d-1) / 2 + d * c * p / 10 * 45;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	ll a; cin >> a;

	ll l = 1, r = 1;
	while(calc(r) < a) r *= 2;
	for(ll d = r / 2; d; d /= 2) if(calc(r - d) >= a) r -= d;
	for(ll t; (t = calc(r) - calc(l)) != a; t < a ? r++ : l++);

	cout << l << ' ' << r-1 << endl;

	return 0;
}

