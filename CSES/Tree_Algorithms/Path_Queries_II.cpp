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
//#define int long long
typedef int ll;
typedef vector<ll> vi;
typedef vector<vi> vii;
typedef pair<ll,ll> pi;
typedef vector<pi> vip;
typedef map<ll,ll> mapi;
typedef vector<vip> viip;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
ll gcd(ll a, ll b) { return ((b == 0) ? a : gcd(b, a % b)); }
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("fast-math")
///// Agamista
const int N = 6e5;
const int M = 30;
vector<int> parent, depth, heavy, head, pos;
int cur_pos;
ll seg[N],n;
ll arr[N];
void Build_seg(ll node,ll l , ll r) {
    if (l == r) {
        seg[node] = arr[l];
        return;
    }
    ll mid = (l + r) / 2;
    Build_seg(node * 2, l, mid);
    Build_seg(node * 2 + 1, mid + 1, r);
    seg[node] = max(seg[node * 2] , seg[node * 2 + 1]);
}
void update(ll node,ll l ,ll r,ll idx,ll val) {
    if (l == r) {
        seg[node] = val;
        return;
    }
    ll mid = (l + r) / 2;
    if (idx <= mid) update(node * 2, l, mid, idx, val);
    else update(node * 2 + 1, mid + 1, r, idx, val);
    seg[node] = max(seg[node * 2] , seg[node * 2 + 1]);
}
ll query(ll node,ll l ,ll r,ll st, ll en) {
    ll mid = (l + r) / 2;
    if (st > r || en < l)return -1e9;
    if (l >= st && r <= en){
        return seg[node];
    }
    return max(query(node * 2, l, mid, st, en), query(node * 2 + 1, mid + 1, r, st, en));
}
/////////////////////////////////////////////////////
ll dfs(ll x,ll p,vector<vector<int>> & adj ) {
    parent[x] = p;ll sz = 1, mx = 0;
    for (auto c: adj[x]) {
        if (p == c)continue;
        depth[c] = depth[x] + 1;
        ll csz = dfs(c, x, adj);
        sz += csz;
        if (csz > mx) {
            mx = csz;
            heavy[x] = c;
        }
    }
    return sz;
}
void decompose(ll x,ll h,vector<vector<int>> & adj) {
    head[x] = h, pos[x] = cur_pos++;
    if (heavy[x] != -1)decompose(heavy[x], h, adj);
    for (auto c: adj[x]) {
        if (parent[x] == c || c == heavy[x])continue;
        decompose(c, c, adj);
    }
}
void init(vector<vector<int>> & adj) {
    n = adj.size();
    parent = vector<int>(n);
    depth = vector<int>(n);
    heavy = vector<int>(n, -1);
    head = vector<int>(n);
    pos = vector<int>(n);
    cur_pos = 1 ;
    dfs(1, 0, adj);
    decompose(1, 1, adj);
}
int query(int a, int b) {
    int res = 0;
    for (; head[a] != head[b]; b = parent[head[b]]) {
        if (depth[head[a]] > depth[head[b]])
            swap(a, b);
        int cur_heavy_path_max = query(1, 0, n + 1, pos[head[b]], pos[b]);
        res = max(res, cur_heavy_path_max);
    }
    if (depth[a] > depth[b])
        swap(a, b);
    int last_heavy_path_max = query(1, 0, n + 1, pos[a], pos[b]);
    res = max(res, last_heavy_path_max);
    return res;
}
void solve() {
    ll q;
    cin >> n >> q;
    vii adj(n+1);
    vi vals(n+1);
    for (int i = 1; i <= n; ++i) {
        cin >> vals[i];
    }
    for (int i = 0; i < n - 1; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    init(adj);
    for (int i = 1; i <=n ; ++i) {
        arr[pos[i]]=vals[i];
    }
    Build_seg(1,0,n+1);
    for (int i = 0; i < q; ++i) {
        ll op;
        cin >> op;
        if (op == 1) {
            ll no, val;
            cin >> no >> val;
            update(1, 0, n + 1, pos[no], val);
        } else {
            ll u, v;
            cin >> u >> v;
            cout << query(u, v) << " ";
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
}