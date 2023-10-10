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
vi lvl(N,0),sub(N,1),res(N);

set<ll> dat[N];
void small_to_large(ll node,ll par) {
    dat[node].insert(edge_cost[node]);
    for (auto ch: adj[node]) {
        if (ch == par)continue;
        small_to_large(ch, node);
        if (dat[ch].size() > dat[node].size()) {
            swap(dat[node], dat[ch]);
        }
            for (auto it: dat[ch])dat[node].insert(it);
    }
    res[node] = dat[node].size();
}

void solve() {
    ll n;
    cin >> n;
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
    small_to_large(1,-1);
    for (int i = 1; i <= n; ++i) {
        cout << res[i] << " ";
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