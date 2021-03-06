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

v2d a;

void SachRestated() {
    int n; cin >> n;
    v1d v(n);
    v1d ans(101);
    a.resize(101, v1d(101));
    
    for(int i = 0; i < n; ++i) {
        cin >> v[i];
    }
    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    for(int i = 0; i < n; ++i) {
        int mx = v[i];
        int mxInd = i;
        a[i][i] = mxInd;
        for(int j = i + 1; j < n; ++j) {
            if(mx < v[j]) {
                mx = v[j];
                mxInd = j;
            }
            a[i][j] = mxInd;
        }
    }
    queue<pair<pair<int, int>, int>> q;
    q.push({{0, n - 1}, 0});
    while(!q.empty()) {
        int l = q.front().ff.ff;
        int r = q.front().ff.ss;
        // cout << l << ' ' << r << endl;
        int d = q.front().ss;
        q.pop();
        ans[a[l][r]] = d;
        int l1 = l;
        int r1 = a[l][r] - 1;
        int l2 = a[l][r] + 1;
        int r2 = r;
        if(l1 <= r1 and r1 >= 0) q.push({{l1, r1}, d + 1});
        if(l2 <= r2 and l2 < n) q.push({{l2, r2}, d + 1});
    }
    for (int i = 0; i < n; ++i) cout << ans[i] << " " ;
    cout << endl;

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