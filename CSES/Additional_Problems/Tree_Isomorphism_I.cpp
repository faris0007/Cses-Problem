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
vii  adj,adj2;
//vi sz(N),vis(N);
//vi sz2(N),vis2(N);
//int get_sz(ll node ,ll par,vii &adj,vi &vis,vi &sz) {
//    sz[node] = 1;
//    for (auto ch: adj[node]) {
//        if (vis[ch] || ch == par)continue;
//        sz[node] += get_sz(ch, node,adj,vis,sz);
//    }
//    return sz[node];
//}
//int get_centroid(ll node ,ll par,ll nwsz,vii &adj,vi &vis,vi &sz) {
//    for (auto ch: adj[node]) {
//        if (vis[ch] || ch == par)continue;
//        if (sz[ch] > nwsz / 2) {
//            return get_centroid(ch, node, nwsz,adj,vis,sz);
//        }
//    }
//    return node;
//}


map<vector<int>, int> mp;
int idx = 0;
int dfs(int s, int p, vii &adj) {
    vector<int> v;
    for (auto i: adj[s]) {
        if (i != p)
            v.push_back(dfs(i, s, adj));
    }
    sort(v.begin(), v.end());
    if (!mp.count(v)) mp[v] = idx++;
    return mp[v];
}


void solve() {
    ll n;
    cin >> n;
    adj.clear(), adj2.clear();
    adj.resize(n + 1), adj2.resize(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        adj2[x].push_back(y);
        adj2[y].push_back(x);
    }
//    ll sizo = get_sz(1, -1, adj, vis, sz);
//    ll c1 = get_centroid(1, -1, sizo, adj, vis, sz);
//    ll sizo2 = get_sz(1, -1, adj2, vis2, sz2);
//    ll c2 = get_centroid(1, -1, sizo2, adj2, vis2, sz2);

    ll z1 = dfs(1, -1, adj);
    ll z2 = dfs(1, -1, adj2);
    if (z1 == z2) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
     cin >> t;
    while (t--) {
        solve();
    }
}