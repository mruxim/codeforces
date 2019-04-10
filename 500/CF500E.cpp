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
#define L first.first
#define R first.second
#define ID second

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 200000 + 100;

int n, qt;
int a[maxn], b[maxn];
int store[2*maxn], len[2*maxn], k;
pair<pii, int> q[maxn];
set<int> s;

int fen[2*maxn];
int ans[maxn];

inline void add(int x, int val) {
	for(x++; x < 2*maxn; x += x & -x) fen[x] += val;
}

inline int get(int x) {
	int res = 0;
	for( ; x; x -= x & -x) res += fen[x];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> a[i] >> b[i], b[i] += a[i];
	cin >> qt;
	rep(i, qt) cin >> q[i].L >> q[i].R, q[i].L--, q[i].R--, q[i].ID = i;

	rep(i, n) store[k++] = a[i], store[k++] = b[i];

	sort(store, store+k);
	k = unique(store, store+k) - store;
	rep(i, k-1) len[i] = store[i+1] - store[i], add(i, len[i]), s.insert(i);

	sort(q, q+qt);
	reverse(q, q+qt);
	
	int pos = n;
	rep(i, qt) {
		while(pos > q[i].L) {
			pos--;
			int aa = lower_bound(store, store+k, a[pos]) - store;
			int bb = lower_bound(store, store+k, b[pos]) - store;
			int bef = get(aa);
			while(bef != get(bb)) {
				int x = *s.lower_bound(aa);
				s.erase(x);
				add(x, -len[x]);
			}
		}
		
		int l = lower_bound(store, store+k, a[q[i].L]) - store;
		int r = lower_bound(store, store+k, a[q[i].R]) - store;
		ans[q[i].ID] = get(r) - get(l);
	}

	rep(i, qt) cout << ans[i] << endl;

	return 0;
}

