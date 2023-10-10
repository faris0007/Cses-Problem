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
vii  adj;
vi edge_cost;
vi res(N);
vi sz(N),vis(N),daddy(N),dis,freq(N,0);
ll ans=0,k;
int get_sz(ll node ,ll par) {
    sz[node] = 1;
    for (auto ch: adj[node]) {
        if (vis[ch] || ch == par)continue;
        sz[node] += get_sz(ch, node);
    }
    return sz[node];
}
int get_centroid(ll node ,ll par,ll nwsz) {
    for (auto ch: adj[node]) {
        if (vis[ch] || ch == par)continue;
        if (sz[ch] > nwsz / 2) {
            return get_centroid(ch, node, nwsz);
        }
    }
    return node;
}
int Decomposition(ll node ,ll par) {
    ll sizo = get_sz(node, par);
    ll centroid = get_centroid(node, par, sizo);
    if (par == -1)par = centroid;
    daddy[centroid] = par;
    vis[centroid] = true;
    for (auto ch: adj[centroid]) {
        if (vis[ch])continue;
        Decomposition(ch, centroid);
    }
    return centroid;
}


void solve() {
    ll n;
    cin >> n;
    adj.clear(), edge_cost.clear();
    adj.resize(n + 1), edge_cost.resize(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        ll x, y, c;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    ll sizo = get_sz(1, -1);
    ll c1 = get_centroid(1, -1, sizo);
    cout<<c1<<endl;
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