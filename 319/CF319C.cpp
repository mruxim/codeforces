// .... .... .....!
// P..... C.....!

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
#include <cmath>
#include <numeric>

#include <cstdio>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define sz(x) (int((x).size()))
#define pb push_back
#define mkp make_pair
#define all(X) (X).begin(),(X).end()

#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;

////////////////////////////////////////////////////////////////////////////////

const int maxn = 100000 + 100;

int n;
int a[maxn], b[maxn];
ll dp[maxn];

int s[maxn], head, tail;

int when(int x, int y) {
	return (dp[x] - dp[y] + (b[y] - b[x]) - 1) / (b[y] - b[x]);
}

int main() {
	ios_base::sync_with_stdio (false);

	cin >> n;
	rep (i, n) cin >> a[i];
	rep (i, n) cin >> b[i];

	dp[0] = b[0];

	head = tail = 0;
	s[tail++] = 0;

	fer(i, 1, n) {		
		while(head+1 < tail && dp[s[head+1]] + a[i] * (ll)b[s[head+1]] <= dp[s[head]] + a[i] * (ll)b[s[head]]) head++;
		dp[i] = dp[s[head]] + (a[i]-1) * (ll)b[s[head]] + b[i];
		while(tail-head >= 2 && when (i, s[tail-1]) <= when(s[tail-1], s[tail-2])) tail--;
		s[tail++] = i;
	}

	cout << dp[n-1] << endl;

	{ int _; cin >> _; return 0; }
}
