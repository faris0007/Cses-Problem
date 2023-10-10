#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define all(v)				((v).begin()), ((v).end())
#define rall(v)				((v).rbegin()), ((v).rend())
#define oo 1e16+5
#define MOD ll(1e9+7)
#define min3(a,b,c) min(a,min(b,c))
#define max3(a,b,c) max(a,max(b,c))
# define M_PI  3.14159265358979323846
#define int long long
typedef int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pi;
typedef vector<pi> vip;
typedef vector<vip> viip;
typedef pair<ll,pi> pii;
typedef map<ll,ll> mapi;;
typedef tree< pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
const int N=2e5+10;
const int M = 25;
viip adj;
vi path;
vi vis(N);
void euler(ll node) {
    while (!adj[node].empty()) {
        ll nod = adj[node].back().first;
        ll ind = adj[node].back().second;
        adj[node].pop_back();
        if (vis[ind])continue;
        vis[ind] = true;
        euler(nod);
    }
    path.push_back(node);
}
void solve() {
    ll n, m;
    cin >> n >> m;
    adj.resize(n + 1);
    ll st = 1, freq = 0;
    vi in(N), out(N);
    for (int i = 1; i <= m; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back({y, i});
        in[y]++;
        out[x]++;
    }
    ll dif1 = 0;
    ll dif2 = 0;
    bool tru = true;
    for (int i = 1; i <= n; ++i) {
        if (in[i] + 1 == out[i]) {
            dif1++;
            st = i;
        } else if (out[i] + 1 == in[i]) {
            dif2++;
        } else {
            tru = false;
        }
    }
    if (dif1 != 1 || dif2 != 1) {
        cout << "IMPOSSIBLE";
        return;
    }
    euler(st);
    if (path.size() != m + 1 || path[0]!=n) {
        cout << "IMPOSSIBLE";
        return;
    }
    reverse(all(path));
    for (auto it: path)cout << it << " ";
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t = 1;
    //  cin >> t;
    while (t--) {
        solve();
    }
}