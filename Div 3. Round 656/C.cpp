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
        int n; cin >> n;
        v1d a(n);
        for(auto &k : a) cin >> k;
        if(n == 1){
            cout << 0 << endl; continue;
        }
        int ans = 1;
        int x = -1;
        bool invert = false;
        for(int i = n - 2; i >=0; --i) {
            if(a[i] < a[i + 1]) invert = true;
            else if(a[i] > a[i + 1] && invert) {
                x = i;
                break;
            }
        }
        // cout << x << " " ;
        if(x == -1) {
            cout << 0 << endl; continue;
        }
        cout << x + 1 << endl;
    }
}