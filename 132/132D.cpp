#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAXn = 1000 * 1000 + 100;

int n;
int r[MAXn];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
		r[i] = min (r[i/2], r[(i+1)/2]) + i%2;
	cout << r[n] << endl;
	for (int i = 0; n; i++)
		if (n % 2 == 1)
			if (r[n] == r[n/2])
				cout << "+2^" << i << endl, n /= 2;
			else
				cout << "-2^" << i << endl, n = (n+1) / 2;
	{ int _; cin >> _; }
}
