#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
#include <vector>

using namespace std;

#define eps (1e-15)

double X0, Y0;

bool leftTurn (int x1, int y1, int x2, int y2)
{
	return (y1 - Y0) * (x2 - X0) <= (x1 - X0) * (y2 - Y0) + eps;
}

bool sameLine (int x1, int y1, int x2, int y2)
{
	return abs ((y1 - Y0) * (x2 - X0) - (x1 - X0) * (y2 - Y0)) < eps;
}

bool leftTurn (int x0, int y0, int x1, int y1, int x2, int y2)
{
	return (long long)(y1 - y0) * (x2 - x0) <= (long long)(x1 - x0) * (y2 - y0) + eps;
}

struct point {
	int x, y;
	bool operator < (const point &p) const
	{
		return abs (atan2 (y - Y0, x - X0) - atan2 (p.y - Y0, p.x - X0)) < eps
				? (p.x-X0)*(p.x-X0) + (p.y-Y0)*(p.y-Y0) < (p.x-X0)*(p.x-X0) + (p.y-Y0)*(p.y-Y0)
				: atan2 (y - Y0, x - X0) < atan2 (p.y - Y0, p.x - X0);
	}
//	(x == X0 && y == Y0) ? 1 : (p.x == X0 && p.y == Y0) ? 0 : 	
};

int n;
set <point> p;
point v[1000000 + 5];
int sz;

bool inside (point tmp)
{
	set<point>::iterator it, it1 = p.begin(), it2 = p.end();
	it2--;
	if (leftTurn (it2->x, it2->y, tmp.x, tmp.y) && leftTurn (tmp.x, tmp.y, it1->x, it1->y))
		return leftTurn (it1->x, it1->y, tmp.x, tmp.y, it2->x, it2->y);
	it = p.upper_bound (tmp);
	if (it == p.end()) it = p.begin();
	it1 = it;
	if (sameLine (it->x, it->y, tmp.x, tmp.y))
		return (tmp.x-X0)*(tmp.x-X0) + (tmp.y-Y0)*(tmp.y-Y0) <= (long long)(it->x-X0)*(it->x-X0) + (it->y-Y0)*(it->y-Y0);
	it--;
	return leftTurn (it1->x, it1->y, tmp.x, tmp.y, it->x, it->y);
}

void add (point tmp)
{
	if (inside (tmp))
		return;
	set<point>::iterator it, it1 = p.begin(), it2 = p.end();
	it2--;
/*	if (leftTurn (it2->x, it2->y, tmp.x, tmp.y) && leftTurn (tmp.x, tmp.y, it1->x, it1->y))
	{
		it = it2--;
		while (leftTurn (tmp.x, tmp.y, it->x, it->y, it2->x, it2->y))
			it--, it2--;
		it++;
		p.erase (it, p.end());
		it2 = p.begin();
		it = it2++;
		while (leftTurn (it2->x, it2->y, it->x, it->y, tmp.x, tmp.y))
			it++, it2++;
		p.erase (p.begin(), it);
		p.insert (tmp);
		return;
	}*/
#define plus(IT) (++(IT)==p.end()?(IT)=p.begin():(IT)=(IT))
#define minus(IT) (((IT)==p.begin()?(IT)=p.end():(IT)=(IT)),(IT)--)
	it1 = p.upper_bound (tmp);
	if (it1 == p.end())
		it1 = p.begin();
	it2 = it1;
	if (!sameLine (it1->x, it1->y, tmp.x, tmp.y))
		minus(it1);
	it = it2;
	plus(it2);
	sz = 0;
	while (leftTurn (it2->x, it2->y, it->x, it->y, tmp.x, tmp.y))
		v[sz++] = *it, plus(it), plus(it2);
	it = it1;
	minus (it1);
	while (leftTurn (tmp.x, tmp.y, it->x, it->y, it1->x, it1->y))
		v[sz++] = *it, minus(it), minus(it1);
	for (int i = 0; i < sz; i++)
		p.erase (v[i]);
	p.insert (tmp);
}

int main()
{
	cin >> n;
	int t;
	point tmp, tmp1, tmp2, tmp3;
	cin >> t >> tmp1.x >> tmp1.y; X0 += tmp1.x, Y0 += tmp1.y;
	cin >> t >> tmp2.x >> tmp2.y; X0 += tmp2.x, Y0 += tmp2.y;
	cin >> t >> tmp3.x >> tmp3.y; X0 += tmp3.x, Y0 += tmp3.y;
	X0 /= 3, Y0 /= 3;
	p.insert (tmp1);
	p.insert (tmp2);
	p.insert (tmp3);
/*			cout << " *** ";
			for (set <point>::iterator it = p.begin(); it != p.end(); it++)
				cout << "(" << (*it).x << ", " << (*it).y << ") ";
			cout << endl;*/
	for (int i = 3; i < n; i++)
	{
		cin >> t >> tmp.x >> tmp.y;
		if (t == 1)
		{
			add (tmp);
/*			cout << " *** ";
			for (set <point>::iterator it = p.begin(); it != p.end(); it++)
				cout << "(" << (*it).x << ", " << (*it).y << ") ";
			cout << endl;*/
		}
		else
			cout << (inside (tmp) ? "YES" : "NO") << endl;
	}
	{ int _; cin >> _; }
}
