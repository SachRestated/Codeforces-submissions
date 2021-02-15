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

int solve(int a) {
    int lo = 1;
    int hi = 1e5;
    int res = 1;
    while(lo <= hi) {
        int m = (lo + hi) >> 1ll;
        if(m * m >= a) {
            res = m;
            hi = m - 1;
        } else {
            lo = m + 1;
        }
    }
    if(res * res - 1 <= a) return res;
    return res - 1;
}

void SachRestated() {
    int a, b; cin >> a >> b;
    if(b == 1 || a <= 2) {
        cout << 0 << endl; return;
    }
    b = min(b, a - 1);
    int x = solve(a);
    if(b <= x) {
        int k = b;
        cout << (k * k - k) / 2 << endl; return;
    }
    int ans = (x * x - x) / 2;
    // cout << x <<  " " << ans << endl;

    for(int i = 1;true; ++i) {
        int k = a / i;
        int j = a / (i + 1);
        --k;
        int u = min(b, k);
        int d = max(j, x + 1);
        ans += max(0ll, u - d + 1) * i;
        if(j <= x) {
            break;
        }

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