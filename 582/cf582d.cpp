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

const int mod = 100000000+7;

int p, a;
string str;
vector<int> v;

int f(int x, int y) {
	int res = 0;
	int c = 0;
	while(x || y || c) {
		c = (x % p + y % p + c) / p;
		x /= p;
		y /= p;
		res += c;
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> p >> a;
	cin >> str;

	reverse(all(str));
	int mul = 1;
	rep(i, sz(str)) {
		
	}

	int ans = 0;
	rep(i, k+1) rep(j, k-i+1)
		ans += (f(i, j) >= a);

	cout << ans << endl;

	return 0;
}

