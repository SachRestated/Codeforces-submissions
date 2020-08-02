//  .|'''.|                  '||      '||''|.                    .             .                '||  
//  ||..  '   ....     ....   || ..    ||   ||    ....   ....  .||.   ....   .||.    ....     .. ||  
//   ''|||.  '' .||  .|   ''  ||' ||   ||''|'   .|...|| ||. '   ||   '' .||   ||   .|...||  .'  '||  
// .     '|| .|' ||  ||       ||  ||   ||   |.  ||      . '|..  ||   .|' ||   ||   ||       |.   ||  
// |'....|'  '|..'|'  '|...' .||. ||. .||.  '|'  '|...' |'..|'  '|.' '|..'|'  '|.'  '|...'  '|..'||. 
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

void solve(string &s, int en) {
    for(int i=0; i<=en; ++i) {
        if(s[i] == '1') s[i] = '0';
        else s[i] = '1';
    }
}

void SachRestated() {
    int n; cin >> n;
    v1d ans;
    string a; cin >> a;
    string b; cin >> b;
    for(int i=n -1; i>=0; --i) {
        if(i == 0) {
            if(a[i] == b[i]) continue;
            else ans.pb(1);
        }
        else {
            if(a[i] == b[i]) continue;
            else {
                if(a[i] == a[0]) {
                    ans.pb(i + 1);
                    reverse(a.begin(), a.begin() + i + 1);
                    solve(a, i);
                }
                else {
                    ans.pb(1);
                    ans.pb(i + 1);
                    a[0] = a[i];
                    reverse(a.begin(), a.begin() + i + 1);

                    solve(a, i);
                    // if(i == 4)
                    // cout << a << endl;
                }
            } 
        }
    }
    cout << sz(ans) << " " ;
    for(auto &k : ans) cout << k << " " ;
    cout << endl;

}

int32_t main() {
    fio
    int t = 1;
    cin >> t;
    while(t--) {
      SachRestated();  
    }

}   