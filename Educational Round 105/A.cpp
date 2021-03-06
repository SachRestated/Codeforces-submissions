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

bool solve(string &s, string &t, char x ) {
    string p = t;
    int n = sz(s);
    int v = 0;
    for(int i = 0; i < n; ++i) {
        if(s[i] != s[0] and s[i] != s[n - 1]) p[i] = x;
        
        p[i] == '(' ? ++v : --v;
        if(v < 0) return false;
    }
    // cout << p << endl; 
    return v == 0;

}


void SachRestated() {
    string s; cin >> s;
    int n = sz(s);
    if(s[0] == s[n - 1]) {
        cout << "NO" << endl;
        return;
    } 
    string t(n, '(');
    for(int i = 0 ; i < n; ++i) {
        if(s[i] == s[0]) t[i] == '(';
        else if(s[i] == s[n - 1]) t[i] = ')';
    }
    char x = '(';
    char y = ')';
    if(solve(s, t, x) or solve(s, t, y)) cout << "YES" << endl;
    else cout << "NO" << endl;
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