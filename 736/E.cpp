// .... .... .....!
// ...... ......!
// .... ....... ..... ..!
// ...... ... ... .... ... .... .....!
// ... .. ... .... ...?

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
//#define endl '\n'

template<class P, class Q> inline void smin(P &a, Q b) { if (b < a) a = b; }
template<class P, class Q> inline void smax(P &a, Q b) { if (a < b) a = b; }

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxm = 3000 + 100;

int m, n;
int res[maxm];
char w[maxm][maxm];
int cnt[maxm];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> m >> n;
	rep(i, n) cin >> res[i], res[i] -= (m-1);

	int sum = accumulate(res, res+n, 0);

	if(res[0] > m-1 || sum + res[n-1] * (m - n) < 0 || (m-n ? -sum / (m-n) > res[n-1] : 0)) { cout << "no" << endl; return 0; }

	set<pii> s, t;
	rep(i, n) s.insert(pii(res[i], i));

	int lpos = m-1;
	rep(z, sum) {
		pii p = *s.rbegin();
		s.erase(p);
		w[p.Y][lpos] = 1;
		w[lpos][p.Y] = -1;
		p.X--;
		cnt[p.Y]++;
		if(cnt[p.Y] == m-n)
			t.insert(p);
		else
			s.insert(p);
		lpos--;
		if(lpos < n) lpos = m-1;
	}

	for(pii p: t) s.insert(p);
	while(!s.empty() && s.rbegin()->X > 0) {
		pii p = *s.rbegin();
		s.erase(p);
		vector<pii> v;
		for(pii q: s) {
			v.pb(q);
			if(sz(v) == p.X) break;
		}
		for(pii q: v) s.erase(q), w[p.Y][q.Y] = 1, w[q.Y][p.Y] = -1, q.X++, s.insert(q);
	}

	cout << "yes" << endl;
	rep(i, m) {
		rep(j, m)
			cout << (i == j ? 'X' : w[i][j] == 1 ? 'W' : w[i][j] == -1 ? 'L' : 'D');
		cout << endl;
	}

	return 0;
}

