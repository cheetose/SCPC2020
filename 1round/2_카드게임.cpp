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

int a[3001],b[3001];
int la[3001],lb[3001];
int d[3001][3001];
int p[3001],cnt[3001];
void solve(){
	int n,k;
	scanf("%d%d",&n,&k);
	fup(i,1,n,1)scanf("%d",a+i);
	fup(i,1,n,1)scanf("%d",b+i);
	fup(i,0,n,1)p[i]=0,cnt[i]=0;
	int ii=1,now=0;
	fup(i,1,n,1){
		now+=a[i];
		while(now>k){
			now-=a[ii++];
		}
		la[i]=ii-1;
	}
	ii=1,now=0;
	fup(i,1,n,1){
		now+=b[i];
		while(now>k){
			now-=b[ii++];
		}
		lb[i]=ii-1;
	}
	fup(i,0,n,1){
		int p2=0;
		int cc=0;
		fup(j,0,n,1){
			if(i==0 && j==0){
				d[i][j]=0;
			}else{
				while(p2<lb[j]){
					if(d[i][p2]==1)cc--;
					p2++;
				}
				while(p[j]<la[i]){
					if(d[p[j]][j]==1)cnt[j]--;
					p[j]++;
				}
				if(cc+cnt[j]>0)d[i][j]=0;
				else d[i][j]=1;
				if(d[i][j]==1){
					cnt[j]++;
					cc++;
				}
			}
		}
	}
	int ans[2]={0};
	fup(i,0,n,1)fup(j,0,n,1)ans[d[i][j]]++;
	printf("%d %d\n",ans[0],ans[1]);
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