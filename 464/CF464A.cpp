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

int n, p;
string s, t;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> p;
	cin >> s;

	rof(i, n, 0) if(s[i] != 'a' + p - 1) {
		t = s;
		t[i]++;
		if(i && t[i] == t[i-1]) t[i]++;
		if(i-1>0 && t[i] == t[i-2]) t[i]++;
		if(i && t[i] == t[i-1]) t[i]++;

		if(t[i] >= 'a' + p) continue;

		bool good = true;
		fer(j, i+1, n) {
			char c = 'a';
			if(c == t[j-1]) c++;
			if(j-1 && c == t[j-2]) c++;
			if(c == t[j-1]) c++;
			if(c >= 'a' + p) { good = false; break; }
			t[j] = c;
		}
		if(good) { cout << t << endl; return 0; }
	}

	cout << "NO" << endl;

	return 0;
}

