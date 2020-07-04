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
        int n; cin >> n;
        if(n == 1) {
            cout << 0 << endl; continue;
        }
        bool ok = true;
        map<int, int> m;
        int cnt = 0;
        while(n % 2 == 0) {
            ++cnt;
            n /= 2;
        }
        m[2] = cnt;
        cnt = 0;
        while(n % 3 == 0) {
            ++cnt;
            n /= 3;
        }
        if(cnt == 0 || n > 1 || m[2] > cnt) {
            cout << -1 << endl;
            continue;
        }
        m[3] = cnt;
        int ans = m[3];
        ans += m[3] - m[2];
        cout << ans << endl;

    }
}