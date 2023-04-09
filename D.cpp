#include <iostream>

using int64 = long long ;

void solve()
{
    int n, MX = 1e7 ;
    std :: cin >> n ;
    int dp[n+1] ;
    for(int nm = 0; nm <= n; nm++)
    {
        if(nm <= 9)
            dp[nm] = 1 ;
        else
            dp[nm] = MX ;
    }
    for(int nm = 10; nm <= n; nm++)
    {
        int digit = nm ;
        while(digit)
        {
            dp[nm] = std :: min(dp[nm], dp[nm-digit%10]+1) ;
            digit /= 10 ;
        }
    }
    std :: cout << dp[n] ;
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
