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
    int n, m; cin >> n >> m;
    v1p a(m);
    v1p b(m);
    v1p x(m);
    for(int i=0; i<m; ++i) {
        cin >> a[i].ff >> b[i].ff;
        b[i].ss = i;
        a[i].ss = i;
        x[i].ff = a[i].ff;
        x[i].ss = b[i].ff;
    }
    RS(a);
    if(n <= m) {
        v1d ans(n);
        for(int i=0; i<min(n, m); ++i) {
            ans[n - i - 1] = a[i].ff;
        }
        
        v1d sf = ans;
        for(int i=1; i<sz(ans); ++i) ans[i] += ans[i - 1];
        int res = ans.back();
        int cur = res;

        for(int i=0; i<m; ++i) {
            int pos = upper_bound(all(sf), b[i].ff) - sf.begin();
            if(pos == 0) continue;
            int q = ans[pos - 1];
            int y = cur - q;
            y += (pos - 1) * b[i].ff;

            if(x[i].ff > b[i].ff) y += b[i].ff;
            else y += x[i].ff;
            
            res = max(res, y);
        }
        cout << res << endl;
    }
    else {
        v1d ans(m);
        for(int i=0; i<m; ++i) {
            ans[m - i - 1] = a[i].ff;
        }

        v1d sf = ans;

        for(int i=1; i<sz(ans); ++i) ans[i] += ans[i - 1];
        int res = ans.back();
        int cur = res;

        for(int i=0; i<m; ++i) {
            int pos = upper_bound(all(sf), b[i].ff) - sf.begin();
            int q = 0;
            if(pos) q = ans[pos - 1];
        
            int y = cur - q;
            pos += n - m;
            y += (pos - 1) * b[i].ff;
            if(x[i].ff > b[i].ff) y += b[i].ff;
            else y += x[i].ff;

            res = max(res, y);
        }
        
        cout << res << endl;
    }
}

int32_t main() {
    fio
    int t;
    cin >> t;
    while(t--) {
      SachRestated();  
    }

}