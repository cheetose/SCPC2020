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

int tree[131072], lazy[131072];
void init(int node, int S, int E)
{
	tree[node]=lazy[node]=0;
	if (S == E)return;
	init(2 * node, S, (S + E) / 2);
	init(2 * node + 1, (S + E) / 2 + 1, E);
}
void propagation(int node, int S, int E)
{
	if (lazy[node] != 0)
	{
		tree[node] += lazy[node];
		if (S != E)
		{
			lazy[2 * node] += lazy[node];
			lazy[2 * node + 1] += lazy[node];
		}
		lazy[node] = 0;
	}
}
void upd(int node, int S, int E, int i, int j, ll val)
{
	propagation(node, S, E);
	if (i > E || j < S) return;
	if (j >= E && i <= S)
	{
		lazy[node] += val;
		propagation(node,S,E);
		return;
	}
	upd(2 * node, S, (S + E) / 2, i, j, val);
	upd(2 * node + 1, (S + E) / 2 + 1, E, i, j, val);
	tree[node] = max(tree[2 * node], tree[2 * node + 1]);
}
int find(int node, int S, int E, int i, int j)
{
	propagation(node, S, E);
	if (i > E || j < S) return -INF;
	if (j >= E && i <= S) return tree[node];
	return max(find(node * 2, S, (S + E) / 2, i, j), find(2 * node + 1, (S + E) / 2 + 1, E, i, j));
}
char s[50005];
int a[50005];
void solve(){
	Viiii v;
	int n,k,m;
	scanf("%d%d%d%s",&n,&k,&m,s);
	init(1,0,n-1);
	int mod=1;
	fup(i,1,k,1)mod*=10;
	fup(i,0,n-1,1)a[i]=s[i]-'0';
	ll c=0;
	fup(i,0,k-2,1)c=(c*10+a[i]);
	fup(i,k-1,n-1,1){
		c=(c*10+a[i])%mod;
		v.pb(iiii((int)c,1,i-k+1,i));
	}
	fup(i,0,n-1,1){
		int tmp=a[i];
		a[i]=1;
		ll cc=0;
		fup(j,i-k+1,i-1,1)cc=cc*10+a[j];
		fup(j,i,min(n-1,i+k-1),1){
			cc=(cc*10+a[j])%mod;
			if(j>=k-1){
				v.pb(iiii((int)cc,0,i,i));
			}
		}
		a[i]=tmp;
	}
	sort(ALL(v));
	int N=v.size();
	int j=0,cnt=0;
	int ans=0;
	fup(i,0,N-1,1){
		auto [cc,t,l,r]=v[i];
		cnt+=t;
		if(t==1)upd(1,0,n-1,l,r,-1);
		else upd(1,0,n-1,l,l,1);
		while(j<i && get<0>(v[j])<cc-m){
			auto [c2,t2,l2,r2]=v[j];
			cnt-=t2;
			if(t2==1)upd(1,0,n-1,l2,r2,1);
			else upd(1,0,n-1,l2,l2,-1);
			j++;
		}
		int res=max(0,find(1,0,n-1,0,n-1));
		ans=max(ans,res+cnt);
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