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
const int M = 30;
ll ansector[N][M];
ll lvl[N];
ll res[N];
vii adj;
void dfs(ll node, ll par) {
    ansector[node][0] = par;
    lvl[node] = lvl[par] + 1;
    for (int i = 1; i < M; ++i) {
        ansector[node][i] = ansector[ansector[node][i - 1]][i - 1];
    }
    for (auto ch: adj[node]) {
        if (ch == par)continue;
        dfs(ch, node);
    }
}
ll findKthAncestor(ll u, ll k) {
    for (int i = M - 1; i >= 0; --i) {
        if ((1 << i) & k)
            u = ansector[u][i];
    }
    return u;
}
ll LCA(ll u, ll v) {
    if (lvl[u] < lvl[v])
        swap(u, v);
    u = findKthAncestor(u, lvl[u] - lvl[v]);
    if (u == v)return v;

    for (int i = M - 1; i >= 0; --i) {
        if (ansector[u][i] == ansector[v][i])continue;
        u = ansector[u][i];
        v = ansector[v][i];
    }
    return ansector[u][0];
}
void update(ll u,ll v,vi &partial) {
    ll lc = LCA(u, v);
    partial[lc]--;
    partial[u]++;
    partial[v]++;
    partial[findKthAncestor(lc, 1)]--;
}
void dfs2(ll node, ll par,vi &partial) {
    ll al = partial[node];
    for (auto ch: adj[node]) {
        if (ch == par)continue;
        dfs2(ch, node,partial);
        al += partial[ch];
    }
    partial[node] = al;
}

void solve() {
    ll n, q;
    cin >> n >> q;
    adj.resize(n + 1);
    vi partial(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        ll x, y;
        cin >> x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1, 0);
    for (int i = 0; i < q; ++i) {
        ll x, y;
        cin >> x >> y;
        update(x, y, partial);
    }
    dfs2(1, 0, partial);
    for (int i = 1; i <=n; ++i) {
        cout << partial[i] << " ";
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