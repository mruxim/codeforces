#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int MAXn = 100000 + 100;

int n;
int a[MAXn];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort (a, a + n);
	if (a[n-1] > 1)
		a[n-1] = 1;
	else
		a[n-1] = 2;
	sort (a, a + n);
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
	{ int _; cin >> _; }
}
