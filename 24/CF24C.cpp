#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAXn = 1000 * 1000 + 100;

int n, k;
long long z;
int mx, my;
int ax[MAXn], ay[MAXn];

int main()
{
	cin >> n >> z;
	cin >> mx >> my;
	for (int i = 0; i < n; i++)
		cin >> ax[i] >> ay[i];
	k = (int)(z % (long long)(2 * n));
	for (int i = 0; i < k; i++)
		mx = 2 * ax[i%n] - mx, my = 2 * ay[i%n] - my;
	cout << mx << ' ' << my << endl;
	{ int _; cin >> _; }
}
