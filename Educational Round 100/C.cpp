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
    v1p v(n) ;
    for(auto &k: v) {
        cin >> k.ff >> k.ss;
    }
    map<int, int> timeline;
    timeline[0] = 0;
    int nextPos = 0;
    int rem = 0;
    int last = 0;
    int dir = 1;
    for(int i = 0; i < n; ++i) {
        if(rem <= v[i].ff - last) {
            timeline[v[i].ff] = nextPos;
            dir = nextPos < v[i].ss ? 1 : -1;
            rem = abs(nextPos - v[i].ss);
            last = v[i].ff;
            nextPos = v[i].ss;
        }
        else {
            rem -= v[i].ff - last;
            int currentPos = nextPos - (dir * rem);
            timeline[v[i].ff] = currentPos;
            last = v[i].ff;
        }
    }
    int mx = v[n - 1].ff + rem;
    if(rem) {
        timeline[v[n - 1].ff + rem] = nextPos;
        // mx = v[n - 1].ff + rem;
    }
    int cnt = 0;
    for(int i = 0; i < n - 1; ++i) {
        int l = timeline[v[i].ff];
        int r = timeline[v[i + 1].ff];
        int a = min(l, r), b = max(l, r);
        if(a <= v[i].ss and b >= v[i].ss) ++cnt;
    }
    if(min(timeline[v[n - 1].ff], timeline[mx]) <= v[n - 1].ss and max(timeline[v[n-1].ff], timeline[mx]) >= v[n - 1].ss) ++cnt;
    // for(auto &x : timeline) {
    //     cout << x.ff << " " << x.ss << endl;
    // }
    cout << cnt << endl;
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