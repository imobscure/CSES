#include <iostream>
#include <algorithm>

using int64 = long long ;

void solve()
{
    int n, totalPrice ;
    std :: cin >> n >> totalPrice ;
    int pages[n], price[n] ;
    for(int &cost : price)
        std :: cin >> cost ;
    for(int &page : pages)
        std :: cin >> page ;

    int dp[totalPrice+1]{} ;
    for(int book = 0; book < n; book++)
        for(int x = totalPrice-price[book]; x >= 0; x--)
            dp[x+price[book]] = std :: max(dp[x+price[book]], dp[x]+pages[book]) ;

    std :: cout << *std :: max_element(dp, dp+totalPrice+1) ;
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
