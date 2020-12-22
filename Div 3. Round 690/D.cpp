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

bool check(int k, map<int, int> &mp, int sum)
{
    int x = k;
    while (x < sum)
    {
        if (mp.count(x))
        {
            x += k;
            continue;
        }
        return false;
    }
    return true;
}

void SachRestated()
{
    int n;
    cin >> n;
    int sum = 0;
    v1d a(n);
    map<int, int> mp;
    for (auto &k : a)
    {
        cin >> k;
        sum += k;
        mp[sum]++;
    }
    int mn = n - 1;
    bool done = false;
    vector<int> nums;
    for (int i = 1; i * i <= sum && !done; ++i)
    {
        if (sum % i == 0)
        {
            int k = sum / i;
            if (i != k && i <= n)
                nums.pb(k);
            if (k > n)
                continue;
            done |= check(i, mp, sum);
            if (done)
            {
                cout << n - k << endl;
                return;
            }
        }
    }

    if (!done)
    {

        for (int i = (int)nums.size() - 1; i >= 0 && !done; --i)
        {
            done |= check(nums[i], mp, sum);
            if (done)
            {
                mn = n - sum / nums[i];
            }
        }
    }
    cout << mn << endl;
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