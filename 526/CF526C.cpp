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

const ll ctv = 1e6;

ll t, ha, hb, wa, wb;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> t >> ha >> hb >> wa >> wb;

	if(wa > wb) swap(wa, wb), swap(ha, hb);
	if(ha >= hb) {
		cout << (t / wa) * ha << endl;
		return 0;
	}

	ll ans = 0;
	
	fer(cb, 0, min(ctv, t/wb+1))
		smax(ans, cb * hb + (t - cb * wb) / wa * ha);

	fer(ca, 0, min(ctv, t/wa+1))
		smax(ans, ca * ha + (t - ca * wa) / wb * hb);

	fer(cb, max(0ll, t/wb-ctv), t/wb+1)
		smax(ans, cb * hb + (t - cb * wb) / wa * ha);

	fer(ca, max(0ll, t/wa-ctv), t/wa+1)
		smax(ans, ca * ha + (t - ca * wa) / wb * hb);

	cout << ans << endl;

	return 0;
}

