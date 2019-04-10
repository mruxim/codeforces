// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define fer(i, x, n) for (int i = (x), _n = (n); i < _n; i++)
#define all(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define cmx(a, b) a = max(a,b)
#define cmn(a, b) a = min(a,b)
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

////////////////////////////////////////////////

const ll mod = 1000000007LL;

int n, m, k;

ll pow (ll a, int b)
{
	if (b == 0) return 1;
	ll t = pow (a, b/2);
	t *= t;
	t %= mod;
	if (b & 1) t *= a;
	return t % mod;
}

int main()
{
	cin >> n >> m >> k;
	if (n == 1) cout << m % mod << endl;
	else if (k > n) cout << pow (m, n) << endl;
	else if (k == n) cout << pow (m, (n+1)/2) << endl;
	else if (k % 2 == 0) cout << m % mod << endl;
	else cout << pow (m, 2) << endl;
	{ int _; cin >> _; }
}
