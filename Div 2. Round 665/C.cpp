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
    int n; cin >> n;
    v1d a(n);
    for(auto &k : a) cin >> k;
    v1d x, y;
    int mn = *min_element(all(a));
    for(int i=0; i<n; ++i) {
        if(a[i] % mn == 0) x.pb(a[i]);
    }
    if(n == 1) {
        cout << "YES\n"; return;
    }
    sort(all(x));
    for(int i=n-1; i>=0; --i) {
        if(a[i] % mn == 0) {
            a[i] = x.back();
            x.pop_back();
        }
    }
    for(int i=1; i<n; ++i) {
        if(a[i] < a[i - 1]) {
            cout << "NO\n"; return;
        }
    }
    cout << "YES\n"; return;

}

int32_t main() {
    fio
    int t = 1;
    cin >> t;
    while(t--) {
      SachRestated();  
    }

}