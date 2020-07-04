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
        // Basic Implementation
        int n; cin >> n;
        string s; cin >> s;
        v1d p;

        if (n == 1){
            cout << s << endl;
            continue;
        }

        int st = 1;
        for(int i=1; i<n; ++i) {
            if(s[i] == s[i-1]) ++st;
            else {
                p.pb(st);
                st = 1;
            }
            if(i == n-1) p.pb(st);
        }
        if(sz(p) == 1) {
            cout << s << endl;
            continue;
        }
        if(s[0] == '1') {
            int x = sz(p);
            if(x % 2 == 0) {
                cout << '0' << endl;
                continue;
            }
            else {
                cout << '0';
                for(int i=0; i<p.back(); ++i) cout << '1';
                cout << endl;
            }
        }
        else {
            for(int i=0; i<p[0]; ++i) cout << '0';
            int x = sz(p) ;
            if(x == 2) {
                for(int i=0; i<p[1]; ++i) cout << '1';
                cout << endl;
                continue;
            }
            if(x % 2 == 1) {
                cout << '0' << endl;
                continue;
            }
            else {
                cout << '0';
                for(int i=0; i<p.back(); ++i) cout << '1';
                cout << endl;
            }

        }
    }
}