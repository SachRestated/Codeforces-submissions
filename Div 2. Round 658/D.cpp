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
const int INF = 1e6;
int n;

int solve(int i, int done, int a, int b, bool first, v1d &v, vector<v2d> &dp) {
    if(done == n) {
        return v[i] > a;
    }
    if(i - done == n) {
        return v[i] > b;
    }
    if(dp[i][done][first] != -1) return dp[i][done][first];
    dp[i][done][first] = 0;
    if(first) {
        if(v[i] > a) {
            dp[i][done][first] |= solve(i + 1, done + 1, v[i], b, first, v, dp);
            dp[i][done][first] |= solve(i + 1, done, a, v[i], !first, v, dp);
        }
        else {
            dp[i][done][first] |= solve(i + 1, done, a, v[i], !first, v, dp);
            dp[i][done][first] |= solve(i + 1, done + 1, a, b, !first, v, dp);
            
        }
    }
    else {
        if(v[i] > b) {
            dp[i][done][first] |= solve(i + 1, done, a, v[i], first, v, dp);
            dp[i][done][first] |= solve(i + 1, done + 1, v[i], b, !first, v, dp);
        }
        else {
            dp[i][done][first] |= solve(i + 1, done, a, b, first, v, dp);
            dp[i][done][first] |= solve(i + 1, done + 1, v[i], b, !first, v, dp);
        }
    }
    return dp[i][done][first];
}

void SachRestated() {
    
    cin >> n;
    vector<v2d> dp(2 * n, v2d(n, v1d(2, -1)));
    // memset(dp, -1, sizeof(dp));
    v1d a(n + n);
    for(auto &k : a) cin >> k;
    if(solve(1, 1, a[0], INF, true, a, dp)) {
        cout << "YES\n";
    }
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