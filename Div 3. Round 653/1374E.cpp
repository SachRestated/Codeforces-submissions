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
    int n, k; cin >> n >> k;
    v1d time(n);
    v1d a, b, comb;
    int cnt1 = k, cnt2 = k;
    for(int i=0; i<n; ++i) {
        int x, y; cin >> time[i] >> x >> y;
        if(x && y) {
            comb.pb(i);
            --cnt1;
            --cnt2;
        }
        else if(x) {
            a.pb(i);
            --cnt1;
        }
        else if(y) {
            b.pb(i);
            --cnt2;
        }

    }
    if(cnt1 > 0 || cnt2 > 0) {
        cout << -1 << endl;
        return 0;
    }
    sort(all(a), [&](int x, int y) {
        return time[x] < time[y];
    });
    sort(all(b), [&](int x, int y) {
        return time[x] < time[y];
    });
    sort(all(comb), [&](int x, int y) {
        return time[x] < time[y];
    });
    if(sz(comb) == 0) {
        int ans = 0;
        for(int i=0; i<k; ++i) {
            ans += time[a[i]] + time[b[i]];
        }
        cout << ans; return 0;
    }
    int ans = 0;
    int left = k;
    for(int i=0; i<sz(comb) && left; ++i) {
        ans += time[comb[i]];
        --left;
    }
    int idx = min(sz(comb) - 1, k - 1);
    if(left) {
        for(int i=0; i<left; ++i) {
            ans += time[a[i]] + time[b[i]];
        }
    }
    int id = left;
    while(true) {
        if(id >= min(sz(a), sz(b)) || idx < 0) break;
        int p = time[comb[idx]];
        int q = time[a[id]] + time[b[id]];
        if(q <= p) {
            ans -= p - q;
            ++id; --idx;
        }
        else break;
    }
    cout << ans; 



}