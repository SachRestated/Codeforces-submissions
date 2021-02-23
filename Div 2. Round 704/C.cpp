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
    int n, m;
    cin >> n >> m;
    v2d cnt(26);

    string s, t;
    cin >> s >> t;

    for (int i = 0; i < n; ++i)
    {
        cnt[s[i] - 'a'].push_back(i + 1);
    }
    int ans = 0;
    v1d a(m);
    v1d b(m);

    int prev = 0;
    for (int i = 0; i < m; ++i)
    {
        int x = t[i] - 'a';
        int pos = upper_bound(all(cnt[x]), prev) - cnt[x].begin();
        a[i] = cnt[x][pos];
        prev = a[i];
    }
    prev = n + 1;
    for (int i = m - 1; i >= 0; --i)
    {
        int x = t[i] - 'a';
        int pos = lower_bound(all(cnt[x]), prev) - cnt[x].begin();
        --pos;
        b[i] = cnt[x][pos];
        prev = b[i];
    }
    for (int i = 0; i < m - 1; ++i)
    {
        ans = max(ans, b[i + 1] - a[i]);
    }
    cout << ans << endl;
}

int32_t main()
{
    fio

        clock_t z = clock();
    //OJ;
    int t = 1;
    //cin >> t;
    while (t--)
    {
        SachRestated();
    }
    cerr << "Run Time : " << ((double)(clock() - z) / CLOCKS_PER_SEC) << '\n';
}