#include <bits/stdc++.h>

using namespace std ;
using int64 = long long ;
const int64 mod = 1e9+7 ;

void solve()
{
    int a, b ;
    cin >> a >> b ;

    vector<vector<int>> dp(a+1, vector<int>(b+1, 1e9)) ;
    dp[0][0] = 0 ;

    for(int aa = 1; aa <= a; aa++)
    {
        for(int bb = 1; bb <= b; bb++)
        {
            if(aa == bb)
                dp[aa][bb] = 0 ;
            else
            {
                for(int aaa = 1; aaa < aa; aaa++)
                    dp[aa][bb] = min(dp[aa][bb], dp[aaa][bb]+dp[aa-aaa][bb]+1) ;
                for(int bbb = 1; bbb < bb; bbb++)
                    dp[aa][bb] = min(dp[aa][bb], dp[aa][bbb]+dp[aa][bb-bbb]+1) ;
            }
        }
    }
    cout << dp[a][b] ;
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
