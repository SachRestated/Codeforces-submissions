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
    int n, q, k; cin >> n >> q >> k;
    v1d a(n);
    v1d b(n);
    for(int i = 0 ; i < n; ++i) {
        cin >> a[i];
        if(i) {
            b[i] += a[i] - a[i - 1];
            b[i - 1] += a[i] - a[i - 1] - 1;
        }
        if(i == 0) {
            b[i] += a[i] ;
        }
        if(i == n - 1) {
            b[i] += n - a[i];
        }
    }
    for (int i = 1; i < n; ++i) b[i] += b[i - 1];
    // for (auto &x : b)
    //     cout << x << " ";
    cout << endl;
    while(q--) {
        int l, r; cin >> l >> r;
        // cout << l << " " << r << endl;
        --l; --r;
        if(l == r) {
            cout << k - 1 << endl;
            continue;
        }
        int len = r - l + 1;
        int ans = (a[l + 1] - 1) + (b[r - 1] - b[l]) + (k - a[r - 1]);
        cout << ans - len << endl; 

    }

}

int32_t main() {
    fio

    clock_t z = clock();
    //OJ;
    int t = 1;
    // cin >> t;
    while(t--) {
        SachRestated();  
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << '\n';
}