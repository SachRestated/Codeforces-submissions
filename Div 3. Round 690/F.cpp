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

const int MAXN = 1e9 + 1;
map<int, int> bit;

int sum(int x)
{
    int ans = 0;
    while (x > 0)
    {
        if (bit.count(x))
            ans += bit[x];
        x -= x & -x;
    }
    return ans;
}

void update(int x, int delta = 1)
{
    for (; x <= MAXN; x += x & -x)
        bit[x] += delta;
}

void SachRestated()
{
    bit.clear();
    int n;
    cin >> n;
    v1p v(n);
    for (auto &k : v)
        cin >> k.ff >> k.ss;

    if (n == 1)
    {
        cout << 0 << endl;
        return;
    }
    sort(all(v));

    v1d x;
    v1d cnt(n);
    update(v[0].second);
    for (int i = 1; i < n; ++i)
    {
        int start = v[i].first;
        int id = sum(start - 1);
        int k = i - id;
        // cout << i << " " << k << endl;
        cnt[i] += k;
        update(v[i].second);
    }

    bit.clear();
    update(v[n - 1].first);
    for (int i = n - 2; i >= 0; --i)
    {
        int end = v[i].second;
        cnt[i] += sum(end);
        update(v[i].first);
    }
    int mx = -1;
    for (int i = 0; i < n; ++i)
    {
        mx = max(mx, 1 + cnt[i]);
    }
    cout << n - mx << endl;
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