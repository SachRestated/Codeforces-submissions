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
        int n; cin >> n ;
        string s; cin >> s;
        string ans = "abacaba";
        bool ok = false;
        for(int i=0; i<n - 6 && !ok; ++i) {
            int j = 0;
            while(j < 7) {
                if(s[i + j] == ans[j] || s[i + j] == '?') {
                    ++j;
                }
                else break;
            }
            if(j == 7) {
                string x = s;
                for(int k=0; k < 7; ++k) {
                    x[i + k] = ans[k];
                }
                for(int k=0; k<n; ++k) {
                    if(k >= i && k <= i + 6) continue;
                    if(x[k] == '?') x[k] = 'z';
                }
                int cnt = 0;
                for(int k=0; k<n - 6; ++k) {
                    int l = 0;
                    while(l < 7 && x[l + k] == ans[l]) ++l;
                    if(l == 7) ++cnt;

                }
                if(cnt != 1) continue;
                else {
                    cout << "YES\n" << x << endl;
                    ok = true; 
                }
            }
            
        }
        if(!ok) {
            cout << "NO\n"; 
        }
    }
}