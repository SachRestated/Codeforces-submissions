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

void SachRestated() {
    int n, k; cin >> n >> k;
    int l1, r1; cin >> l1 >> r1; 
    int l2, r2; cin >> l2 >> r2;
    int lb = max(l1, l2);
    int rb = min(r1, r2);
    int p = max(0ll, rb - lb);
    if(p * n >= k) {
        cout << 0 << endl; 
        return;
    }
    
    k -= p * n;
    // cout << k << endl;
    int rr = max(r1, r2);
    int ll = min(l1, l2);
    int ex = rr - ll - p;
    int used = rr - rb + lb - ll;
    if(rb - lb >= 0) {

        if(n * ex >= k) {
            cout << k << endl; return;
        }
        int ans = n * ex;
        k -= n * ex;
        ans += k * 2;
        cout << ans << endl;
        return;
    }
    
    if(ex >= k) {
        cout << lb - rb + k << endl;
    }
    else {
        int mini = lb - rb;
        k -= ex;
        int ans1 = lb - rb + ex;
        if(ans1 >= ex * 2) {    
            
        }
        else {
            
            int x = n * ex;
            k += ex;
            if(x <= k) {
                ans1 = n * (lb - rb + ex);
                k -= x;
            }
            else {
                // cout << "hi" << endl;
                int req = k / ex;
                ans1 *= req;
                k %= ex;
                int add;
                add = min(k * 2, k + lb - rb);
                ans1 += add;
                k = 0;
                
            }
        }
        if(k) 
            ans1 += k * 2;
        cout << ans1 << endl;
        
    }
    
}

int32_t main() {
    fio
    int t = 1;
    cin >> t;
    while(t--) {
      SachRestated();  
    }

}