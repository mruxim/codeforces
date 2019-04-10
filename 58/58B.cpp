#include <iostream>

using namespace std;

const int MAXn = 1000000 + 100;

int n;
int h[MAXn], d[MAXn];

int gcd (int a, int b)
{
	return a==0 ? b : gcd (b%a, a);
}

int main()
{
	cin >> n;
	h[1] = 1;
	for (int i = 1; i <= n; i++)
		for (int j = i*2; j <= n; j += i)
			if (h[i] + 1 >= h[j])
				h[j] = h[i] + 1, d[j] = i;
	int k = n;
	while (k > 1)
	{
		cout << k << ' ';
		k = d[k];
	}
	cout << 1 << endl;
	int g;
	cout << n << ' ';
	while (n > 1)
	{
		for (g = n / 2; n % g; g--);
		n = g;
		cout << n << ' ';
	}
	cout << endl;
	{ int _; cin >> _; }
}
