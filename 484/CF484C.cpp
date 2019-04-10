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

const int maxn = 1000000 + 100;

int n, m;
string s, t;
int p[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> s; n = sz(s);
	t = s;

	cin >> m;
	while(m--) {
		int k, d; cin >> k >> d;

		int pos = 0;
		rep(i, d) for(int j = i; j < k; j += d) p[pos++] = j;
		p[pos] = 0;

		pos = 0;
		rep(i, n-k) {
			cerr << pos << ' ';
			t[i] = s[pos];
			pos = p[pos+1];
		}

		cout << t << endl;
	}

	int k, d;
	while(cin >> k >> d) {
		string t = s;
		rep(i, n-k+1) {
			string str = t;
			int pos = i;
			rep(j, d)
				for(int p = i+j; p < i+k; p += d)
					str[pos++] = t[p];
			t = str;
			cout << t << endl;
		}
	}

	return 0;
}

