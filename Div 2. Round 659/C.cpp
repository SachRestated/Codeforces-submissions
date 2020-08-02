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

void dfs(int i, vb &vis, v2d &graph) {
    vis[i] = 1;
    for(auto &k : graph[i]) {
        if(!vis[k]) {
            dfs(k, vis, graph);
        }
    }
}

void SachRestated() {
    int n; cin >> n;
    string a, b; 
    cin >> a >> b;
    // cout << a << endl << b << endl;
    set<int> s[20];
    v2d graph(20);
    bool ok = true;
    for(int i=0; i<n && ok; ++i) {
        if(a[i] > b[i]) ok = false;
        if((a[i] - 'a') < (b[i] - 'a')) {
            graph[a[i] - 'a'].pb(b[i] - 'a');
            graph[b[i] - 'a'].pb(a[i] - 'a');
        }
    }
    if(!ok) {
        cout << -1 << endl;
    }
    else {
        int ans = 20;
        vb vis(20);
        for(int i=0; i<20; ++i) {
            if(!vis[i]) {
                --ans; dfs(i, vis, graph);
            }
        }
        cout << ans << endl;
    }
}

int32_t main() {
    fio
    int t = 1;
    cin >> t;
    while(t--) {
      SachRestated();  
    }

}