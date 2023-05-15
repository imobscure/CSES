#include <bits/stdc++.h>

using namespace std ;
using int64 = long long ;
const int64 mod = 1e9+7 ;

void solve()
{
    int n ;
    cin >> n ;
    int x[n] ;
    for(int &xi : x)
        cin >> xi ;

    vector<vector<int64>> dp(n, vector<int64>(n)) ;
    int64 total = 0 ;

    for(int l = n-1; l >= 0; l--)
    {
        total += x[l] ;
        for(int r = l; r < n; r++)
        {
            if(l == r)
                dp[l][r] = x[l] ;
            else
                dp[l][r] = max(x[l]-dp[l+1][r], x[r]-dp[l][r-1]) ;
        }
    }

    cout << (dp[0][n-1]+total)/2 ;
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
