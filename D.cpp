#include <iostream>

using int64 = long long ;

void solve()
{
    int64 n, mod = 1e9+7 ;
    std :: cin >> n ;
    int64 dp[n]{} ;
    dp[0] = 1 ;
    for(int rw = 0; rw < n; rw++)
    {
        for(int cl = 0; cl < n; cl++)
        {
            char cell ;
            std :: cin >> cell ;
            if(cell == '*')
                dp[cl] = -1 ;
            else
            {
                if(dp[cl] == -1)
                    dp[cl] = 0 ;
                if(cl and dp[cl-1] != -1)
                    (dp[cl] += dp[cl-1]) %= mod ;
            }
        }
    }
    std :: cout << std :: max(0ll, dp[n-1]) ;
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
