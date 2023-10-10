#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define MOD ll(1e9+7)
#define endl '\n'
#define int long long
typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
const int N = 5 * 1e5;
ll n, m;
ll add(ll a, ll b) {
    return ((a % MOD + b % MOD) + MOD) % MOD;
}
void dfs( int node,ll par,vii &adj,vi &vis,vi &dp) {
    if (node == n) { dp[node] = 1; }
    if (vis[node] || node == n)return;
    vis[node] = 1;
    for (auto ch: adj[node]) {
        if (par == ch)continue;
        dfs(ch, node, adj, vis, dp);
        if (dp[ch])
            dp[node] = add(dp[ch], dp[node]);
    }
}
void solve() {
    cin >> n >> m;
    vii adj(n + 1);
    vi vis(n + 1, 0);
    vi dp(n + 1, 0);
    for (int i = 0; i < m; ++i) {
        ll u, v, w;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    dfs(1, -1, adj, vis, dp);
    cout << dp[1] << endl;
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    //cin >> t;
    while (t--) {
        solve();
    }
}