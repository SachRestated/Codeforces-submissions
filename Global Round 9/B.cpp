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
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        v2d ans(n, v1d(m));
        bool ok = true;
        for(int i=0; i<n; ++i) {
            for(int j = 0; j<m; ++j) {
                int x = 4;
                if(i == 0 || i == n - 1) --x;
                if(j == 0 || j == m - 1) --x;
                cin >> ans[i][j];
                if(ans[i][j] > x) ok = false;
                else ans[i][j] = x;
            }
        }
        if(!ok) cout << "NO\n";
        else {
            cout << "YES\n";
            for(int i=0; i<n; ++i) {
                for(int j=0; j<m; ++j) {
                    cout << ans[i][j] << " " ;
                }
                cout << endl;
            } 
        } 
    }
}