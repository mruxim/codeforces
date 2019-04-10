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

const int maxn = 1000000 + 100;
const int base = 747;

int n, k;
char s[maxn];
int h[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> k;
	cin >> s;

	rep(i, n) h[i+1] = h[i] * base + s[i];

	for(int ab = 1; ab <= n/k; ab++) {
		int len = k * ab;

	}

	return 0;
}

