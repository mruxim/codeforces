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

ll l, r;
int k;

vector<ll> s1() { return vector<ll>({l}); }

vector<ll> s2() {
	ll t = l;
	if(t % 2) t++;
	if(t+1 < r) return vector<ll>({t, t+1});
	return vector<int>({l, l+1});
}

vector<ll> s3() {
	
}

vector<ll> s4() {
	ll t = l;
	if(t % 2) t++;
	if(t+3 < r) return vector<ll>({t, t+1, t+2, t+3});
	return vector<ll>({l, l+1, l+2, l+3});
}

bool less(vector<ll> v1, vector<ll> v2) {
	ll xr1 = 0, xr2 = 0;
	for(ll x: v1) xr1 ^= x;
	for(ll x: v2) xr2 ^= x;
	return xr1 < xr2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> l >> r >> k;
	r++;

	auto v = s1();
	if(k >= 2) {
		auto tv = s2();
		if(less(tv, v)) v = tv;
	}
	if(k >= 3) {
		auto tv = s3();
		if(less(tv, v)) v = tv;
	}
	if(k >= 4) {
		auto tv = s4();
		if(less(tv, v)) v = tv;
	}

	ll xr = 0;
	for(ll x: v) xr ^= x;
	cout << xr << endl;
	cout << sz(v) << endl;
	for(ll x: v) cout << x << ' ';
	cout << endl;
	

	return 0;
}

