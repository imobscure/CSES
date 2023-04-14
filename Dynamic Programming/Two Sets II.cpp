#include <iostream>
 
using namespace std;
 
long long dp[63000][501];
 
int main(){
	
	int n; cin>>n;
	
	/*
	
	max sum = (500)*(501)/2 -> 125250 --> ~ 63000
	
	dp[x][i] -> number of ways to produce sum of x using first ith ele.
	
	space -> O(63000*500)
	time -> O(63000*500)
	
	Transition state :
	
	dp[i][j] = dp[i-j][j-1] + dp[i][j-1];
	
	AC for 1 sec
	
	*/
	
	int sm=((n+1)*n)/2;
	long long mod=1e9+7;
	
	dp[0][0]=1;
	
	if(sm%2)cout<<0;
	else{
		sm/=2;
		
		for(int i=0;i<=sm;i++){
			for(int j=1;j<=n;j++){
				dp[i][j]=dp[i][j-1];
				if(i>=j){
					dp[i][j]+=dp[i-j][j-1];
					dp[i][j]%=mod;
				}
			}
		}
		
		cout<<dp[sm][n-1]%mod;
		
	}
	return 0;
}
