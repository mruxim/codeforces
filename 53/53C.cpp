#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int n;

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		if (i & 1)
			cout << n - i / 2 << ' ';
		else
			cout << i / 2 + 1 << ' ';
	{ int _; cin >> _; }
}
