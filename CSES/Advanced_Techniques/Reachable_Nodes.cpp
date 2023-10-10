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
const int N=6e4+10;
vi res;
vi vis;
void dfs(ll node,ll par, vii &adj) {
    for (auto ch: adj[node]) {
        if (ch != par && !vis[ch]) {
            vis[ch] = 1;
            dfs(ch, node, adj);
        }
    }
    res.push_back(node);
}


void solve() {
    ll n, m;
    cin >> n >> m;
    vii adj(n + 1);
    vis.resize(n + 1);
    vector<bitset<N>> dp(N + 1);
    for (int i = 1; i <= m; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
    }
    for (int i = 1; i <=n ; ++i) {
        if(!vis[i]) {
            vis[i]=1;
            dfs(i, 0, adj);
        }
    }
    for (auto s: res) {
        dp[s][s] = 1;
        for (auto it: adj[s]) {
            dp[s] |= dp[it];
        }
    }
    for (int i = 1; i <= n; ++i) {
        cout << (dp[i].count()) << " ";
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