#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int a[4];

int main()
{
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	while ((a[0] | a[1] | a[2] | a[3]) > 1)
	{
		up:
		for (int i = 0; i < 4; i++)
			if (a[i] % 2 == 0 && a[(i+1)%4] % 2 == 0)
			{
				cout << "/" << i+1 << endl;
				a[i] /= 2, a[(i+1)%4] /= 2;
				goto up;
			}
		
	}
	{ int _; cin >> _; }
}
