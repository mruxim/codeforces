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

const int maxn = 100000 + 100;

int n;

int powmod(int b, int pw, int mod) {
	int r = 1;
	rep(i, 30) {
		if(pw >> i & 1)
			r = r * (ll)b % mod;
		b = b * (ll)b % mod;
	}
	return r;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;

	if(n == 4) {
		cout << "YES" << endl;
		cout << 1 << endl << 3 << endl << 2 << endl << 4 << endl;
		return 0;
	}

	bool ip = true;
	for(int i = 2; i*i <= n; i++) if(n % i == 0) ip = false;
	if(!ip) { cout << "NO" << endl; return 0; }

	cout << "YES" << endl;
	int cur = 1;
	rep(i, n) {
		int val = (i+1) % n * (ll)powmod(cur, n-2, n) % n;
		cout << (val ? val : val+n) << endl;
		cur = cur * (ll)val % n;
	}

	return 0;
}

