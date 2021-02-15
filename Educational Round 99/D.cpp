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
    int n, x; cin >> n >> x;
    v1d v(n);
    for(auto &k: v) {
        cin >> k;
    }
    v1d a = v;
    bool ok = true;
    int ans = 0;
    for(int i = 1; i < n && ok; ++i) {
        if(v[i] < v[i - 1]) {
            if(x > v[i]) {
                ok = false;
                continue;
            } else {
                int j = i - 1;
                while(j >= 0 and v[j] > x) --j;
                ++ans;

                int p = v[i - 1];
                for(int k = i - 2; k >= j + 1; --k) {
                    if(v[k + 1] > v[k])
                        ++ans;
                    v[k + 1] = v[k];
                    
                } 
                v[j + 1] = x;
                x = p;
                if(v[i - 1] > v[i]) ok = false;
            }
        }
    }
    if(!ok) {
        cout << -1 << endl;
    } else {
        ans = 0;
        for(int i = 0; i<n; ++i) if(v[i] != a[i]) ++ans;
        cout << ans << endl;
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