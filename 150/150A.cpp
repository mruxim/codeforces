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

ll n;
ll x, y;
int a, b;

int main()
{
	cin >> n;
	for (ll i = 2; i * i <= n; i++)
		if (n % i == 0)
		{
			x = i;
			while (n % i == 0) n /= i, a++;
			break;
		}
	for (ll i = 2; i * i <= n; i++)
		if (n % i == 0)
		{
			y = i;
			while (n % i == 0) n /= i, b++;
			break;
		}
	if (n > 1 && a == 0) a = 1, x = n, n = 1;
	if (n > 1 && b == 0) b = 1, y = n, n = 1;
	if (b == 0)
	{
		if (a == 1) { cout << 1 << endl << 0 << endl; }
		else if (a == 2) { cout << 2 << endl; }
		else { cout << 1 << endl << x*x << endl; }
	}
	else
	{
		if (a == 1 && b == 1 && n == 1) { cout << 2 << endl; }
		else { cout << 1 << endl << x * y << endl; }
	}
	{ int _; cin >> _; }
}
