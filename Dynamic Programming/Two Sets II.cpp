#include <bits/stdc++.h>

using namespace std ;
using int64 = long long ;
const int64 mod = 1e9+7 ;

void solve()
{
    int n ;
    cin >> n ;

    int sum = (n*(n+1))/2 ;
    if(sum%2)
    {
        cout << 0 ;
        return ;
    }
    sum /= 2 ;

    vector<int64> dp(sum+1, 0) ;
    dp[0] = 1 ;

    for(int nm = 2; nm <= n; nm++)
        for(int sm = sum; sm >= nm; sm--)
            (dp[sm] += dp[sm-nm]) %= mod ;

    cout << dp[sum] ;
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
