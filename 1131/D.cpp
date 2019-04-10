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

const int maxn = 1000 + 10;

int n, m;
string f[maxn];
pii a[maxn], b[maxn];
int ar[maxn], br[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m;
	rep(i, n) cin >> f[i];

	rep(i, n) a[i].Y = i;
	rep(i, m) b[i].Y = i;
	
	rep(i, n) rep(j, m) {
		if(f[i][j] == '>') a[i].X++;
		else if(f[i][j] == '<') b[j].X++;
	}

	sort(a, a + n);
	sort(b, b + m);

	int ap = 0, bp = 0;
	int cur = 1;
	
	while(ap < n || bp < m) {
		if(ap > 0 && ap < n && a[ap].X == a[ap-1].X) { ar[a[ap].Y] = ar[a[ap-1].Y], ap++; continue; }
		if(bp > 0 && bp < m && b[bp].X == b[bp-1].X) { br[b[bp].Y] = br[b[bp-1].Y], bp++; continue; }
		if(ap < n && bp < m && f[a[ap].Y][b[bp].Y] == '=') {
			ar[a[ap++].Y] = cur;
			br[b[bp++].Y] = cur;
			cur++;
		}
		else if(ap < n && (bp == m || f[a[ap].Y][b[bp].Y] == '<'))
			ar[a[ap++].Y] = cur++;
		else
			br[b[bp++].Y] = cur++;
	}

	bool ok = true;

	rep(i, n) rep(j, m)
		ok &=	(f[i][j] == '=' && ar[i] == br[j]) ||
				(f[i][j] == '>' && ar[i] > br[j])  ||
				(f[i][j] == '<' && ar[i] < br[j]);

	cout << (ok ? "Yes" : "No") << endl;
	if(ok) {
		rep(i, n) cout << (i ? " " : "") << ar[i];
		cout << endl;
		rep(i, m) cout << (i ? " " : "") << br[i];
		cout << endl;
	}

	return 0;
}

