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
    vector<int> v(n);
    for(auto &k : v) cin >> k;

    set<pr> stl;
    set<pr> str;
    int re = 0;
    if(n == 2) {
        cout << "NO" << endl;
        return;
    }
    vector<int> left(n), right(n);
    for(int i = 1; i < n; ++i) {
        if(v[i] > v[i - 1]) ++re;
        else re = 0;
        left[i] = re;
        stl.insert({left[i], i});
    }
    re = 0;
    for(int i = n - 2; ~i; --i) {
        if (v[i] > v[i + 1])
            ++re;
        else
            re = 0;
        right[i] = re;

        str.insert({right[i], i});
    }
    int ans = 0;
    for(int i = 1; i < n - 1; ++i) {
        if(v[i] > v[i - 1] and v[i] > v[i + 1]) {
            stl.erase({left[i], i});
            str.erase({right[i], i});
            int mx = max((*stl.rbegin()).first, (*str.rbegin()).first);
            stl.insert({left[i], i});
            str.insert({right[i], i});
            if(mx >= left[i] and mx >= right[i] == 0) {
                continue;
            }
            
            int stepl = left[i];
            int stepr = right[i];
            if(stepl % 2 == 0) --stepl;
            if(stepr % 2 == 0) --stepr;

            if(stepr >= left[i] or stepl >= right[i]) continue;
            ++ans;
        }
    }
    cout << ans << endl;
}

int32_t main() {
    fio

    clock_t z = clock();
    //OJ;
    int t = 1;
    //cin >> t;
    while(t--) {
        SachRestated();  
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << '\n';
}