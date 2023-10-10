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
typedef vector<pi> vip;
typedef map<ll,ll> mapi;
typedef vector<vip> viip;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
const int N=2e5+10;
///// Agamista
ll tim=0;
vi dfsn(N);
void dfs(ll node,vi &vis,vii &adj) {
    if (vis[node])return;
    vis[node] = 1;
    dfsn[node] = tim++;
    for (auto it: adj[node]) {
        dfs(it, vis, adj);
    }
}

void solve() {
    ll n, m;
    cin >> n >> m;
    vii adj(n + 1);
    vi vis(n + 1, 0);
    vi lvl(n + 1);
    vip edges;
    for (int i = 0; i < m; ++i) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        edges.push_back({u, v});
    }
    for (int i = 1; i <= n; ++i) {
        dfs(i, vis, adj);
    }
    for (auto it: edges) {
        if (dfsn[it.first] > dfsn[it.second])swap(it.first, it.second);
        cout << it.first << " " << it.second << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
 //   cin >> tc;
    while (tc--) {
        solve();
    }
}