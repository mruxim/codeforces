// .... ... .... .., ....!

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
typedef unsigned long long ull;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

ull n, H;

ull g(ull x) {
	if(x % 2 == 0)
		return (x / 2) * (x / 2 + 1);
	else
		return (x / 2 + 1) * (x / 2 + 1);
}

ull f(ull len) {
	ull res = len * (len + 1) / 2;
	if(len > H)
		res -= g(len - H);
	return res;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> H;

	ull lo, hi = 1;
	while(f(hi) < n)
		hi *= 2;
	lo = hi / 2;
	while(hi - lo > 1) {
		ull md = (lo + hi) / 2;
		if(f(md) < n)
			lo = md;
		else
			hi = md;
	}

	cout << hi << endl;

	return 0;
}

