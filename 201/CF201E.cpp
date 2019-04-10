// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int((x).size()))
#define cmx(a, b) (a = max(a,b))
#define cmn(a, b) (a = min(a,b))
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

////////////////////////////////////////////////

int x;

int f (int a, int b)
{
	return (a*b+1) / 2;
}

bool ok (int n)
{
	if (x == 3 && n == 3) return false;
	if (n % 2 == 0 && x % 4) return false;
	if (n % 2 == 0)
	{
		if (x / 4 <=  f (n/2-1, n/2-1))
			return true;
		return false;
	}
	int z = f (n, n);
	if (x > z) return false;
	return true;
}

int main()
{
	cin >> x;
	fer (i, 1, 100000)
		if (ok (i))
		{
			cout << i << endl;
			break;
		}
	{ int _; cin >> _; }
}
