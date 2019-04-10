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

int cnt(int x) {
	if(x == 0) return 2;
	if(x == 1) return 7;
	if(x == 2) return 2;
	if(x == 3) return 3;
	if(x == 4) return 3;
	if(x == 5) return 4;
	if(x == 6) return 2;
	if(x == 7) return 5;
	if(x == 8) return 1;
	if(x == 9) return 2;
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;

	int ans = 1;
	rep(z, 2) {
		ans *= cnt(n % 10);
		n /= 10;
	}

	cout << ans << endl;

	return 0;
}

