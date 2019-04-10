// .... .... .....!
// ...... ......!
// .... ....... ..... ..!

#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define sz(x) (int((x).size()))
#define pb push_back
#define all(X) (X).begin(),(X).end()
#define X first
#define Y second

template<class T> inline void smin(T &a, T b){if(b<a)a=b;}
template<class T> inline void smax(T &a, T b){if(a<b)a=b;}

typedef long long ll;
typedef pair<int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 1000000 + 100;
const int maxx = 10000000 + 100;

int n;
bool np[maxx];
int cnt[maxx];
int ans[maxx];
int sum[maxx];

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) {
		int x;
		cin >> x;
		cnt[x]++;
	}

	fer (i, 2, maxx) if (!np[i]) {
		ans[i] += cnt[i];
		for (int j = i+i; j < maxx; j += i) {
			np[j] = true;
			ans[i] += cnt[j];
		}
	}

	fer (i, 1, maxx) sum[i] = sum[i-1] + ans[i-1];

	int m;
	cin >> m;

	while (m--) {
		int l, r;
		cin >> l >> r; r++;
		cout << sum[r] - sum[l] << endl;
	}

	{ return 0; }
}


