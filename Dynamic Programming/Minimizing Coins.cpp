#include <iostream>

using int64 = long long ;

void solve()
{
    int n, target, MX = 1e6+1 ;
    std :: cin >> n >> target ;
    int coins[n] ;
    for(int &coin : coins)
        std :: cin >> coin ;
    int dp[target+1] ;
    for(int &subtarget : dp)
        subtarget = MX ;
    dp[0] = 0 ;
    for(int currentSum = 1; currentSum <= target; currentSum++)
        for(int &coin : coins)
            if(currentSum >= coin and dp[currentSum-coin] != MX)
                dp[currentSum] = std :: min(dp[currentSum], 1+dp[currentSum-coin]) ;
    dp[target] == MX ? std :: cout << -1 : std :: cout << dp[target] ;
}

int main()
{
    std :: ios_base::sync_with_stdio(false);
    std :: cin.tie(NULL);
    int totalCases = 1 ;
    for(int testcase = 1; testcase <= totalCases; testcase++)
    {
        solve() ;
        std :: cout << '\n' ;
    }
    return 0 ;
}
