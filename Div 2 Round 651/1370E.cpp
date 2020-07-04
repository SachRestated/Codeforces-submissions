#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
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
    int n; cin >> n;
    string s, t; cin >> s >> t;
    if(s == t) {
        cout << 0; return 0;
    }
    string ans;
    int p = 0, q = 0;
    for(int i=0; i<n; ++i) {
        if(s[i] == '1') ++p;
        else ++q;
        if(t[i] == '1') --p;
        else --q;
        if(s[i] != t[i]) ans.pb(s[i]);
    }
    if(p !=0 or q != 0) {
        cout << -1; return 0;
    }
    int stk = 1;
    int x = (int)ans.size();
    v1d pp;
    for(int i=1; i<x; ++i) {
        if(ans[i] != ans[i - 1]) {
            
            pp.pb(stk);
            stk = 1;
        }
        else stk++;
        if(i == x - 1)
        pp.pb(stk);
    }
    int cnt1 = 0, cnt2 = 0;
    for(int i=0; i<(int)pp.size(); ++i) {
        if(i % 2 == 0) {
            cnt1 += pp[i];
            cnt2 = max(0ll, cnt2 - pp[i]);
        }
        else {
            cnt2 += pp[i];
            cnt1 = max(0ll, cnt1 - pp[i]);
        }
    }
    cout << cnt1 + cnt2;
    

}