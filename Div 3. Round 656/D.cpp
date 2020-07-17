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

int solve(int l, int r, string &s, char c, bool small, v2d &cnt) {
    if(r - l == 1) {
        if(s[l] == c) return 0;
        return 1;
    }
    if(small) {
        int i = c - 'a';
        int pos1 = lower_bound(all(cnt[i]), l) - cnt[i].begin();
        int pos2 = lower_bound(all(cnt[i]), r) - cnt[i].begin();
        return r - l - (pos2 - pos1);
    }
    int d = (r - l) / 2;
    int p = solve(l, l + d, s, c, !small, cnt) + solve(l + d, r, s, c + 1, small, cnt);
    int q = solve(l, l + d, s, c + 1, small, cnt) + solve(l + d, r, s, c, !small, cnt);
    return min(p, q);
    

}

int32_t main() {
    fio
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        string s; cin >> s;
        v2d cnt(26);
        if(n == 1) {
            if(s[0] == 'a') cout << 0 << endl;
            else cout << 1 << endl;
            continue;
        }
        
        for(int i=0; i<n; ++i) {
            cnt[s[i] - 'a'].pb(i);
        }
        // cout << solve(0, n/2, s, 'b', false);
        int p = solve(0, n / 2, s, 'a', true, cnt) + solve(n/2, n, s, 'b', false, cnt);
        int q = solve(0, n / 2, s, 'b', false, cnt) + solve(n/2, n, s, 'a', true, cnt);
        cout << min(p, q) << endl;
    }
}