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

    vector<int> length(n+1, INT_MAX) ;
    length[0] = 0 ;
    int ans = 0 ;

    for(int &xi : x)
    {
        int lo = 0, hi = n, pos = 0 ;
        while(lo <= hi)
        {
            int mid = lo + (hi-lo)/2 ;
            if(length[mid] <= xi)
            {
                pos = mid ;
                lo = mid+1 ;
            }
            else
                hi = mid-1 ;
        }
        ++pos ;
        if(length[pos-1] < xi and length[pos] > xi)
            length[pos] = xi, ans = max(ans, pos) ;
    }
    cout << ans ;
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
