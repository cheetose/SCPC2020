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
typedef vector<iiii> Viiii;
typedef complex<double> base;
const int MOD = 1000000007;
ll POW(ll a, ll b, ll MMM=MOD) {ll ret=1; for(;b;b>>=1,a=(a*a)%MMM)if(b&1)ret=(ret*a)% MMM; return ret; }
ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll lcm(ll a, ll b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[] = { 0,1,0,-1,1,1,-1,-1 }, dy[] = { 1,0,-1,0,1,-1,1,-1 };
int ddx[]={2,2,-2,-2,1,1,-1,-1},ddy[]={1,-1,1,-1,2,-2,2,-2};

struct PP{
	ll x,y;
	ld p;
}P[200000];
ld pr[200000][18];
ld mul(int l,int r){
	int t=r-l+1;
	ld res=1;
	fdn(i,17,0,1){
		if(t&(1<<i)){
			res*=pr[l][i];
			l+=(1<<i);
		}
	}
	return res;
}
void solve(){
	int n;
	cin>>n;
	fup(i,0,n-1,1)cin>>P[i].x;
	fup(i,0,n-1,1)cin>>P[i].y;
	fup(i,0,n-1,1)cin>>P[i].p;
	ll x_,y_;
	cin>>x_>>y_;
	fup(i,0,n-1,1)P[i].x-=x_,P[i].y-=y_;
	int tt=0;
	sort(P,P+n,[&](PP p1,PP p2){
		if(p1.x>=0 && p2.x<0)return false;
		if(p1.x<0 && p2.x>=0)return true;
		return p2.y*(p2.x-p1.x)<p2.x*(p2.y-p1.y);
	});
	fup(i,n,2*n-1,1)P[i]=P[i-n];
	fup(i,0,2*n-1,1)pr[i][0]=1-P[i].p;
	fup(j,0,16,1){
		fup(i,0,2*n-1,1){
			if(i+(1<<(j+1))>2*n)break;
			pr[i][j+1]=pr[i][j]*pr[i+(1<<j)][j];
		}
	}
	ld ans=mul(0,n-1);
	int j=0;
	fup(i,0,n-1,1){
		if(j<=i)j=i+1;
		while(P[j].y*(P[j].x-P[i].x)<P[j].x*(P[j].y-P[i].y))j++;
		ld tt=mul(j,i+n-1)*P[i].p;
		ans+=tt;
	}
	cout<<1.0-ans<<'\n';
}
int main(){
	SYNC;
	cout<<fixed<<setprecision(9);
	int tc;
	cin>>tc;
	fup(TT,1,tc,1){
		cout<<"Case #"<<TT<<'\n';
		solve();
	}
}