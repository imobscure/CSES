#include <bits/stdc++.h>

using namespace std ;
using int64 = long long ;
const int64 mod = 1e9+7 ;

bool sum[100001] ;

void solve()
{
    int n ;
    cin >> n ;
    int x[n] ;
    for(int &xi : x)
        cin >> xi ;

    sum[0] = true ;

    for(int &xi : x)
        for(int sm = 100000; sm-xi >= 0; sm--)
            sum[sm] |= sum[sm-xi] ;

    vector<int> pSum ;
    for(int sm = 1; sm <= 100000; ++sm)
        if(sum[sm])
            pSum.push_back(sm) ;

    cout << pSum.size() << '\n' ;
    for(int &sm : pSum)
        cout << sm << " " ;
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
