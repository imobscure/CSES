#include <iostream>

using int64 = long long ;
const int64 mod = 1e9+7 ;

void solve()
{
    int n, m ;
    std :: cin >> n >> m ;
    int x[n] ;
    for(int &xi : x)
        std :: cin >> xi ;
    int64 dp[n+1][m+1] ;
    for(int idx = 0; idx <= n; idx++)
    {
        for(int mm = 0; mm <= m; mm++)
        {
            dp[idx][mm] = 0 ;
            if(x[0] == 0)
                dp[1][mm] = 1 ;
        }
    }
    dp[1][0] = 0 ;
    if(x[0])
        dp[1][x[0]] = 1 ;
    for(int idx = 2; idx <= n; idx++)
    {
        if(x[idx-1])
        {
            (dp[idx][x[idx-1]] += (x[idx-1] > 0 and x[idx-1] <= m)*dp[idx-1][x[idx-1]-1]) %= mod ;
            (dp[idx][x[idx-1]] += (x[idx-1] >= 0 and x[idx-1] < m)*dp[idx-1][x[idx-1]+1]) %= mod ;
            (dp[idx][x[idx-1]] += dp[idx-1][x[idx-1]]) %= mod ;
        }
        else
        {
            for(int mm = 1; mm <= m; mm++)
            {
                (dp[idx][mm] += (mm > 0 and mm <= m)*dp[idx-1][mm-1]) %= mod ;
                (dp[idx][mm] += (mm >= 0 and mm < m)*dp[idx-1][mm+1]) %= mod ;
                (dp[idx][mm] += dp[idx-1][mm]) %= mod ;
            }
        }
    }
    int64 ans = 0 ;
    for(int64 &ways : dp[n])
        (ans += ways) %= mod ;
    std :: cout << ans ;
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
