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

const int maxn = 400000 + 100;

int n, m;
int a[maxn];
int cnt[maxn];
int tmp[maxn];
int minb, maxb;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	cin >> n;
	rep(i, n) cin >> a[i];
	cin >> m;
	minb = n, maxb = -1;
	rep(i, m) {
		int x; cin >> x, x--;
		cnt[x]++;
	}

	bool allsame = true;
	rep(i, n-2) if(a[i+1] - a[i] != a[i+2] - a[i+1]) allsame = false;

	int cm = min(cnt[0], cnt[n-1]);
	rep(i, n-2) smin(cm, cnt[i+1] / 2);
	ll add = cm * 2LL * (a[n-1] - a[0]);
	cnt[0] -= cm; cnt[n-1] -= cm;
	rep(i, n-2) cnt[i+1] -= 2 * cm;

	if(count(cnt, cnt+n, 0) == n) {
		if(allsame)
			cout << (a[1] - a[0]) * (ll)(m-1) << endl;
		else
			cout << -1 << endl;
		return 0;
	}

	rep(i, n) if(cnt[i]) smin(minb, i), smax(maxb, i);

	if(*max_element(cnt, cnt+n) == 1) {
		cout << add + a[maxb] - a[minb] << endl;
		return 0;
	}

	if(cnt[0] == 0) {
		rep(i, n-1) add += cnt[i] * (a[i+1] - a[i]);
		cout << add << endl;
		return 0;
	}
	if(cnt[n-1] == 0) {
		fer(i, 1, n) add += cnt[i] * (a[i] - a[i-1]);
		cout << add << endl;
		return 0;
	}
	
	minb = n, maxb = -1;
	fer(i, 1, n-1) if(cnt[i] == 1) smin(minb, i), smax(maxb, i);

	add += a[n-1] - a[0];
	add += a[minb-1] - a[0];
	add += a[n-1] - a[maxb+1];

	cout << add << endl;

	return 0;
}

