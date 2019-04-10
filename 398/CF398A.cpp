// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include <bits/stdc++.h>
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

int main() {
	ios_base::sync_with_stdio (false);

	int a, b;
	cin >> a >> b;

	if(a == 0) {
		cout << -b * (ll)b << endl;
		cout << string(b, 'x') << endl;
		return 0;
	}

	ll ans = -1e18;
	int c = -1;
	fer(i, 1, a+1) {
		int len = b / (i+1);
		ll cur = (i-1) + (a-i+1) * (ll)(a-i+1);
		cur -= len * (ll)len * ((i+1) - b % (i+1)) + (len+1) * (ll)(len+1) * (b % (i+1));
		if(ans < cur) ans = cur, c = i;
	}

	cout << ans << endl;
	string str;
	rep(i, b % (c+1)) str += "o" + string(b / (c+1) + 1, 'x');
	rep(i, (c+1) - b % (c+1)) str += "o" + string(b / (c+1), 'x');
	fer(i, 1, sz(str)) if(str[i] == 'o') {
		str = str.substr(0, i) + string(a-c, 'o') + str.substr(i);
		break;
	}
	cout << str.substr(1) << endl;

	{ return 0; }
}

