#include <bits/stdc++.h>
 
using namespace std ;
using int64 = long long ;
const int64 mod = 1e9+7 ;
 
struct project
{
    int a, b, p ;
};
 
void solve()
{
    int n ;
    cin >> n ;
    vector<project> proj(n) ;
    for(int idx = 0; idx < n; idx++)
        cin >> proj[idx].a >> proj[idx].b >> proj[idx].p ;
 
   sort(proj.begin(), proj.end(), [](project x, project y)
        {
            return x.b < y.b ;
        }) ;
 
    map<int, int64> money ;
    vector<int> prev ;
 
    prev.push_back(0) ;
    money[0] = 0 ;
    int last = 0 ;
 
    for(project &prj : proj)
    {
        auto it = lower_bound(prev.begin(), prev.end(), prj.a) ;
        --it ;
        money[prj.b] = max(money[last], money[*it]+prj.p) ;
        last = prj.b ;
        prev.push_back(prj.b) ;
    }
 
    int64 ans = 0 ;
    for(auto amount : money)
        ans = max(ans, amount.second) ;
 
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
