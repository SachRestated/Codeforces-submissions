#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define int long long
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
        if(n & 1) {
            if(n == 1) cout << "FastestFinger" << endl;
            else cout << "Ashishgup" << endl;
            continue;
        }
        if(n == 2) {
            cout << "Ashishgup" << endl;
            continue;
        }
        int cnt1 = 0, cnt2 = 0;
        for(int i=2; i*i<=n; ++i) {
            int x = 0;
            while(n % i == 0) {
                n /= i;
                ++x;
            }
            if(x != 0) {
                if(i == 2) cnt1 += x;
                else cnt2 += x;
            }

        }
        if(n > 1) {
            ++cnt2;
        }
        if(cnt1 > 1) {
            if(cnt2 > 0) {
                cout << "Ashishgup" << endl;
                
            }
            else cout << "FastestFinger" << endl;
        }
        else {
            if(cnt2 == 1) cout << "FastestFinger" << endl;
            else cout << "Ashishgup" << endl;
        }

    }
}