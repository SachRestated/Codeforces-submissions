//  .|'''.|                  '||      '||''|.                    .             .                '||  
//  ||..  '   ....     ....   || ..    ||   ||    ....   ....  .||.   ....   .||.    ....     .. ||  
//   ''|||.  '' .||  .|   ''  ||' ||   ||''|'   .|...|| ||. '   ||   '' .||   ||   .|...||  .'  '||  
// .     '|| .|' ||  ||       ||  ||   ||   |.  ||      . '|..  ||   .|' ||   ||   ||       |.   ||  
// |'....|'  '|..'|'  '|...' .||. ||. .||.  '|'  '|...' |'..|'  '|.' '|..'|'  '|.'  '|...'  '|..'||. 

#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
#define sz(v) (int)v.size()
#define pr pair<int, int>
#define v1d vector<int>
#define mp make_pair
#define pb push_back
#define v1p vector<pr>
#define vb vector<bool>
#define v2d vector<vector<int>>
#define ff first
#define ss second
#define all(v) v.begin(), v.end()
#define S(v) sort(v.begin(), v.end())
#define RS(v) sort(v.rbegin(), v.rend())
#define eb emplace_back
#define ld long double
#define endl "\n"
#define MOD 1000000007
#define pqx priority_queue <int>
#define pqn priority_queue <int, v1d, greater<int> >
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void SachRestated() {
    int n, k, l; cin >> n >> k >> l;
    v2d dp(n + 10, v1d(k + k + 5));
    v1d d(n);

    for(auto &x : d) cin >> x;

    for(int i=0; i<k+k+5; ++i) dp[0][i] = 1;
    
    // cout << *max_element(all(d)) << endl;
    if(*(max_element(all(d))) > l) {
        cout << "NO\n"; return;
    }

    for(int i=1; i<=n; ++i) {
        for(int j=0; j<k + k; ++j) {
            int x = d[i - 1];
            
            if(j <= k) {
                x += j;
            }
            else {
                x += k - (j - k);
            }
            int lst = j - 1;
            if(j == 0) lst = k + k - 1;
            

            if(dp[i - 1][lst] && l >= x) dp[i][j] = 1;
            if(j && dp[i][j - 1] && l >= x) dp[i][j] = 1;
        }
    }

    
    bool ok = false;
    
    for(int i=0; i<k + k + 5; ++i) {
        if(dp[n][i]) ok = true;
    }
    
    if(ok) cout << "YES\n";
    else cout << "NO\n";
}

int32_t main() {
    fio
    int t = 1;
    cin >> t;
    while(t--) {
      SachRestated();  
    }

}
