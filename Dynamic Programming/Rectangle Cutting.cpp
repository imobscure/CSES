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

	int a,b; cin>>a>>b;
	vector<vector<int>> dp(501,vector<int>(501,-1));

	auto solve = [&](auto&& solve,int x,int y)->int{

		if(x<=0 || y<=0)return LLONG_MAX;
		if(x==y)return 0ll;

		if(dp[x][y]!=-1)return dp[x][y];

		int find = LLONG_MAX;

		for(int i=1;i<x;i++){
			find = min(find,solve(solve,x-i,y)+solve(solve,i,y)+1ll);
		}
		for(int i=1;i<y;i++){
			find = min(find,solve(solve,x,y-i)+solve(solve,x,i)+1ll);
		}

		return dp[x][y]=find;
	};

	cout<<solve(solve,a,b);

}
