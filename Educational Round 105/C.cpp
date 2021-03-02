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


int solve(v1d &a, v1d &b) {
    int n = a.size();
    int m = b.size();
    set<int> pos(b.begin(), b.end());

    vector<int> suf(n + 1);
    suf[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        suf[i] = suf[i + 1];
        if (pos.count(a[i]))
            suf[i]++;
    }

    int ans = suf[0];

    for(int i = 1; i <= n; ++i) {
        auto it = lower_bound(b.begin(), b.end(), a[i - 1]);
        if (it == b.end())
            continue;

        int idx = it - b.begin();
        int lim = 1e9 + 5;
        if(i < n) lim = a[i] - 1;
        while(idx < m && b[idx] <= lim) {
            int idx1 = lower_bound(all(b), b[idx] - (i - 1)) - b.begin();
            ans = max(ans, suf[i] + (idx - idx1 + 1));

        }
        
    }
    return ans;
}


void SachRestated() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    vector<int> b(m);
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int answer = 0;

    vector<int> a1, b1;
    for (auto it : a)
        if (it > 0)
            a1.push_back(it);
    for (auto it : b)
        if (it > 0)
            b1.push_back(it);

    answer += solve(a1, b1);

    a1.clear();
    b1.clear();

    for (auto it : a)
        if (it < 0)
            a1.push_back(-it);
    for (auto it : b)
        if (it < 0)
            b1.push_back(-it);

    reverse(a1.begin(), a1.end());
    reverse(b1.begin(), b1.end());
    answer += solve(a1, b1);
    cout << answer << endl;
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