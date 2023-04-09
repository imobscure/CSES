#include <iostream>

using int64 = long long ;

void solve()
{
    int64 target, mod = 1e9+7 ;
    std :: cin >> target ;
    int64 dp[target+1]{} ;
    dp[0] = 1 ;
    for(int currentSum = 1; currentSum <= target; currentSum++)
        for(int die = 1; die <= 6; die++)
            if(currentSum >= die)
                (dp[currentSum] += dp[currentSum-die]) %= mod ;
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
