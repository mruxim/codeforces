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

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	string s;
	cin >> s;
	string t = s.substr(3);
	s = s.substr(0, 3);

	int a = accumulate(all(s), 0) - '0' * 3;
	int b = accumulate(all(t), 0) - '0' * 3;

	if(a > b) swap(s, t), swap(a, b);
	vector<int> v;
	rep(i, 3) v.pb('9' - s[i]);
	rep(i, 3) v.pb(t[i] - '0');
	sort(all(v)); reverse(all(v));
	rep(i, 4) {
		if(a >= b) {
			cout << i << endl;
			break;
		}
		a += v[i];
	}

	return 0;
}

