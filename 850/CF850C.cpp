// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?
// ....... .. .... .. ...., ....... ..!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0, i##__n = (int)(n); i < i##__n; ++i)
#define fer(i, a, b) for (int i = (int)(a), i##__b = (int)(b); i < i##__b; ++i)
#define rof(i, b, a) for (int i = (int)(b), i##__a = (int)(a); i-- > i##__a; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define X first
#define Y second
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

int n;
map<int, int> f;
map<int, int> m;

int nim(int r) {
	if((r & (r-1)) == 0) return r;
	if(m.find(r) != m.end()) return m[r];
	int mark = 0;
	fer(i, 1, 31) {
		if(r < (1 << i)) break;
		mark |= nim((r & ((1 << i) - 1)) | (r >> i));
	}
	mark = ~mark;
	return m[r] = mark & -mark;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) {
		int a; cin >> a;
		for(int i = 2; i * i <= a; i++) if(a % i == 0) {
			int c = 0;
			while(a % i == 0) a /= i, c++;
			f[i] |= 1 << c;
		}
		if(a > 1) f[a] |= 1 << 1;
	}

	int x = 0;
	for(pii p: f) x ^= __builtin_ctz(nim(p.Y));

	cout << (x ? "Mojtaba" : "Arpa") << endl;

	return 0;
}

