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
    map<int, int> m;
    v1d a(n);
    v1d res;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        m[k]++;
        a[i] = k;
        // cout << k << ' ';
    }

    if (n == 1)
    {
        cout << 1 << endl;
        cout << 1 << endl;
        return;
    }
    // cout << endl;
    v1p v;
    for (auto &k : m)
        v.push_back(k);
    int ans = 0;
    int sum = 0;
    int mx = v.back().first;
    int mn = mx;

    for (int i = 0; i < sz(v); ++i)
    {
        if (i == sz(v) - 1)
        {
            ans += v[i].second;
            break;
        }
        sum += (v[i].ff * v[i].ss);
        // cout << sum << endl;
        if (sum >= v[i + 1].ff)
        {
            ans += v[i].second;
            mn = min(mn, v[i].first);
        }
        else
        {
            ans = 0;
            mn = mx;
        }
    }

    cout << ans << endl;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] >= mn)
        {
            res.push_back(i + 1);
        }
    }
    // cout << sz(res) << endl;
    for (auto &k : res)
        cout << k << ' ';
    cout << endl;
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