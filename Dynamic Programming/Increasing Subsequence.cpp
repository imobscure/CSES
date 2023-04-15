#include <iostream>
#include <vector>
 
using namespace std;
 
 
int main(){
	
	int n; cin>>n;
	int a[n]; 
	
	for(auto &val:a)cin>>val; 
	
	vector<int> dp(n+1,1e9+1);
	
	dp[0]=0;
	
	for(int idx=0;idx<n;++idx){
		
		int lo=0,hi=n,pos=0;
		
		while(lo<=hi){
			int mid=lo+(hi-lo+1)/2;
			
			if(dp[mid]<=a[idx]){
				pos=mid;
				lo=mid+1;
			}
			else hi=mid-1;
			
		}
		++pos;
		
		if(dp[pos-1]<a[idx] && dp[pos]>a[idx]){
			dp[pos]=a[idx];
		}
		
	}
	
	int ans=1;
	
	for(int i=n;i>=0;i--){
		if(dp[i]!=(1e9+1)){
			ans=i;
			break;
		}
	}
	
	cout<<ans;
	
	return 0;
}
