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
    cout << endl << endl;
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        set<int> st;
        int p = 2 + n * 2;
        for(int i=0; i<p + 1; ++i) st.insert(i);
        map<int, v1d> m;
        v1d v(n);
        v1d ans;
        set<int> mult;

        for(int i=0; i<n; ++i) {
            cin >> v[i];
            st.erase(v[i]);
            m[v[i]].pb(i);
            if(sz(m[v[i]]) > 1) mult.insert(v[i]); 
        }

        while(!mult.empty()) {
            int p = *(mult.begin());
            int q = m[p].back();
            int r = *(st.begin());
            ans.pb(q + 1);
            v[q] = r;
            st.erase(st.begin());
            m[p].pop_back();
            m[r].pb(q);
            if(sz(m[p]) == 1) mult.erase(p);
        }
       
        if(sz(m[0]) == 1) {
            int r = *(st.begin());
            v[m[0].back()] = r;
            ans.pb(m[0].back() + 1);
            m.erase(0);
            st.erase(r);
            st.insert(0);
        }
        int y = v[0];
        v[0] = 0;
        st.erase(0);
        st.insert(y);
        ans.pb(1);

        
        for(int i=0; i<n; ++i) {
            int r = *(st.begin());
            if(r == n) {
                bool ok = true;
                for(int j=0; j<n; ++j) {
                    if(v[j] != j) {
                        int y = v[j];
                        v[j] = n;
                        st.erase(n);
                        st.insert(y);
                        ans.pb(j + 1);
                        ok = false;
                        break;
                    }
                }
                if(ok) break;
                continue;
            }
            int x = v[r];
            // cout << r << " " << x << endl;
            
            v[r] = r;
            st.erase(r);
            st.insert(x);
            ans.pb(r + 1);
        }
        
        for(int i=0; i<n; ++i) {
            if(v[i] == n) {
                // cout << "hi" << endl;
                ans.pb(i + 1);
                v[i] = i;
            }
        }
        
        // for(auto &k : v) cout << k << " " ;
        // cout << endl;
        cout << sz(ans) << endl;
        for(auto &k : ans) cout << k << " " ;
        
        cout << endl;

    }
}