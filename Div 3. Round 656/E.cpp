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

void dfs(int i, v1d &vis, v2d &graph, stack<int> &st, bool &fine) {
    if(!fine) return;
    vis[i] = 1;
    for(auto &k : graph[i]) {
        if(vis[k] == 1) fine = false;
        else if(!vis[k]) dfs(k, vis, graph, st, fine);
    }
    vis[i] = 2;
    st.push(i);
}


int32_t main() {
    fio
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        v1p ans;
        v2d graph(n);
        v1p todo;
        for(int i=0; i<m; ++i) {
            int t, u, v; cin >> t >> u >> v;
            --u, --v;
            if(!t) {
                todo.pb({u, v});
            }
            else {
                graph[u].pb(v);
                ans.pb({u, v});
            }

        }
        v1d vis(n);
        v1d order(n);
        stack<int> st;
        bool ok = true;
        for(int i=0; i<n && ok; ++i) {
            if(!vis[i] && sz(graph[i])) {
                bool fine = true;
                dfs(i, vis, graph, st, fine);
                ok &= fine;
            }
        }
        if(!ok) {
            cout << "NO\n"; continue; 
        }
        int x = 1;
        while(st.size()) {
            int p = st.top();
            order[p] = x++;
            st.pop();
        }
        for(auto &k : todo) {
            if(order[k.ff] <= order[k.ss]) {
                ans.pb({k.ff, k.ss});
            }
            else if(order[k.ff] > order[k.ss]) {
                ans.pb({k.ss, k.ff});
            }
        }
        cout << "YES" << endl;
        for(auto &k : ans) cout << k.ff << " " << k.ss << endl;

    }

}