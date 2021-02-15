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
#define ft first
#define sc second
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
    v1d a(3), b(3);
    for(auto &k: a) cin >> k;
    for(auto &k: b) cin >> k;
    v1d c, d;
    c = a, d = b;
    auto fun = [&]() {
        int mx = 0;
        for(int i = 0; i<3; ++i) {
            int j = (i + 1) % 3;
            int k = min(a[i], b[j]);
            mx += k;
        }
        return mx;
    };
    int mx = fun();
    auto solve = [&]() {
        vector<pair<int, int>> ord;
        int ans1 = INT_MAX;
        ord.pb({0, 0});
        ord.pb({0, 2});
        ord.pb({1, 1});
        ord.pb({1, 0});
        ord.pb({2, 2});
        ord.pb({2, 1});
        sort(all(ord));
        do
        {
            vector<int> a1 = a, b1 = b;
            for (int i = 0; i < sz(ord); i++)
            {
                int cnt = min(a1[ord[i].ft], b1[ord[i].sc]);
                a1[ord[i].ft] -= cnt;
                b1[ord[i].sc] -= cnt;
            }
            int cur = min(a1[0], b1[1]) + min(a1[1], b1[2]) + min(a1[2], b1[0]);
            ans1 = min(ans1, cur);
        } while (next_permutation(all(ord)));
        return ans1;
    };
    int mn = solve();
    
    cout << mn << " " << mx << endl;
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