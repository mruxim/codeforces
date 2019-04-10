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

const int inf = 1e9;
const int maxk = 500 + 10;

int w, h, k;
pii p[maxk];
int s[2*maxk][2*maxk];

bool check(int t) {
	vector<int> vx, vy;
	vx.pb(0), vx.pb(w);
	vy.pb(0), vy.pb(h);
	
	rep(i, k) {
		vx.pb(max(0, p[i].X - t)), vx.pb(min(w, p[i].X + t + 1));
		vy.pb(max(0, p[i].Y - t)), vy.pb(min(h, p[i].Y + t + 1));
	}
	
	sort(all(vx)); vx.erase(unique(all(vx)), vx.end());
	sort(all(vy)); vy.erase(unique(all(vy)), vy.end());

	memset(s, 0, sizeof s);

	rep(i, k) {
		int x1 = lower_bound(all(vx), max(0, p[i].X - t)) - vx.begin();
		int x2 = lower_bound(all(vx), min(w, p[i].X + t + 1)) - vx.begin();
		int y1 = lower_bound(all(vy), max(0, p[i].Y - t)) - vy.begin();
		int y2 = lower_bound(all(vy), min(h, p[i].Y + t + 1)) - vy.begin();
		s[x1][y1]++;
		s[x1][y2]--;
		s[x2][y1]--;
		s[x2][y2]++;
	}

	int minx = inf, maxx = -1, miny = inf, maxy = -1;
	rep(i, sz(vx)-1) rep(j, sz(vy)-1) {
		if(i) s[i][j] += s[i-1][j];
		if(j) s[i][j] += s[i][j-1];
		if(i && j) s[i][j] -= s[i-1][j-1];
		if(s[i][j] == 0)
			smin(minx, vx[i]), smin(miny, vy[j]), smax(maxx, vx[i+1]), smax(maxy, vy[j+1]);
	}

	if(minx == inf) return true;
	return max(maxx - minx, maxy - miny) <= 2 * t + 1;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> w >> h >> k;
	rep(i, k) cin >> p[i].X >> p[i].Y, p[i].X--, p[i].Y--;

	int lo = -1, hi = 1e9;
	while(hi - lo > 1) {
		int md = (lo + hi) / 2;
		if(check(md)) hi = md; else lo = md;
	}

	cout << hi << endl;

	return 0;
}

