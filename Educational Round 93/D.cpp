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

int dp[203][203][203];

int solve(int i, int j, int k, v2d &v) {

    if(dp[i][j][k] != -1) return dp[i][j][k];
    if(i >= sz(v[0])) {
        int res = 0;
        int r = j, s = k;
        while(r < sz(v[1]) && s < sz(v[2])) {
            res += v[1][r] * v[2][s];
            ++r, ++s;
        }
        return dp[i][j][k] = res;

    }

    int ans = 0;
    dp[i][j][k] = max((v[0][i] * v[1][j]) + solve(i + 1, j + 1, k, v), (v[0][i] * v[2][k]) + solve(i + 1, j, k + 1, v));
    return dp[i][j][k];
    
    
}

void SachRestated() {
    int r, g, b; cin >> r >> g >> b;
    memset(dp, -1, sizeof(dp));
    v2d v(3);
    int x = 0;
    for(int i=0; i<r; ++i) {
        int p; cin >> p;
        v[0].pb(p);
    }
    for(int i=0; i<g; ++i) {
        int p; cin >> p;
        v[1].pb(p);
    }
    for(int i=0; i<b; ++i) {
        int p; cin >> p;
        v[2].pb(p);
    }
    RS(v[0]);
    RS(v[1]);
    RS(v[2]);

    if(sz(v[0]) > sz(v[1])) swap(v[0], v[1]);
    if(sz(v[0]) > sz(v[2])) swap(v[0], v[2]);
    int ans = 0;
    ans = solve(0, 0, 0, v);
    
}

int32_t main() {
    fio
    int t = 1;
    cin >> t;
    while(t--) {
      SachRestated();  
    }

}