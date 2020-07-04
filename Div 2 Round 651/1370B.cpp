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

int32_t main() {
    fio
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        v1p e, o;
        v1d v(n + n);
        for(int i=0; i<n + n; ++i) {
            cin >> v[i];
            if(v[i] & 1) o.pb({v[i], i + 1});
            else e.pb({v[i], i + 1});
        }
        int p = (int)e.size();
        int q = (int)o.size();
        if(p % 2 == 1) {
            e.pop_back();
            o.pop_back();
        }
        else if(p >= 2) {
            e.pop_back();
            e.pop_back();
        }
        else if(q >= 2){
            o.pop_back();
            o.pop_back();
        }
        for(int i=1; i<(int)o.size(); i += 2) cout << o[i].ss << " " << o[i - 1].ss << endl;
        for(int i = 1; i<(int)e.size(); i += 2) cout << e[i].ss << " " << e[i - 1].ss << endl;
        // cout << endl;
    }
}