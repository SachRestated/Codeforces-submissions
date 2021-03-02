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
    int n, m; cin >> n >> m;
    vector<int> mxfront(n + 1), mnfront(n + 1), curfront(n + 1);
    vector<int> mxback(n + 1), mnback(n + 1), curback(n + 1);
    int mx = 0, mn = 0, cur = 0;
    string s; cin >> s;
    for(int i = 0; i < n; ++i) {
        s[i] == '+' ? ++cur : --cur;
        mx = max(mx, cur);
        mn = min(mn, cur);
        mxfront[i + 1] = mx;
        mnfront[i + 1] = mn;
        curfront[i + 1] = cur;
    }
    mx = 0, mn = 0, cur = 0;
    for(int i = n - 1; ~i; --i) {
        s[i] == '+' ? --cur : ++cur;
        mx = max(mx, cur);
        mn = min(mn, cur);
        mxback[i + 1] = mx;
        mnback[i + 1] = mn;
        curback[i + 1] = cur;
    }

    for(int i = 0; i < m; ++i) {
        int l, r; cin >> l >> r;

        int mxf = mxfront[l - 1];
        int mnf = mnfront[l - 1];
        int cur = curfront[l - 1];
        int inc = 0;
        int dec = 0;

        if(r != n) {
            dec = curback[r + 1] - mnback[r + 1];
            inc = mxback[r + 1] - curback[r + 1];

        }
        // cout << mnf << " " << mxf << " " << cur << " " << dec << ' ' << inc << endl;
        mnf = min(mnf, cur - dec);
        mxf = max(mxf, cur + inc);
        cout << mxf - mnf + 1 << endl;
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