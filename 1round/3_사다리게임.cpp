#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define y0 y12
#define y1 y22
#define INF 987654321
#define PI 3.141592653589793238462643383279502884
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define ALL(a) a.begin(),a.end()
#define SYNC ios_base::sync_with_stdio(false);cin.tie(0)
using namespace std;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll> Pll;
typedef pair<ld, ld> Pd;
typedef vector<int> Vi;
typedef vector<ll> Vll;
typedef vector<double> Vd;
typedef vector<Pi> VPi;
typedef vector<Pll> VPll;
typedef vector<Pd> VPd;
typedef tuple<int, int, int> iii;
typedef tuple<int,int,int,int> iiii;
typedef tuple<ll, ll, ll> LLL;
typedef vector<iii> Viii;
typedef vector<LLL> VLLL;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

int d[1501][1501];
int dist[7001],ne[7001];
int n,k,q;
VPi v[7001];
Vi vv[1501];
void bfs(int N){
	fup(i,1,2*(n+k),1)dist[i]=-1;
	deque<int> q;
	dist[N]=0;
	q.push_back(N);
	while(!q.empty()){
		int x=q.front();
		q.pop_front();
		for(Pi p:v[x]){
			auto [next,cost]=p;
			if(dist[next]==-1 || dist[next]>dist[x]+cost){
				dist[next]=dist[x]+cost;
				if(cost==0)q.push_front(next);
				else q.push_back(next);
			}
		}
	}
}
int op(int x){
	if(n&1){
		return x^1;
	}else{
		return ((x-1)^1)+1;
	}
}
void solve(){
	scanf("%d%d%d",&n,&k,&q);
	fup(i,1,n,1)fup(j,1,n,1)d[i][j]=-1;
	fup(i,1,n,1)vv[i].clear();
	fup(i,1,2*(n+k),1)v[i].clear();
	fup(i,1,n,1)vv[i].pb(i);
	fup(i,1,k,1){
		int x,y;
		scanf("%d%d",&x,&y);
		int t1=n+i*2-1,t2=n+i*2;
		vv[x].pb(t1);
		vv[y].pb(t2);
	}
	fup(i,1,n,1)vv[i].pb(n+2*k+i);
	fup(i,1,n,1){
		int N=vv[i].size();
		fup(j,0,N-2,1){
			ne[vv[i][j]]=vv[i][j+1];
			v[vv[i][j]].pb(mp(vv[i][j+1],(j==0)?0:1));
		}
	}
	fup(i,1,n,1){
		int N=vv[i].size();
		fup(j,1,N-2,1){
			v[vv[i][j]].pb(mp(ne[op(vv[i][j])],0));
		}
	}
	fup(i,1,n,1){
		bfs(i);
		fup(j,1,n,1){
			d[i][j]=dist[n+2*k+j];
		}
	}
	int ans=0;
	while(q--){
		int x,y;
		scanf("%d%d",&x,&y);
		ans+=d[x][y];
	}
	printf("%d\n",ans);
}
int main(){
	setbuf(stdout, NULL);
	int tc;
	scanf("%d",&tc);
	fup(TT,1,tc,1){
		printf("Case #%d\n",TT);
		solve();
	}
}