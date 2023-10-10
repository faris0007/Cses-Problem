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
const int N=2e5+10;
const int M = 30;
ll seg[N<<2];

void update(ll node,ll l ,ll r,ll idx,ll val) {
    if (l == r) {
        seg[node] = val;
        return;
    }
    ll mid = (l + r) / 2;
    if (idx <= mid) update(node * 2, l, mid, idx, val);
    else update(node * 2 + 1, mid + 1, r, idx, val);
    seg[node] = (seg[node * 2] + seg[node * 2 + 1]);
}
ll query(ll node,ll l ,ll r,ll st, ll en) {
    ll mid = (l + r) / 2;
    if (st > r || en < l)return 0;
    if (l >= st && r <= en)return seg[node];
    return (query(node * 2, l, mid, st, en)+ query(node * 2 + 1, mid + 1, r, st, en));
}



////////////////////////////////////////////////////////////////// segment above


int isValueOnEdge = 1;  // switch to 0 for value on node
vii  adj;
vii treeEdgeIdx;
vi edge_to;
vi edge_cost;
vi parent(N),lvl(N,0),sub(N,1), heavy(N,-1), root(N), segTreePos(N);

void dfs(ll node,ll par) {
    ll maxo = 0, cnt = 0;
    parent[node] = par;
    for (auto ch: adj[node]) {
        if (ch == par)continue;
        ll edgeIdx = treeEdgeIdx[node][cnt++];
        lvl[ch] = lvl[node] + 1;
        dfs(ch, node);
        sub[node] += sub[ch];
        edge_to[edgeIdx] = ch;
        if (sub[ch] > maxo) {
            maxo = sub[ch];
            heavy[node] = ch;
        }
    }
}
void Build(ll node) {
    dfs(node, -1);
    for (int chainRoot = 0, pos = 0; chainRoot < adj.size(); ++chainRoot) {
        if (parent[chainRoot] == -1 || heavy[parent[chainRoot]] != chainRoot) {
            for (int j = chainRoot; j != -1; j = heavy[j])  // iterate on a chain
                root[j] = chainRoot, segTreePos[j] = pos++;
        }
    }
}

ll query_Chain(int l, int r) {
    if(l>r)swap(l,r);
    return query(1, 0, adj.size() - 2, l-1, r-1);
}

void updatePos(int treeNode, int value) {
    update(1, 0, adj.size() - 2, segTreePos[treeNode] - 1, value);
}

ll queryPath(int u, int v) {
    ll res = 0;  // be careful from u = v for isValueOnEdge
    for (; root[u] != root[v]; v = parent[root[v]]) {
        if (lvl[root[u]] > lvl[root[v]])
            swap(u, v);
        res = (res + query_Chain(segTreePos[root[v]], segTreePos[v]));
    }
    if (lvl[u] > lvl[v])
        swap(u, v);
    if (!isValueOnEdge || u != v)
        res = (res + query_Chain(segTreePos[u] + isValueOnEdge, segTreePos[v]));
    return res;
}


void solve() {
    ll n, q;
    cin >> n >> q;
    isValueOnEdge = 0;
    adj.clear(), edge_cost.clear(), treeEdgeIdx.clear(), edge_to.clear();
    adj.resize(n + 1), edge_cost.resize(n + 1), treeEdgeIdx.resize(n + 1), edge_to.resize(n + 1);

    for (int i = 1; i <= n; ++i) {
        cin >> edge_cost[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        ll x, y, c;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
        treeEdgeIdx[x].push_back(i), treeEdgeIdx[y].push_back(i);
    }
    Build(1);
    for (int i = 1; i <= n; ++i)
        updatePos(i, edge_cost[i]);


    for (int i = 0; i < q; ++i) {
        ll op;
        cin >> op;
        if (op == 1) {
            ll no, val;
            cin >> no >> val;
            updatePos(no, val);
        } else {
            ll u;
            cin >> u ;
            cout << queryPath(u, 1) << " ";
        }
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