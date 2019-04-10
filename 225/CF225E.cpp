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

const int mod = 1000000000+7;

bool ip(int x) {
	if(x < 2) return false;
	for(int i = 2; i*i <= x; i++)
		if(x % i == 0) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n; cin >> n; n--;

	vector<int> v;
	fer(i, 2, 300) if(ip(i) && i != 11 && i != 23) v.pb(i);


	int ans = 1;
	rep(i, v[n]-1)
		ans = ans * 2 % mod;

	cerr << " !!" << v[n] << endl;
	cout << ans-1 << endl;

	return 0;
}

