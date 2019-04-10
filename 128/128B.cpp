#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

const int MAXn = 100 * 1000 + 100;

string s;
int n, k;
int len[MAXn];
int h[MAXn], z;

bool les (int x, int y)
{
	if (x + len[x] > n) return true;
	if (y + len[y] > n) return false;
	if (len[x] == len[y])
		return s[x+len[x]-1] < s[y+len[y]-1];
	int ml = min (len[x], len[y]) - 1;
	return s[x+ml] != s[y+ml] ? s[x+ml] < s[y+ml] : len[x] < len[y];
}

void push (int x)
{
	h[++z] = x;
	int r = z;
	while (r > 1 && les (h[r], h[r/2]))
		swap (h[r], h[r/2]), r /= 2;
}

void pop ()
{
	int x = h[1];
	len[x]++;
	if (x + len[x] > n)
		h[1] = h[z--];
	int c = 1, f;
	while (c * 2 <= z)
	{
		if (c * 2 + 1 <= z)
			f = les (h[c*2], h[c*2+1]) ? c*2 : c*2+1;
		else
			f = c*2;
		if (les (h[f], h[c]))
			swap (h[f], h[c]), c = f;
		else
			break;
	}
}

int main()
{
	cin >> s >> k;
	n = s.length();
	if (k > (long long)n*(n+1)/2)
	{
		cout << "No such line." << endl;
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		len[i] = 1;
		push (i);
	}
	for (int i = 1; i < k; i++)
		pop ();
	int r = h[1];
	cout << s.substr (r, len[r]) << endl;
	{ int _; cin >> _; }
}
