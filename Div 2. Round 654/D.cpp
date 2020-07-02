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

int32_t main() {
    fio
    int t; cin >> t;
    while(t--) {
        int n, k; cin >> n >> k;
        int p = n * n - k;
        int x = p / n;
        int y = p % n;
        v1d r(n, n - x);
        for(int i=0; i<y; ++i) r[i]--;
        vector<vector<char>> ans(n, vector<char>(n, '0'));
        priority_queue<pr, v1p, greater<pr>> q;
        for(int i=0; i<n; ++i) {
            q.push({0, i});
        }
        for(int i=0; i<n; ++i) {
            int ones = r[i];
            for(int j=0; j<ones; ++j) {
                pr a = q.top();
                q.pop();
                ans[i][a.ss] = '1';
                q.push({a.ff + 1, a.ss});
            }
        }
        int rr = r[n - 1];
        int sm = r[0];
        int ot = (rr - sm) * (rr - sm);
        cout << ot * 2 << endl; 
        for(auto &l : ans) {
            for(auto &y : l) cout << y;
            cout << endl;
        }


    }
}