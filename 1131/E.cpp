// ... ... .. ....!
// ... ....... .... ...!

#include<bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0, i##__n = (int)(n); i < i##__n; ++i)
#define fer(i, a, b) for(int i = (int)(a), i##__b = (int)(b); i < i##__b; ++i)
#define rof(i, b, a) for(int i = (int)(b), i##__a = (int)(a); i-- > i##__a; )
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

const int maxn = 100000 + 100;

int n;
string s[maxn];
int mask[maxn];

int calc_mid(int k, char c) {
	int ans = 0, cnt = 0;
	rep(i, sz(s[k])) {
		if(s[k][i] == c)
			cnt++;
		else
			cnt = 0;
		smax(ans, cnt);
	}
	return ans;
}

int calc_pref(int k, char c) {
	int pc;
	for(pc = 0; pc < sz(s[k]) && s[k][pc] == c; pc++);
	return pc;
}

int calc_suf(int k, char c) {
	int sc;
	for(sc = 0; sc < sz(s[k]) && s[k][sz(s[k]) - sc - 1] == c; sc++);
	return sc;
}

int calc(int k, char c) {
	if(k == 0) 
		return calc_mid(k, c);

	if(s[k] == string(sz(s[k]), c))
		return calc(k - 1, c) * (sz(s[k]) + 1) + sz(s[k]);

	int pref = calc_pref(k, c);
	int mid = calc_mid(k, c);
	int suf = calc_suf(k, c);
	int ans = mid;
	if(mask[k - 1] >> (c - 'a') & 1)
		smax(ans, pref + 1 + suf);
	return ans;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> s[i];

	rep(i, n) {
		if(i) mask[i] = mask[i-1];
		for(char c: s[i]) mask[i] |= 1 << (c - 'a');
	}
	
	int ans = 0;
	for(char c = 'a'; c <= 'z'; c++)
		smax(ans, calc(n-1, c));

	cout << ans << endl;

	return 0;
}

