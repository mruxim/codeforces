//IN THE NAME OF GOD
//codeforces 274d
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <map>
#include <queue>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <assert.h>
#include <ctime>
#include <bitset>
#include <numeric>
#include <complex>
using namespace std;

#define FOR(i, a, n) for (register int i = (a); i < (int)(n); ++i)
#define Size(n) ((int)(n).size())
#define ll long long
#define pb push_back
#define X first
#define Y second
#define EPS 1e-10
#define mp make_pair
#define MFOR(i,m,n) for(int i=m;i>n;i--)
#define error(x) cerr<<endl<<x<<endl;
#define st cout<<endl;return 0;
#define PI 3.1415926535897932384626433

void error2(const string &s,const int &t){
	cerr<<endl<<"  "<<s<<" = "<<t<<endl;
}

void error3(const string &s,const long double &t){
	cerr<<endl<<"  "<<s<<" = "<<t<<endl;
}

const int MAXINT=2147483647,MAXSINT=32767,N=1000*500+2;
short mrk[N];
bool flag=1;
int temp=N/5;
vector <int> adj[N],way,lc;
vector <pair <int,int> > row;
queue <int> q;

void DFS(int v){
	FOR(i,0,adj[v].size()){
		if(mrk[adj[v][i]]==1){
			cout<<-1<<endl;
			exit (0);
		}
		if(!mrk[adj[v][i]]){
			mrk[adj[v][i]]=1;
			DFS(adj[v][i]);
		}
	}
	way.pb(v);
	mrk[v]=2;
}

int main(){
	ios::sync_with_stdio(false);
	int n,m,t;
	pair <int,int> qs=mp(-1,0);
	cin>>n>>m;
	FOR(i,0,n){
		row.clear();
		FOR(j,0,m){
			cin>>t;
			if(t > -1)
				row.pb(mp(t,j));
		}
		sort(row.begin(),row.end());
		FOR(j,0,Size(row))
			cerr<<j<<"	"<<row[j].X<<"	"<<row[j].Y<<endl;
		FOR(j,0,Size(row)){
			error2("j",j);
			FOR(z,0,Size(lc)){
	//			adj[lc[i]].pb(row[j].Y);
	//			cerr<<lc[i]+1<<" became adjacent to "<<row[j].Y+1<<endl;
			}
			if(row[j].X==qs.X){
				q.push(row[j].Y);
				qs.Y++;
			}
			else{
				lc.clear();
				if(qs.Y>100){
					lc.pb(++temp);
					while(!q.empty()){
						adj[q.front()].pb(temp);
						cerr<<q.front()<<" became adjacent to "<<temp<<endl;
						q.pop();
					}
				}
				if(qs.Y<=100)
					while(!q.empty()){
						error2("q.front()",q.front());
						lc.pb(q.front());
						q.pop();
					}
				qs.X=row[j--].X;
				qs.Y=0;
			}
		}
		row.clear();
		lc.clear();
		qs=mp(-1,0);
		while(!q.empty()){
			error2("q.front() rm",q.front());
			q.pop();
		}
	}
	cerr << "$$$$$$$$$$" << endl;
	FOR(i,0,m)
		if(!mrk[i]){
			mrk[i]=1;
			DFS(i);
		}
	//reverse(way.begin(),way.end());
	FOR(i,0,Size(way))
		cout<<way[i]+1<<" ";
	st;
}
//voroodi:
//2 3
//1 2 -1
//2 -1 1
