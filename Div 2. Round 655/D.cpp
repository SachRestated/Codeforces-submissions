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

int32_t main() {
    fio
    int n; cin >> n;
    v1d v(n + n);
    int ans = 0;
    for(int i=0; i<n; ++i) {
        cin >> v[i];
        ans += v[i]; 
        v[i + n] = v[i];
    }
    if(n == 1) {
        cout << ans; return 0;
    }
    
    v1d prefix(n + n);
    prefix[0] = v[0];
    prefix[1] = v[1]; 
    for(int i=2; i<n+n; ++i) {
        prefix[i] = v[i] + prefix[i - 2];
    }
    int mn = prefix[n - 1] - prefix[0];
    
    for(int i=n; i<n + n; ++i) {
        mn = min(mn, prefix[i] - prefix[i - n + 1]);
    }
    cout << ans - mn;
}       