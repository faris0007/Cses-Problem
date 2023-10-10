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


void pre(ll node,ll par,vi &depth,vii &adj) {
    ///// to get depth
    for (auto ch: adj[node]) {
        if (ch == par)continue;
        pre(ch, node, depth, adj);
        depth[node] = max(1 + depth[ch], depth[node]);
    }
}
void dfs(ll node,ll par,ll par_ans,vi &dp,vi &depth,vii &adj) {

    vi prfx, sufx;
    ll chs = 0;
    for (auto ch: adj[node]) {
        if (ch == par)continue;
        prfx.push_back(depth[ch]);
        sufx.push_back(depth[ch]);
        chs++;
    }
    for (int i = 1; i < prfx.size(); ++i) { prfx[i] = max(prfx[i], prfx[i - 1]); }
    for (int i = sufx.size() - 2; i >= 0; --i) { sufx[i] = max(sufx[i], sufx[i + 1]); }

    ll cnt = 0;
    ///// number of current ch to exclude it
    for (auto ch: adj[node]) {
        if (ch == par)continue;
        ll bef = (cnt == 0) ? -oo : prfx[cnt - 1];
        ll aft = (cnt == chs - 1) ? -oo : sufx[cnt + 1];
        ll now_ans = 1 + max3(par_ans, bef, aft);
        dfs(ch, node, now_ans, dp, depth, adj);
        cnt++;
    }
    dp[node] = 1 + max(par_ans, (!chs ? -1 : prfx.back()));
}


void solve() {
    ll n;
    cin >> n;
    vii adj(n + 1);
    vi dp(n + 1, 0);
    vi depth(n + 1, 0);
    for (int i = 1; i < n; ++i) {
        ll x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    pre(1, 0, depth, adj);
    dfs(1, 0, -1, dp, depth, adj);
    for (int i = 1; i <= n; ++i) {
        cout << dp[i] << " ";
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