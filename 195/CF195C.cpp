// .... .... .... !

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>

using namespace std;

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)
#define fer(i, x, n) for (int i = (int)(x), _n = (int)(n); i < _n; i++)
#define rof(i, n, x) for (int i = (int)(n), _x = (int)(x); i-- > _x; )
#define fch(i, x) for (__typeof(x.begin()) i = x.begin(); i != x.end(); i++)
#define all(x) x.begin(), x.end()
#define sz(x) (int((x).size()))
#define cmx(a, b) (a = max(a,b))
#define cmn(a, b) (a = min(a,b))
#define pb push_back
#define mp make_pair
#define X first
#define Y second

typedef long long ll;
typedef pair <int, int> pii;
typedef vector <int> vi;

////////////////////////////////////////////////

int n;
char s[100009][55];
int len[100009];
int st[100009], top;
char ex[55];
int el, dep, pos;
char px[55];
int pl;
bool yes;

int main()
{
	scanf ("%d ", &n);
	rep (i, n) gets (s[i]);
	rep (i, n) len[i] = strlen(s[i]);

//	rep (i, n) puts (s[i]);
	
	rep (i, n)
	{
		int k = 0; char* t = s[i];
		while (k < len[i] && t[k] == ' ') k++;
		if (k == len[i]) continue;
		if (t[k] == 't' && t[k+1] == 'r')
			{ top++; continue; }
		if (t[k] == 'c')
		{
			if (top > dep)
				{ top--; continue; }
			if (top == dep && yes)
				{ top--; continue; }
			if (top == dep) yes = true;
			while (t[k] != '(') k++;
			for (k++; t[k] == ' '; k++);
			pl = 0;
			while (t[k] != ' ' && t[k] != ',')
				px[pl++] = t[k++];
			if (el == pl && strcmp (ex, px) == 0)
			{
				while (t[k] != ',') k++;
				for (k++; t[k] != '"'; k++);
				k++;
				pl = 0;
				while (t[k] != '"')
					px[pl++] = t[k++];
				px[pl] = 0;
				puts (px);
				goto hell;
			}
			
			{ top--; continue; }
		}

		while (t[k] != '(') k++;
		for (k++; t[k] == ' '; k++);
		while (t[k] != ' ' && t[k] != ')')
			ex[el++] = t[k++];
		dep = top;
		yes = false;
	}
	puts ("Unhandled Exception");
	hell:
	{ int _; cin >> _; }
}
