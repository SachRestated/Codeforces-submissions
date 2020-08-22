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

int sub(int a,int b,int p=MOD){return ((a%p)-(b%p)+p)%p;}
int mult(int a,int b, int p=MOD) {return ((a%p)*(b%p))%p;}
int add(int a, int b, int p=MOD) {return (a%p + b%p)%p;}
int fpow(int n, int k, int p = MOD) {int r = 1; while(k > 0) {if (k & 1) r = r * n%p; n = n * n%p; k = k >> 1;} return r;}
inline int powr(int a, int b) {
    int x = 1;
    while (b) {
        if (b & 1) x *= a;
        a *= a;
        b >>= 1;
    }
    return x;
}
int inv(int a, int p = MOD) {return fpow(a, p - 2, p);}
int fdiv(int a,int b,int p=MOD){
    int yinv=inv(b);
    int ans=(a*yinv)%p;
    return ans;
}
 
int _pow(int p, int q){
    int res = 1;
    while(q){
        if(q&1) res = (res*p)%MOD;
        p = (p*p)%MOD;
        q = q>>1;
    }
    return (res+MOD)%MOD;
}

int dfs(int i, v2d &graph, v1d &s, int p = -1) {
    int ans =1;
    for(auto &k : graph[i]) {
        if(k == p) continue;
        ans += dfs(k, graph, s, i);
    }
    s[i] = ans;
}

void SachRestated() {
    int n; cin >> n;
    v2d graph(n);
    v1p edges;
    for(int i=0; i<n-1; ++i) {
        int u, v; cin >> u >> v;
        --u, --v;
        graph[u].pb(v);
        graph[v].pb(u);
        edges.pb({min(u, v), max(u, v)});
    }
    int ans = 0;
    int m; cin >> m;
    v1d s(n);
    v1d primes(m);
    v1d ds;
    for(auto &prime : primes) cin >> prime;
    RS(primes);
    dfs(0, graph, s);
    int x = 0;

    for(auto &edge : edges) {
        int num = min(s[edge.ff],s[edge.ss]);
        num = num * (n - num);
        ds.pb(num);
    }
    RS(ds);
    if(sz(primes) <= sz(ds)) {
        for(int i=0; i<sz(ds); ++i) {
            if(x < sz(primes)) {
                ans = add(ans, mult(ds[i], primes[x]));
                ++x;
            }
            else ans = add(ans, ds[i]);
        }
    }
    else {
        for(int i=0; i<sz(ds); ++i) {
            if(i == 0) {
                int k = primes[0];
                for(int i=sz(ds); i<sz(primes); ++i) {
                    k = mult(k, primes[i]);
                }
                ans = add(ans, mult(k, ds[i]));
            }
            else {
                ans = add(ans, mult(ds[i], primes[i]));
            }
        }
    }
    cout << ans << endl;


}

int32_t main() {
    fio
    int t = 1;
    cin >> t;
    while(t--) {
      SachRestated();  
    }

}