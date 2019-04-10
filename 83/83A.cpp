#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAXn = 100 * 1000 + 100;

int n;
int a[MAXn];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	long long r = 0, p = 1;
	for (int i = 1; i < n; i++)
		if (i && a[i] == a[i-1])
			p++;
		else
			r += p * (p+1) / 2, p = 1;
	r += p * (p+1) / 2;
	cout << r << endl;
	{ int _; cin >> _; }
}
