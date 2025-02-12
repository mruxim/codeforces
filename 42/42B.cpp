#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>

using namespace std;

int x1, y1, x2, y2, wx, wy, x, y;
int a[11][11];

int main()
{
	string p;
	cin >> p; x1 = p[0] - 'a', y1 = p[1] - '1';
	cin >> p; x2 = p[0] - 'a', y2 = p[1] - '1';
	cin >> p; wx = p[0] - 'a', wy = p[1] - '1';
	cin >> p; x = p[0] - 'a', y = p[1] - '1';

	a[wx][wy] = -1;

	for (int i = x1-1; i >= 0 && a[i][y1] >= 0; i--) a[i][y1]++;
	for (int i = x1+1; i < 8 && a[i][y1] >= 0; i++) a[i][y1]++;
	for (int i = y1-1; i >= 0 && a[x1][i] >= 0; i--) a[x1][i]++;
	for (int i = y1+1; i < 8 && a[x1][i] >= 0; i++) a[x1][i]++;

	for (int i = x2-1; i >= 0 && a[i][y2] >= 0; i--) a[i][y2]++;
	for (int i = x2+1; i < 8 && a[i][y2] >= 0; i++) a[i][y2]++;
	for (int i = y2-1; i >= 0 && a[x2][i] >= 0; i--) a[x2][i]++;
	for (int i = y2+1; i < 8 && a[x2][i] >= 0; i++) a[x2][i]++;
	
	if(wy > 0) a[wx][wy-1]++;
	a[wx][wy+1]++;
	if(wx > 0) a[wx-1][wy]++;
	a[wx+1][wy]++;
	if (wx > 0 && wy > 0) a[wx-1][wy-1]++;
	if (wx > 0) a[wx-1][wy+1]++;
	if (wy > 0) a[wx+1][wy-1]++;
	a[wx+1][wy+1]++;

	if ((!a[x][y]) || (x>0&&!a[x-1][y]) || (x>0&&y>0&&!a[x-1][y-1]) || (x>0&&y<7&&!a[x-1][y+1]) ||
		(y>0&&!a[x][y-1]) || (y<7&&!a[x][y+1]) || (x<7&&y>0&&!a[x+1][y-1]) || (x<7&&!a[x+1][y]) ||
		(x<7&&y<7&&!a[x+1][y+1]))
		puts ("OTHER");
	else
		puts ("CHECKMATE");
	{ int _; cin >> _; }
}
