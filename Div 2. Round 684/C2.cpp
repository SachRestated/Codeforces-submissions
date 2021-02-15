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


v2d solve(int x, int y, v2d &cnt ) {
    v1p a, b;
    int c = 0;
    v2d ans;
    for(int i = 0; i < 2; ++i) {
        for(int j = 0; j < 2; ++j) {
            if(x + i >= sz(cnt) || y + j >= sz(cnt[0])) {
                // cout << "Hello" << endl;
                continue;
            
            }
            if(cnt[x + i][y + j]) {

                a.pb({x + i, y + j});
                ++c;
                cnt[x + i][j + y] = 0;
            } else {
                b.pb({x + i, y + j});
            }
        }
    }

    if(c == 0) {
        return ans;
    } 
    else if(c == 1) {
        ans.pb({a[0].ff, a[0].ss, b[1].ff, b[1].ss, b[2].ff, b[2].ss});
        ans.pb({a[0].ff, a[0].ss, b[0].ff, b[0].ss, b[1].ff, b[1].ss});
        ans.pb({a[0].ff, a[0].ss, b[0].ff, b[0].ss, b[2].ff, b[2].ss});
    } else if(c == 2) {
        ans.pb({a[0].ff, a[0].ss, b[0].ff, b[0].ss, b[1].ff, b[1].ss});
        ans.pb({a[1].ff, a[1].ss, b[0].ff, b[0].ss, b[1].ff, b[1].ss});
    } else if(c == 3) {
        ans.pb({a[0].ff, a[0].ss, a[1].ff, a[1].ss, a[2].ff, a[2].ss});
    }
    else {
        ans.pb({a[0].ff, a[0].ss, a[1].ff, a[1].ss, a[2].ff, a[2].ss});
        a.clear();
        b.clear();
        a.pb({x + 1, y + 1});
        b.pb({x, y});
        b.pb({x + 1, y});
        b.pb({x, y + 1});
        ans.pb({a[0].ff, a[0].ss, b[1].ff, b[1].ss, b[2].ff, b[2].ss});
        ans.pb({a[0].ff, a[0].ss, b[0].ff, b[0].ss, b[1].ff, b[1].ss});
        ans.pb({a[0].ff, a[0].ss, b[0].ff, b[0].ss, b[2].ff, b[2].ss});
    }
    return ans;
}


void SachRestated() {
    int n, m; cin >> n >> m;
    v2d cnt(n, v1d(m));
    v2d v;
    bool isit = false;
    for(int i = 0; i < n; ++i) {
        string x; cin >> x;
        for(int j = 0; j < m; ++j) {
            cnt[i][j] = x[j] - '0';
            if(cnt[i][j]) {
                isit = true;
            }
        }
    }

    if(!isit) {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i <= n - 3; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (cnt[i][j])
            {
                if (j != m - 1)
                {
                    v.pb({i, j, i + 1, j, i + 1, j + 1});
                    cnt[i][j] ^= 1, cnt[i + 1][j] ^= 1, cnt[i + 1][j + 1] ^= 1;
                }
                else
                {
                    v.pb({i, j, i + 1, j, i + 1, j - 1});
                    cnt[i][j] ^= 1, cnt[i + 1][j] ^= 1, cnt[i + 1][j - 1] ^= 1;
                }
            }
        }
    }

    int i = n - 2;
    int j = 0;
    
    if(m & 1) {
        if(cnt[n-2][0]) {
            i = n - 2;
            j = 0;
            v.pb({i, j, i + 1, j, i + 1, j + 1});
            cnt[i][j] ^= 1, cnt[i + 1][j] ^= 1, cnt[i + 1][j + 1] ^= 1;
        } 
        if(cnt[n - 1][0]) {
            i = n - 1 ;
            j = 0;
            v.pb({i, j, i, j + 1, i - 1, j + 1});
            cnt[i][j] ^= 1, cnt[i][j + 1] ^= 1, cnt[i - 1][j + 1] ^= 1;
        }
        j = 1;
        i = n - 2;
    }
    for (; j < m; j += 2)
    {
        v2d res;
        res = solve(i, j, cnt);
        for (auto &k : res)
            v.pb(k);
    }

    cout << sz(v) << endl;

    for(auto &k: v) {
        for(auto &j: k) cout << j + 1 << " " ;
        cout << endl;
    }
    
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