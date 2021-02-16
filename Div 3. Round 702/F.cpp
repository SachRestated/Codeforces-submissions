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
    map<int, int> m;
    map<int, int> mpp;
    for(int i = 0; i < n; ++i) {
        int k; cin >> k;
        mpp[k]++;
    }
    for(auto &k : mpp) m[k.ss]++;
    int x = sz(m);
    v1d pre(x), suf(x), cnt(x), num(x);
    int tot = 0;
    int sum = 0;
    int id = 0;
    for(auto &k : m) {
        pre[id] = sum;
        sum += (k.ff * k.ss);
        tot += k.ss;
        cnt[id] = tot;
        num[id] = k.ff;
        ++id;
    }
    --id;
    sum = 0;
    for(auto it = m.rbegin(); it != m.rend(); ++it) {
        suf[id] = sum;
        sum += (it->first * it->second);
        --id;
    }
    // for(auto &k : pre) cout << k << " " ;
    // cout << endl; 
    
    // for(auto &k : suf) cout << k << " " ;
    // cout << endl; 

    int ans = n + 1;
    for(int i = 0; i < x; ++i) {
        int val = pre[i];
        int count = tot - cnt[i];
        // cout << i << " " << pre[i] << " " << count << " " << num[i] << endl; 
        val += (suf[i] - (count * num[i]));
        ans = min(ans, val);
    }
    cout << ans << endl;
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