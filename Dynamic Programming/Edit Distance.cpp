#include <bits/stdc++.h>

using namespace std ;
using int64 = long long ;
const int64 mod = 1e9+7 ;

void solve()
{
    string A, B ;
    cin >> A >> B ;

    int n = A.size(), m = B.size() ;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 1e9)) ;

    dp[0][0] = 0 ;
    for(int a = 1; a <= n; a++)
        dp[a][0] = dp[a-1][0]+1 ;
    for(int b = 1; b <= m; b++)
        dp[0][b] = dp[0][b-1]+1 ;

    for(int a = 1; a <= n; a++)
        for(int b = 1; b <= m; b++)
            dp[a][b] = min((int)(A[a-1]!= B[b-1])+dp[a-1][b-1], 1+min(dp[a-1][b], dp[a][b-1])) ;

    cout << dp[n][m] ;
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
