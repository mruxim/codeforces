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

const int maxn = 50 + 5;

int n, L;
int a[maxn], b[maxn];


int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> L;
	
	rep(i, n) cin >> a[i];
	rep(i, n) cin >> b[i];

	rep(d, n) {
		bool ok = true;
		rep(i, n)
			if((a[i] - a[(i-1+n)%n] + L) % L != (b[(i+d)%n] - b[(i+d-1+n) % n] + L) % L) {
				ok = false;
				break;
			}
		if(ok) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;

	return 0;
}

