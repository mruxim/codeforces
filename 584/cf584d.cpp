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

bool ip(int x) {
	for(int i = 2; i*i <= x; i++) if(x % i == 0) return false;
	return true;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	int n;
	cin >> n;

	if(ip(n)) {
		cout << 1 << endl;
		cout << n << endl;
		return 0;
	}
	
	int p = n - 4;
	while(!ip(p)) p -= 2;

	for(int i = 2; i < n-p; i++)
		if(ip(i) && ip(n-p-i)) {
			cout << 3 << endl;
			cout << p << ' ' << i << ' ' << n-p-i << endl;
			return 0;
		}

	return 0;
}

