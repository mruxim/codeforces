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

int n, q;
int s, e;
bool rev;
int a[maxn];
int f[maxn];

void add(int pos, int val) {
	for(pos++; pos < maxn; pos += pos & -pos)
		f[pos] += val;
}

int get(int pos) {
	int res = 0;
	for(; pos; pos -= pos & -pos) res += f[pos];
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> q;

	rep(i, n) a[i] = 1, add(i, 1);
	s = 0, e = n;
	
	rep(z, q) {
		int cmd; cin >> cmd;
		if(cmd == 1) {
			int p; cin >> p;
			int orev = rev;
			if(2*p > e-s) rev = !rev;
			if(orev) p = (e-s) - p;
			if(2*p <= e-s) {
				rep(i, p)
					add(s+2*p-i-1, a[s+i]), a[s+2*p-i-1] += a[s+i],
					add(s+i, -a[s+i]), a[s+i] = 0;
				s += p;
			}
			else {
				p = (e-s)-p;
				rep(i, p)
					add(e-2*p+i, a[e-i-1]), a[e-2*p+i] += a[e-i-1],
					add(e-i-1, -a[e-i-1]), a[e-i-1] = 0;
				e -= p;
			}
		} else {
			int l, r; cin >> l >> r;
			if(!rev) l += s, r += s;
			else { int ol = l; l = e - r, r = e - ol; }
			cout << get(r) - get(l) << endl;
		}
	}

	return 0;
}

