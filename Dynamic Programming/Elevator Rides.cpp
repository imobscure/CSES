#include <bits/stdc++.h>

using namespace std ;
using int64 = long long ;
const int64 mod = 1e9+7 ;

void solve()
{
    int n, x ;
    cin >> n >> x ;

    int wt[n] ;
    for(int &WTi : wt)
        cin >> WTi ;

    pair<int, int64> dp[1<<n] ;
    dp[0] = {1, 0} ;

    for(int mask = 1; mask < (1<<n); mask++)
    {
        dp[mask] = {1e9, 1e18} ;
        for(int idx = 0; idx < n; idx++)
        {
            if(mask&(1<<idx))
            {
                auto prev = dp[mask^(1<<idx)] ;
                if(prev.second+wt[idx] <= x)
                    prev.second += wt[idx] ;
                else
                {
                    prev.second = wt[idx] ;
                    ++prev.first ;
                }
                dp[mask] = min(dp[mask], prev) ;
            }
        }
    }

    cout << dp[(1<<n)-1].first ;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int test = 1 ;
    // cin >> test ;
    for(int cas = 1; cas <= test; cas++)
    {
        solve() ;
        cout << '\n' ;
    }
    return 0 ;
}
