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
    string s, t; cin >> s >> t;
    if(sz(s) > sz(t)) swap(s, t);

    int x = sz(s);
    int y = sz(t);

    int k = __gcd(x, y);
    int p = 0;
    string check;
    for(int i = 0; i < k; ++i) check.pb(s[i]);
    for(int i = 0 ; i < x; ++i) {
        if(s[i] != check[p]) {
            cout << -1 << endl; return;
        } 
        ++p;
        p %= k;
    }
    p = 0;
    for (int i = 0; i < y; ++i)
    {
        if (t[i] != check[p])
        {
            cout << -1 << endl;
            return;
        }
        ++p;
        p %= k;
    }
    p = 0;
    int z = (x * y) / k;
    string res;
    for(int i = 0; i < z; ++i) {
        res.push_back(check[p]);
        ++p;
        p %= k;
    }
    cout << res << endl;
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