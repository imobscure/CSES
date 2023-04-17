#include <bits/stdc++.h> 
using namespace std;
 
#define int long long
 
using vi = vector<int>;
#define pb push_back
#define all(x) begin(x), end(x)
#define sz(x) (int) (x).size()
 
using pi = pair<int,int>;
#define f first
#define s second
#define mp make_pair
 
#define re(i,n) for(int i=0;i<n;i++)
#define reb(i,n) for(int i=n-1;i>=0;i--)
#define test int t;cin>>t;while(t--)
 
 
void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); 
	if (sz(name)) {
		freopen((name + ".in").c_str(), "r", stdin); 
		freopen((name + ".out").c_str(), "w", stdout);
	}
}
 
signed main(){
	setIO();
	
	int n; cin>>n;
	vector<pair<pair<int,int>,int>> v(n);
	
	re(i,n)cin>>v[i].f.f>>v[i].f.s>>v[i].s;
	sort(all(v),[](pair<pi,int> a,pair<pi,int> b){return a.f.s<b.f.s;});
	
	set<int> range;
	map<int,int> dp;
	
	range.insert({0,0});
	dp[0]=0;
	int prev=0;
	
	for(int i=0;i<n;i++){
		
		auto it=range.lower_bound(v[i].f.f);
 
		--it;
		
		dp[v[i].f.s]=dp[prev];
		prev=v[i].f.s;
		
		dp[v[i].f.s]=max(dp[v[i].f.s],dp[*it]+v[i].s);
		range.insert(v[i].f.s);

	}
	
	int ans=0;
	for(auto x:dp)ans=max(ans,x.s);
	
	cout<<ans;
}
