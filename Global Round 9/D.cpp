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
        set<int> st;
        int p = 2 + n * 2;
        for(int i=0; i<p + 1; ++i) st.insert(i);
        map<int, int> m;
        v1d v(n);
        v1d ans;
        set<int> mult;
        
        auto issorted = [&]() {
            for(int i=1; i<n; ++i) if(v[i] < v[i - 1]) return false;
            return true;
        };

        for(int i=0; i<n; ++i) {
            cin >> v[i];
            st.erase(v[i]);
            m[v[i]]++;
            // if(sz(m[v[i]]) > 1) mult.insert(v[i]); 
        }
       
        while(true) {
            if(sz(ans) > 2 * n) break;

            if(issorted()) break;
            int r = *(st.begin());
            if(r == n) {
               for(int i=1; i<n; ++i) {
                   if(v[i] < v[i - 1]) {
                       int y = v[i - 1];
                       v[i - 1] = n;
                       ans.pb(i);
                       if(--m[y] == 0) {
                           st.insert(y);
                           m.erase(y);
                       }
                       st.erase(n);
                       m[n]++;
                       break;
                   }
               }
               continue;
            }
            int y = v[r];
            v[r] = r;
            if(--m[y] == 0) {
                m.erase(y);
                st.insert(y);
            }
            ans.pb(r + 1);
            m[r]++;
            st.erase(r);
        }
        cout << sz(ans) << endl;
        for(auto &k : ans) cout << k << " " ;
        cout << '\n';
    }
}