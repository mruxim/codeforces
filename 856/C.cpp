#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
using namespace std;

const int MAXN= 2000 + 10;
const int MAXC= 2 * MAXN + 10;
const int mod = 998244353;

int n;
int fact[MAXC];
int C[MAXC][MAXC];
vector <int> Q[2];

inline int add (int x, int y) { int ret = x + y; if (ret >= mod) ret-= mod; return ret; }
inline int mul (int x, int y) { return (long long)x * y % mod; }

vector < vector<int> > go (vector <int> a){
	int n = (int)a.size();
	vector < vector <int> > dp(n+1, vector<int>(11, 0));
	dp[0][0] = 1;
	for (int i=0; i<n; i++){
		vector < vector <int> > t(n+1, vector<int>(11, 0));
		for (int j=0; j<=i; j++)
			for (int r=0; r<11; r++)
				t[j+1][(r+a[i])%11] = add(t[j+1][(r+a[i])%11], dp[j][r]), 
				t[j][(r-a[i]+11)%11]= add(t[j][(r-a[i]+11)%11],dp[j][r]); 
		for (int j=0; j<=n; j++)
			for (int r=0; r<11; r++)
				dp[j][r] = t[j][r];
	}
	return dp;
}

int main(){
	for (int i=0; i<MAXC; i++){
		C[i][0] = 1;
		for (int j=1; j<=i; j++)
			C[i][j] = add(C[i-1][j], C[i-1][j-1]);
	}
	fact[0] = 1;
	for (int i=1; i < MAXN; i++)
		fact[i] = mul(fact[i-1], i);

	int t;
	scanf("%d", &t);
	while(t--) {
		Q[0].clear(); Q[1].clear();
		scanf("%d", &n);
		for (int i=0; i<n; i++){
			int a; scanf("%d", &a);
			int l = 0, temp = a;
			while (temp)
				l^=1, temp/=10;
			Q[l].push_back(a % 11);
		}
		vector < vector<int> > dp0 = go(Q[0]); 
		vector < vector<int> > dp1 = go(Q[1]);
		int even= (int)dp0.size() - 1;
		int odd = (int)dp1.size() - 1;
		int ans = 0;
		for (int i=0; i<=even; i++)
			for (int r=0; r<11; r++){
				int ways = mul(dp0[i][r], dp1[(odd+1)/2][(11-r)%11]);  
				ways = mul(ways, mul(fact[i], mul(fact[even-i], mul(fact[odd/2], fact[(odd+1)/2])))); 
				ways = mul(ways, mul(C[odd/2+i][i], (i==even) ? (1) : (C[(odd+1)/2-1+even-i][even-i])));
				ans = add(ans, ways);
			}
		printf("%d\n", ans);
	}
	return 0;
}
