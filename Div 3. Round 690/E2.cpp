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

v1d fact(2e5 + 2, 1);

void preprocess() {
    for(int i=1; i<(int)fact.size(); ++i) {
        fact[i] = i * fact[i - 1];
        fact[i] %= MOD;
    }
}

int solve(int n, int r) {
    int x = fact[n];
    int y = mult(fact[r], fact[n - r]);
    return fdiv(x, y);
}

void SachRestated() {
    int n, m, k; cin >> n >> m >> k;
    v1d a(n);
    for(auto &k: a) cin >> k;
    sort(all(a));
    int i = 0;
    int j = 0;
    int ans = 0;
    while(i < n) {
        while(j < n and a[j] - a[i] <= k) ++j;
        int d = j - i - 1;
        if(d >= m - 1) {
            ans = add(ans, solve(d, m-1));
        }
        ++i;
    }
    cout << ans << endl; 
    return;
}

int32_t main() {
    fio
    preprocess();
    clock_t z = clock();
    //OJ;
    int t = 1;
    cin >> t;
    while(t--) {
        SachRestated();  
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << '\n';
}