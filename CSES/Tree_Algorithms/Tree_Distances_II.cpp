#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define oo 1e18+5
#define MOD ll(1e9+7)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
# define M_PI  3.14159265358979323846
#define int long long
typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef pair<ll,pi> pii;
typedef vector<pi> vip;
typedef map<ll,ll> mapi;;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N=3e5+10;

ll n;
void pre(ll node,ll par,vi &depth,vi &sub,vii &adj) {
    for (auto ch: adj[node]) {
        if (ch == par)continue;
        pre(ch, node, depth, sub, adj);
        sub[node] += sub[ch];
        depth[node] += sub[ch] + depth[ch];
    }
}
void dfs(ll node,ll par,ll par_ans,vi &dp,vi &depth,vi &sub,vii &adj) {
    ///// array dp to get ans
    //// array sub ro get num of Subordinates
    //// array depth to get sum of all me to my sub tree
    for (auto ch: adj[node]) {
        if (ch == par)continue;
        ll now_ans = par_ans + (n - sub[node]) + (depth[node] - depth[ch] - sub[ch]) + (sub[node] - sub[ch]);
        dfs(ch, node, now_ans, dp, depth, sub, adj);
    }
    dp[node] = par_ans + depth[node];
}


void solve() {
    cin >> n;
    vii adj(n + 1);
    vi dp(n + 1, 0);
    vi depth(n + 1, 0);
    vi sub(n + 1, 1);
    for (int i = 1; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    pre(1, 0, depth, sub, adj);
    dfs(1, 0, 0, dp, depth, sub, adj);
    for (int i = 1; i <= n; ++i) {
        cout << dp[i] << " ";
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}