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

const int maxn = 200000 + 100;

int n, m, k;
int a[maxn];
pii b[maxn];
int mark[maxn];

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n >> m >> k;
	rep(i, n) cin >> a[i], b[i] = pii(a[i], i);
	sort(b, b+n);
	ll sum = 0;
	fer(i, n-m*k, n) sum += b[i].X, mark[b[i].Y] = 1;
	cout << sum << endl;
	int s = 0;
	rep(i, k-1) {
		int e = s, cnt = 0;
		while(cnt < m)
			cnt += mark[e++];
		s = e;
		cout << s << ' ';
	}
	cout << endl;

	return 0;
}

