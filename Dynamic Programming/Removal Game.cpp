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

vector<vi> dp(5001,vi(5001,-1));
vi a(5001);

signed main(){
	setIO();

    int n; cin>>n;

    re(i,n)cin>>a[i+1];


    auto solve=[&](auto&& solve,int l,int r)->int{

    	if(l>r)return 0ll;

    	if(dp[l][r]!=-1)return dp[l][r];

    	int back=a[r]+min(solve(solve,l+1,r-1),solve(solve,l,r-2));
    	int frwd=a[l]+min(solve(solve,l+1,r-1),solve(solve,l+2,r));

    	return dp[l][r]=max(back,frwd);
    };

    cout<<solve(solve,1,n);

}
