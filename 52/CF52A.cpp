#include <iostream>
#include <string>

using namespace std;

const int MAXn = 1000000 + 100;

int n;
int s[MAXn];
int p[5];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++)
		p[s[i]]++;
	cout << n - max (p[1], max (p[2], p[3])) << endl;
	{ int _; cin >> _;}
}
