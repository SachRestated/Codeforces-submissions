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

void SachRestated() {
    int n, k, z; cin >> n >> k >> z;
    v1d a(n);
    v1d b(n);
    for(int i=0; i<n; ++i) {
        cin >> a[i];
        b[i] = a[i];
        if(i) b[i] += b[i-1];
    }
    int ans = b[k];
    for(int use=1; use <= z; ++use) {
        int rem = use;
        // int cur = a[0];
        int maxreach = k - (2 * use);
        if(maxreach < 0) {
            break;
        }
        int p = b[maxreach + 1] + a[maxreach];
        int x = 0;
        for(int i=maxreach + 1; i>=1; --i) {
            x = max(x, (use - 1) * (a[i] + a[i - 1]));
        }
        ans = max(ans, p + x);
        int cur = b[maxreach];
        for(int i = maxreach; i >= 1; --i) {
            cur = max(cur, b[maxreach] + (use * (a[i] + a[i - 1])));
        }
        ans = max(ans, cur);

    }

    cout << ans << endl;

}

int32_t main() {
    fio
    int t = 1;
    cin >> t;
    while(t--) {
      SachRestated();  
    }

}