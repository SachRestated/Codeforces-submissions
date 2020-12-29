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
#define OJ freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


void SachRestated() {
    int n; cin >> n;
    if(n == 3) {
        cout << "2\n3 2\n3 2\n";
        return; 
    }
    int k = n;
    int pos = 0;
    while(k > 1) {
        ++pos;
        k >>= 1;
    }
    v1d v;
    int i = pos;
    while(i > 1) {
        v.pb(1 << i);
        i = (i + 1) / 2;
    }
    reverse(all(v));
    int id = 0;
    v1p ans;

    for(int i=2; i<n; ++i) {
        if(id < sz(v) and i == v[id]) {
            ++id; 
        } else {
            ans.pb({i, n});
        }
    }
    bool isit = false;
    if(n != v.back()) {
        isit = true;
        v.pb(n);
    }
    for(int i = sz(v) - 1; i>=1; --i) {
        ans.pb({v[i], v[i - 1]});
        ans.pb({v[i], 2});
    }
    // if(isit) ans.pb({n, 2});
    cout << sz(ans) << endl;
    for(auto &k: ans) {
        cout << k.ff << " " << k.ss << endl;
    }


}

int32_t main() {
    fio

    clock_t z = clock();
    //OJ;
    int t = 1;
    cin >> t;
    while(t--) {
        SachRestated();  
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << '\n';
}