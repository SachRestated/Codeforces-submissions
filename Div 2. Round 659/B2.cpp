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
const int INF = 1e11;


void SachRestated() {
    int n, k, l; cin >> n >> k >> l;
    v1d d(n + 2, -INF);
    for(int i=1;i<=n; ++i) cin >> d[i];
    if(*max_element(all(d)) > l) {
        cout << "NO\n"; return;
    } 
    int time = 0;
    for(int i=1; i<=n; ++i) {
        ++time;
        time %= 2*k;

        int x = d[i];
        int y = min(time, k + k - time);
        if(d[i - 1] + k <= l) {
            time = k;
        }
        else if(time <= k && x + y > l) {
            cout << "NO\n";
            return;
        }

        if(time >= k) {
            int mx = min(l - x, k);
            time = max(time, k + k - mx);
        }

    }
    cout << "YES\n";
}

int32_t main() {
    fio
    int t = 1;
    cin >> t;
    while(t--) {
      SachRestated();  
    }

}