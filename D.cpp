#include <iostream>

using int64 = long long ;

void solve()
{
    int64 n, target, mod = 1e9+7 ;
    std :: cin >> n >> target ;
    int coins[n] ;
    for(int &coin : coins)
        std :: cin >> coin ;
    int64 dp[target+1]{} ;
    dp[0] = 1 ;
    for(int &coin : coins)
        for(int currentSum = 1; currentSum <= target; currentSum++)
            if(currentSum >= coin)
                (dp[currentSum] += dp[currentSum-coin]) %= mod ;
    std :: cout << dp[target] ;
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
