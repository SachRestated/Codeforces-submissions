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

int n, m;
v1d h; 
v1d cnt;
v1d sum;
v1d good;
// v1d par;

int dfs(int i, v2d &a, int p = -1) {
    // par[i] = p;
    for(auto &k : a[i]) {
        if(k != p) {
            sum[i] += dfs(k, a, i);
        }
    }
    return sum[i];
}

 int dfs2(int i, v2d &a, bool &ok, int p = -1) {
    if(sum[i] < abs(h[i]) || abs(sum[i] + h[i]) % 2 ==1) {
        ok = false;
        return 1e10;
    }
    int tot = 0;
    good[i] = (sum[i] + h[i]) / 2;
    for(auto &k : a[i]) {
        if(k != p) {
            tot += dfs2(k, a, ok, i);

        }
    }
    if(tot > good[i]) {
        ok = false;
        return 1e10;
    }
    return good[i];

}


void SachRestated() {
    cin >> n >> m;

    h.resize(n, 0);
    cnt.resize(n, 0);
    sum.resize(n, 0);
    good.resize(n, 0);

    v2d graph(n);
    for(int i=0; i<n; ++i) {
        cin >> cnt[i];
        sum[i] = cnt[i];
    }
    for(int i=0; i<n; ++i) cin >> h[i];

    
    if(n == 1) {
        int k = abs(h[0] - cnt[0]);
        if(abs(h[0]) > cnt[0] || k % 2 == 1) {
            cout << "NO\n";
        }
        else cout << "YES\n";
        return;
    }
    for(int i=0; i<n-1; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        // cout << u << " " << v << endl;
        graph[u].pb(v);
        graph[v].pb(u);
    }

    dfs(0, graph);

    bool ok = true;
    dfs2(0, graph, ok);
    if(ok) cout << "YES\n";
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