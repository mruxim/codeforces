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
#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxa = 4 * 100000;

ll s[maxa];

ll calc(int l, int a, int b) {
	if(l < 0) return 0;
	if(a + b < 0) return 0;
	if(a > b) swap(a, b);
	ll res = 0;
	res += (l+1) * (l+2) / 2;
	if(a >= 0 && b >= 0)
		res -= (l-a > 0 ? s[l-a] : 0) + (l-b > 0 ? s[l-b] : 0);
	else
		res = (l+a >= 0 ? s[l+a+1] : 0) - (l-b > 0 ? s[l-b] : 0);
	return res;
}

int a, b, c, l;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	fer(i, 1, maxa) {
		s[i] = i;
		if(i - 2 >= 0) s[i] += s[i-2];
	}

	cin >> a >> b >> c >> l;
	if(b > c) swap(b, c);

	ll ans = 0;

	rep(i, l+1) {
		a += i;
		int r = l - i;

		ans += max(0LL, calc(r, b-c+a-1, c-b+a-1) - calc(a-b-c, b-c+a-1, c-b+a-1));

		a -= i;
	}

	cout << ans << endl;


	return 0;
}

