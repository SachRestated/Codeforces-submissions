#include <bits/stdc++.h>
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
#define pqx priority_queue<int>
#define pqn priority_queue<int, v1d, greater<int>>
#define fio                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define OJ                            \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void SachRestated()
{

    int n;
    cin >> n;
    v1d a(n);
    for (auto &k : a)
        cin >> k;

    int m;
    cin >> m;
    v1d b(m);
    for (auto &k : b)
        cin >> k;
    int ans = INT_MIN;
    int cur = 0;

    v1d c(n);
    v1d d(m);
    int mx1 = INT_MIN;
    int mx2 = INT_MIN;
    for (int i = 0; i < n; ++i)
    {
        if (!i)
            c[i] = a[i];
        else
            c[i] = c[i - 1] + a[i];
        mx1 = max(mx1, c[i]);
    }
    for (int i = 0; i < m; ++i)
    {
        if (!i)
            d[i] = b[i];
        else
            d[i] = d[i - 1] + b[i];
        mx2 = max(mx2, d[i]);
    }
    ans = max(0ll, mx1) + max(0ll, mx2);
    cout << max(0ll, ans) << endl;
}

int32_t main()
{
    fio

        clock_t z = clock();
    //OJ;
    int t = 1;
    cin >> t;
    while (t--)
    {
        SachRestated();
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << '\n';
}