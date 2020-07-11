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

int solve(int a, int b) {
    return (a * b) / __gcd(a, b);
}

int32_t main() {
    fio
    int t; cin >> t;
    while(t--) {
        int n; cin >> n; 
        if(n % 2 == 0) {
            cout << n / 2 << " " << n / 2 << endl;
        }
        else {
            int ans1 = -1;
            int ans2 = -1;
            int lcm = 1e18 + 2;
            for(int i=3; i*i<= n; i += 2) {
                if(n % i == 0) {
                    int a = i;
                    int b = n / i;
                    int p = solve(a, n - a);
                    int q = solve(b, n - b);
                    if(p < lcm) {
                        lcm = p;
                        ans1 = a, ans2 = n - a;
                    }
                    if(q < lcm) {
                        lcm = q;
                        ans1 = b, ans2 = n - b;
                    }
                }
            }
            if(ans1 == -1) {
                cout << 1 << " " << n - 1 << endl;
            }
            else {
                cout << ans1 << " " << ans2 << endl;
            }
        }
    }
}