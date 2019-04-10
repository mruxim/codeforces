#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

#define X first
#define Y second

typedef pair <int, int> pii;
typedef set<pii>::iterator iter;

int n;
set <pii> up, dw;

bool inside (int x, int y)
{
	if (x < (*dw.begin()).first || x > (*up.rbegin()).first)
		return false;
	pii tmp = pii (x, y);
	iter lb = dw.lower_bound (tmp), ub = dw.upper_bound (tmp);
	;
	return true;
}

void add (int x, int y)
{
	if (inside (x, y))
		return;
	if (x < (*dw.begin()).X)
	{
		iter b = dw.begin(), a = b++;
		while (b != dw.end() && 2 * (*a).Y >= y + (*b).Y)
			a++, b++;
		if (b == dw.end() && 2 * (*a).Y >= y + (-(*up.begin()).Y))
			a++;
		dw.erase (dw.begin(), a);
		dw.insert (pii (x, y));

		b = up.end();
		b--, a = b--;
		if (a != up.begin() && 2 * (-(*a).Y) <= (*dw.begin()).Y + (-(*b).Y))
		{
			
		}
	}
	else if (x > (-(*up.rbegin()).X))
	{
		iter b = up.begin(), a = b++;
		while (b != up.end() && 2 * (-(*a).Y) >= y + (-(*b).Y))
			a++, b++;
		if (b == up.end() && 2 * (-(*a).Y) >= y + (*dw.begin()).Y)
			a++;
		dw.erase (dw.begin(), a);
		/*
		iter b = up.end(), a = (--b)--;
		while (a != up.begin() && 2 * (*a).Y <= y + (*b).Y)
			a--, b--;
		if (!(a == up.begin() && 2 * (*a).Y <= y + (*dw.begin()).Y))
			a++;
		dw.erase (a, up.end());*/
		dw.insert (pii (x, y));
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int t, x, y;
		cin >> t >> x >> y;
		if (t == 1)
			add (x, y);
		else
			inside (x, y);
	}
	{ int _; cin >> _; }
}
