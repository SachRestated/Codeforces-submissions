//  .|'''.|                  '||      '||''|.                    .             .                '||  
//  ||..  '   ....     ....   || ..    ||   ||    ....   ....  .||.   ....   .||.    ....     .. ||  
//   ''|||.  '' .||  .|   ''  ||' ||   ||''|'   .|...|| ||. '   ||   '' .||   ||   .|...||  .'  '||  
// .     '|| .|' ||  ||       ||  ||   ||   |.  ||      . '|..  ||   .|' ||   ||   ||       |.   ||  
// |'....|'  '|..'|'  '|...' .||. ||. .||.  '|'  '|...' |'..|'  '|.' '|..'|'  '|.'  '|...'  '|..'||. 

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

void SachRestated() {
	int n; cin >> n;
	v1d a(n + 1);
	for(int i=1; i<n + 1;++i) cin >> a[i];
	int ans = 0;
	v1d b(n + 1);
	v2d graph(n + 1);
	v1d deg(n + 1);
	v1d cop(n + 1);
	for(int i=1; i<n + 1; ++i) {
		int x; cin >> x;
		if(x != -1) {
			graph[i].pb(x);
			deg[x]++;
		}
	}
	queue<int> q;
	for(int i=1; i<=n; ++i) {
		if(deg[i] == 0) {
			q.push(i);
		}
		cop[i] = deg[i];
	}
	v1d pos;
	v1d neg;
	while(!q.empty() ) {
		int i = q.front();
		q.pop();
		// cout << i << endl;
		int val = a[i];
		ans += val;
		for(auto &k : graph[i]) {
			if(--deg[k] == 0) {
				q.push(k);
			}
			a[k] = max(a[k], val + a[k]);
		}
		if(a[i] >= 0) pos.pb(i);
		else neg.pb(i);
	}
	cout << ans << endl;
	for(auto &k : pos) cout << k << " " ;
	for(auto &k : neg) cout << k << " " ;
	cout << endl;
}

int32_t main() {
    fio
    int t = 1;
    // cin >> t;
    while(t--) {
      SachRestated();  
    }

}