#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
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

v1d v;
set<int> st;
v1d nums;
int n, k;

bool solve(int m) {
    int sz = 0;
    for(int i=0; i<n; ++i) {
        if((sz & 1) && v[i] <= m) ++sz;
        else if(!(sz & 1)) ++sz;
    }
    
    if(sz >= k) return true;
    sz = 0;
    for(int i=0; i<n; ++i) {
        if(sz % 2 == 0 and v[i] <= m) ++sz;
        else if(sz % 2 == 1) ++sz;
    }
    
    if(sz >= k) return true;
    return false;
}

int32_t main() {
    fio
    cin >> n >> k;
    v.resize(n);
    for(auto &x : v) cin >> x;
    v1d b = v;
    S(b);
    int ans = b.back();
    int lo = 0, hi = n - 1;
    while(lo <= hi) {
        int m = (lo + hi) >> 1ll;
        // cout << b[m] << endl;
        if(solve(b[m])) {
            ans = b[m];
            hi = m - 1;
        }
        else {
            lo = m + 1;
        }
    }
    cout << ans;

}
