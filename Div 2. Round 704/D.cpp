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
    int a, b, k; cin >> a >> b >> k;
    if(k == 0) {
        string ans;
        for(int i = 0; i < b; ++i) ans.pb('1');
        for(int i = 0; i < a; ++i) ans.pb('0');
        cout << "Yes" << endl;
        cout << ans << endl << ans << endl; 
        return;
        
    }

    if(b == 1 || a == 0 || a + b <= k + 1) {
        cout << "No" << endl;
        return;
    }
    


    vector<char> x(a + b, '0'), y(a + b, '0');
    x[k] = '1';
    y[0] = '1';
    int left = b - 2;
    for (int i = 1; i < k and left; ++i)
    {
        x[i] = '1';
        y[i] = '1';
        --left;
    }
    for (int i = k + 1; left and i < a + b - 1; ++i)
    {
        x[i] = '1';
        y[i] = '1';
        --left;
    }
    
    x[a + b - 1] = '1';
    y[a + b - 1] = '1';
    reverse(all(x));
    reverse(all(y));
    cout << "Yes" << endl;
    for (auto &k : x)
        cout << k;
    cout << endl;
    for (auto &k : y)
        cout << k;
    cout << endl;
}

int32_t main() {
    fio

    clock_t z = clock();
    //OJ;
    int t = 1;
    //cin >> t;
    while(t--) {
        SachRestated();  
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << '\n';
}