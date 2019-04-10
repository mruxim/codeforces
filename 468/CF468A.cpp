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

int n;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;

	if(n < 4) cout << "NO" << endl;
	else {
		cout << "YES" << endl;

		int c1 = 1;
		while(n-1 > 4)
			cout << n << " - " << n-1 << " = " << 1 << endl, c1++, n -= 2;
		if(n == 5)
			cout << "5 - 2 = 3" << endl, cout << "3 - 1 = 2" << endl, c1--, n--;
		while(c1) cout << "1 * 2 = 2" << endl, c1--;
		cout << "2 * 3 = 6" << endl;
		cout << "6 * 4 = 24" << endl;
	}

	return 0;
}

