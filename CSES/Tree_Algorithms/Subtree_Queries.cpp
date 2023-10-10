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
vii  adj;
vi edge_cost;
vi lvl(N,0),sub(N,1),eul,in(N);

void euler(ll node,ll par,ll &time) {
    in[node] = time++;
    eul.push_back(node);
    for (auto ch: adj[node]) {
        if (ch == par)continue;
        lvl[ch] = lvl[node] + 1;
        euler(ch, node, time);
        sub[node] += sub[ch];

    }
}
void Build(ll node) {
    ll time=0;
    euler(node, -1,time);
}

void solve() {
    ll n, q;
    cin >> n >> q;
    adj.clear(), edge_cost.clear();
    adj.resize(n + 1), edge_cost.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> edge_cost[i];
    }

    for (int i = 0; i < n - 1; ++i) {
        ll x, y, c;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    Build(1);
    for (int i = 0; i < n; ++i)
        update(1, 0, n - 1, i, edge_cost[eul[i]]);


    for (int i = 0; i < q; ++i) {
        ll op;
        cin >> op;
        if (op == 1) {
            ll no, val;
            cin >> no >> val;
            update(1, 0, n - 1, in[no], val);
        } else {
            ll u;
            cin >> u;
            cout << query(1, 0, n - 1, in[u], in[u] + sub[u]-1) << " ";
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