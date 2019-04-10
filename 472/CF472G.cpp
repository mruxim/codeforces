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

typedef unsigned int TP;

const int maxlen = 200000 + 100;
const int rem = sizeof(TP) * 8;
const int remh = rem / 2;
const int shift = __builtin_ctz(rem);

TP a[rem][maxlen / rem + 1];
TP b[rem][maxlen / rem + 1];

void read(TP f[rem][maxlen / rem + 1]) {
	string str;
	cin >> str;
	rep(r, rem) fer(i, r, sz(str))
		f[r][(i-r) >> shift] |= ((TP)str[i] - '0') << ((i-r) & (rem-1));
}

int cnt[1<<remh];

inline int bpc(TP x) {
	return cnt[x >> remh] + cnt[x & ((1U << remh) - 1)];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	fer(i, 1, 1 << remh) cnt[i] = cnt[i&(i-1)] + 1;

	read(a);
	read(b);

	int qs; cin >> qs;
	while(qs--) {
		int pa, pb, len; cin >> pa >> pb >> len;
		TP *aa = a[pa & (rem-1)] + (pa >> shift);
		TP *bb = b[pb & (rem-1)] + (pb >> shift);

		int ans = 0;
		rep(i, len >> shift) ans += bpc(aa[i] ^ bb[i]);
		ans += bpc((aa[len >> shift] ^ bb[len >> shift]) & ((1 << (len & (rem-1))) - 1));

		cout << ans << endl;
	}

	return 0;
}

