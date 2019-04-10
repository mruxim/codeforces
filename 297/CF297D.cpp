// .... .... .... !

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cassert>

#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define all(X) (X).begin(),(X).end()

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 1000 + 100;

int n, m, k;
char a[maxn][maxn], b[maxn][maxn];
int tot, cnt;
int s[maxn][maxn];

int main() {
	ios::sync_with_stdio (false);

	cin >> n >> m >> k;
	rep(i, n) {
		rep(j, m-1) cin >> a[i][j], cnt += (a[i][j] == 'E');
		if (i < n-1)
			rep(j, m) cin >> b[i][j], cnt += (b[i][j] == 'E');
	}
	if (k == 1) {
		tot = n * (m-1) + (n-1) * m;
		if (cnt * 4 >= tot * 3) {
			cout << "YES" << endl;
			rep(i, n) {
				rep(j, m) cout << "1 ";
				cout << endl;
			}
		}
		else
			cout << "NO" << endl;
	}
	else {
		bool swp = false;
		if(n > m) {
			swap(n, m);
			rep(i, m) rep(j, m) swap(a[i][j], b[j][i]);
			swp = true;
		}
		cout << "YES" << endl;
		rep(i, n) {
			rep (j, m)
				s[i][j] = (i ? (b[i-1][j] == 'E' ? s[i-1][j] : 3 - s[i-1][j]) : (j == 0 ? 1 : (a[i][j-1] == 'E' ? s[i][j-1] : 3 - s[i][j-1])));
			rep(j, m-2)
				if (((s[i][j] == s[i][j+1]) ^ (a[i][j] == 'E')) && (((s[i][j+1] == s[i][j+2]) ^ (a[i][j+1] == 'E'))))
					s[i][j+1] = 3 - s[i][j+1];
		}
		if (swp) {
			rep(i, m) rep(j, m) swap(a[i][j], b[j][i]);
			rep(i, m) rep(j, i) swap(s[i][j], s[j][i]);
			swap(n, m);
		}
		rep(i, n)
		{
			rep(j, m) cout << s[i][j] << ' ';
			cout << endl;
		}
	}

	{ int _; cin >> _; return 0; }
}
