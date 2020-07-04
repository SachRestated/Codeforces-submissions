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

const int MAXN = 2000005;
vb usesroot(MAXN);
v1d ans(MAXN);

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


void preprocess() {
    ans[1] = 0;
    ans[2] = 0;
    ans[3] = 4;
    usesroot[2] = false;
    usesroot[1] = false;
    usesroot[3] = 1;
    for(int i=4; i<MAXN; ++i) {
        ans[i] = add(mult(2, ans[i - 2]), ans[i - 1]);
        if(!usesroot[i - 1] && !usesroot[i - 2]) usesroot[i] = 1;
        else usesroot[i] = false;
        if(usesroot[i]) {
            // if(i == 6) cout << ans[i] << " " ;
           ans[i] =  add(ans[i], 4);
        }
    }
} 

int32_t main() {
    fio
    preprocess(); //precompute answers, then just query the results
    int t; cin >> t;
    while(t--) {
        int x; cin >> x;
        cout << ans[x] << endl;
    }
}