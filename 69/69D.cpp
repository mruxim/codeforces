#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAXn = 20 + 3;

int n, d;
int vx[MAXn], vy[MAXn];
char s[500][500];

bool win (int x, int y)
{
	if (x*x + y*y > d*d) return 1;
	char &p = s[x+250][y+250];
	if (p != 0) return p-1;
	for (int i = 0; i < n; i++)
		if (!win (x + vx[i], y + vy[i]))
			return (p = 2) - 1;
	return (p = 1) - 1;
}

int main()
{
	int x, y;
	cin >> x >> y >> n >> d;
	for (int i = 0 ; i < n; i++)
		cin >> vx[i] >> vy[i];
	cout << (win (x, y) ? "Anton" : "Dasha") << endl;
	{ int _; cin >> _; }
}

